#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <string>
#include <ctime>

/**
 * @brief Current Epoch time (POSIX timestamp)
 * @return The current POSIX timestamp
 */
std::time_t currentEpoch();

/**
 * @brief Convert date to POSIX timestamp
 * @param date Date to convert in yyyy-MM-dd format (ignore hour)
 * @return Date in epoch format
 */
std::time_t dateToEpoch(const char *date);

/**
 * @brief Convert POSIX timestamp in date
 * @param epoch POSIX timestamp
 * @return Date in yyyy-MM-dd format (ignore hour)
 */
std::string epochToDate(const std::time_t epoch);

/**
 * @brief Compare two dates in yyyy-MM-dd format
 * @param date1 First date
 * @param date2 Second date
 * @return True if date1 <= date2, False otherwise
 */
bool before(const char *date1, const char *date2);

#endif /* TIME_UTILS_H */
