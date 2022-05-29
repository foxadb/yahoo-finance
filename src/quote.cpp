#include "quote.hpp"
#include "time_utils.hpp"
#include "curl_utils.hpp"

#include <iostream>
#include <sstream>
#include <curl/curl.h>

Quote::Quote(std::string symbol) {
    this->symbol = symbol;
}

Quote::~Quote() {}

size_t Quote::nbSpots() {
    return this->spots.size();
}

Spot Quote::getSpot(size_t i) {
    if (i < this->spots.size()) {
        return this->spots[i];
    }
    std::stringstream ss;
    ss << this->spots.size();

    std::string error = "ERROR: getSpot(index) - Index must be smaller than "
      + ss.str();
    throw std::invalid_argument(error);
}

Spot Quote::getSpot(std::time_t date) {
    for (std::vector<Spot>::iterator it = this->spots.begin();
         it != this->spots.end();
         ++it) {
        if (it->getDate() == date) {
            return *it;
        }
    }
    std::string error = "ERROR getSpot(date) - There is not spot at " + date;
    throw std::invalid_argument(error);
}

Spot Quote::getSpot(std::string date) {
    for (std::vector<Spot>::iterator it = this->spots.begin();
         it != this->spots.end();
         ++it) {
        if (it->getDateToString() == date) {
            return *it;
        }
    }
    std::string error = "ERROR getSpot(date) - There is not spot at " + date;
    throw std::invalid_argument(error);
}

void Quote::printSpots() {
    for (std::vector<Spot>::iterator it = this->spots.begin();
         it != this->spots.end();
         ++it) {
        std::cout << it->toString() << std::endl;
    }
}

void Quote::clearSpots() {
    this->spots.clear();
}

std::string Quote::getHistoricalCsv(
    std::time_t period1,
    std::time_t period2,
    const char *interval
) {
    return downloadYahooCsv(this->symbol, period1, period2, interval);
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
        // Split line delimited by comma separator into a vector
        std::vector<std::string> spotVector;
        std::stringstream iss(line);
        std::string lineItem;
        while (std::getline(iss, lineItem, ',')) {
            spotVector.push_back(lineItem);
        }

        if (spotVector[0] != "null" && spotVector[1] != "null") {
            Spot spot = Spot(
                spotVector[0],                      // date
                std::atof(spotVector[1].c_str()),   // open
                std::atof(spotVector[2].c_str()),   // high
                std::atof(spotVector[3].c_str()),   // low
                std::atof(spotVector[4].c_str())    // close
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
