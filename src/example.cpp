#include "quote.hpp"

#include <iostream>

int main() {
    // S&P 500
    Quote *snp500 = new Quote("^GSPC");

    // Get the historical spots from Yahoo Finance
    snp500->getHistoricalSpots("2017-12-01", "2017-12-31", "1d");

    // Print the spots
    snp500->printSpots();

    // Print a spot
    try {
        Spot spot = snp500->getSpot("2017-12-01");
        std::cout << "Spot at 2017-12-01: " << std::endl;
        spot.printSpot();
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Get the historical EUR/USD rates
    Quote *eurusd = new Quote("EURUSD=X");
    eurusd->getHistoricalSpots("2018-01-01", "2018-01-10", "1d");
    std::cout << "EUR/USD rates between 2018-01-01 and 2018-01-10" << std::endl;
    eurusd->printSpots();

    // Get the historical EUR/AUD rates
    Quote *euraud = new Quote("EURAUD=X");
    euraud->getHistoricalSpots("2018-01-01", "2018-01-10", "1d");
    std::cout << "EUR/AUD rates between 2018-01-01 and 2018-01-10" << std::endl;
    euraud->printSpots();

    // Free memory
    delete snp500;
    delete eurusd;
    delete euraud;
}
