#include "time_utils.hpp"

#include <sstream>
#include <cstring>

std::time_t currentEpoch() {
    return std::time(NULL);
}

std::time_t dateToEpoch(const char *date) {
    char year[5] = {0};
    strncpy(year, date, 4);

    char month[3] = {0};
    strncpy(month, date + 5, 2);

    char day[3] = {0};
    strncpy(day, date + 8, 2);

    struct tm time = {0};
    time.tm_year = std::atoi(year) - 1900;
    time.tm_mon = std::atoi(month) - 1;
    time.tm_mday = std::atoi(day);

    return timegm(&time);
}

std::string epochToDate(const std::time_t epoch) {
    struct std::tm *ptm = std::gmtime(&epoch);
    std::stringstream osYear;
    osYear << ptm->tm_year + 1900;

    std::stringstream osMonth;
    if (ptm->tm_mon < 9) {
        osMonth << 0 << ptm->tm_mon + 1;
    } else {
        osMonth << ptm->tm_mon + 1;
    }

    std::stringstream osDay;
    if (ptm->tm_mday < 10) {
        osDay << 0 << ptm->tm_mday;
    } else {
        osDay << ptm->tm_mday;
    }

    std::string date = osYear.str() + "-" + osMonth.str() + "-" + osDay.str();
    return date;
}

bool before(const char *date1, const char *date2) {
    std::time_t epoch1 = dateToEpoch(date1);
    std::time_t epoch2 = dateToEpoch(date2);

    return epoch1 < epoch2;
}
