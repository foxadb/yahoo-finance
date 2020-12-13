#include "quote.hpp"
#include "time_utils.hpp"
#include "curl_utils.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>
#include <ctime>
#include <stdexcept>
#include <boost/algorithm/string.hpp>

Quote::Quote(std::string symbol) {
    this->symbol = symbol;
}

Quote::~Quote() {}

size_t Quote::nbSpots() {
    return this->spots.size();
}

Spot Quote::getSpot(size_t i) const {
    if (i < this->spots.size()) {
        return this->spots[i];
    }
    std::stringstream ss;
    ss << this->spots.size();

    std::string error = "ERROR: getSpot(index) - Index must be smaller than "
      + ss.str();
    throw std::invalid_argument(error);
}

Spot Quote::getSpot(std::time_t date) const {
    for (std::vector<Spot>::const_iterator it = this->spots.cbegin();
         it != this->spots.cend();
         ++it) {
        if (it->getDate() == date) {
            return *it;
        }
    }
    std::string error = "ERROR getSpot(date) - There is not spot at " + date;
    throw std::invalid_argument(error);
}

Spot Quote::getSpot(std::string date) const {
    for (std::vector<Spot>::const_iterator it = this->spots.cbegin();
         it != this->spots.cend();
         ++it) {
        if (it->getDateToString() == date) {
            return *it;
        }
    }
    std::string error = "ERROR getSpot(date) - There is not spot at " + date;
    throw std::invalid_argument(error);
}

void Quote::printSpots() const {
    for (std::vector<Spot>::const_iterator it = this->spots.cbegin();
         it != this->spots.cend();
         ++it) {
        std::cout << it->toString() << std::endl;
    }
}

void Quote::clearSpots() {
    this->spots.clear();
}

std::string Quote::getHistoricalCsv(std::time_t period1,
                                    std::time_t period2,
                                    const char *interval) {
    std::string url = "https://finance.yahoo.com/quote/"
            + this->symbol
            + "/?p="
            + this->symbol;

    std::string crumb;
    std::string cookie;

    // Get the Crumb and Cookie from Yahoo Finance
    getYahooCrumbCookie(url, crumb, cookie);

    // Download the historical prices Csv
    std::string csv = downloadYahooCsv(
                this->symbol, period1, period2, interval, crumb, cookie);

    // Free memory

    // Return the csv
    return csv;
}

void Quote::getHistoricalSpots(std::time_t period1,
                               std::time_t period2,
                               const char *interval) {
    // Download the historical prices Csv
    std::string csv = this->getHistoricalCsv(period1, period2, interval);
    std::istringstream csvStream(csv);
    std::string line;

    // Remove the header line
    std::getline(csvStream, line);

    while (std::getline(csvStream, line)) {
        std::vector<std::string> data;
        boost::split(data, line, boost::is_any_of(","));

        if (data[0] != "null" && data[1] != "null") {
            Spot spot = Spot(
                    data[0],                // date
                    std::atof(data[1].c_str()),     // open
                    std::atof(data[2].c_str()),      // high
                    std::atof(data[3].c_str()),     // low
                    std::atof(data[4].c_str())      // close
                    );

            this->spots.push_back(spot);
        }
    }
}

void Quote::getHistoricalSpots(const char *date1,
                               const char *date2,
                               const char *interval) {
    std::time_t period1 = dateToEpoch(date1);
    std::time_t period2 = dateToEpoch(date2);

    this->getHistoricalSpots(period1, period2, interval);
}
