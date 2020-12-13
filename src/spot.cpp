#include "spot.hpp"
#include "time_utils.hpp"

#include <iostream>
#include <sstream>

Spot::Spot(std::time_t date, double open, double high, double low, double close) {
    this->date = date;
    this->open = open;
    this->high = high;
    this->low = low;
    this->close = close;
}

Spot::Spot(const std::string& date, double open, double high, double low, double close) {
    this->date = dateToEpoch(date.c_str());
    this->open = open;
    this->high = high;
    this->low = low;
    this->close = close;
}

Spot::Spot(std::time_t date, double price){
  this->date = date;
  this->close = price;
  this->open = price;
  this->high = price;
  this->low = price;
}

Spot::Spot(const std::string& date, double price){
  this->date = dateToEpoch(date.c_str());
  this->close = price;
  this->open = price;
  this->high = price;
  this->low = price;
}

Spot::~Spot() {}

std::time_t Spot::getDate() const {
    return this->date;
}

std::string Spot::getDateToString() const {
    return epochToDate(this->date);
}

double Spot::getOpen() const {
    return this->open;
}

double Spot::getHigh() const {
    return this->high;
}

double Spot::getLow() const {
    return this->low;
}

double Spot::getClose() const {
    return this->close;
}


std::string Spot::toString() const {
    std::ostringstream osOpen;
    osOpen << this->open;
    std::ostringstream osHigh;
    osHigh << this->high;
    std::ostringstream osLow;
    osLow << this->low;
    std::ostringstream osClose;
    osClose << this->close;
    return "{ date: " + this->getDateToString()
            + " open: " + osOpen.str()
            + " high: " + osHigh.str()
            + " low: " + osLow.str()
            + " close: " + osClose.str()
            + " }";
}

void Spot::printSpot() const {
    std::cout << this->toString() << std::endl;
}
