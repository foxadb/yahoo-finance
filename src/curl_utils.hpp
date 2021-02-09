#ifndef CURL_UTILS_HPP
#define CURL_UTILS_HPP

#include <string>
#include <ctime>

/**
 * @brief Write callback function for Curl
 * @param content Deliver content pointer
 * @param size Content element bytes size
 * @param nmemb Number of content element
 * @param userdata User data where contents are storaged
 * @return Real buffer size = size * nmemb
 */
size_t writeCallback(char *content, size_t size, size_t nmemb, void *userdata);

/**
 * @brief Download the spots CSV file from Yahoo Finance
 * @param symbol Quote symbol
 * @param period1 Begining POSIX timestamp
 * @param period2 Ending POSIX timestamp
 * @param interval Date interval for spots, examples:
 *          daily "1d"
 *          weekly "1wk"
 *          annual "1y"
 * @return CSV file containing the spots
 */
std::string downloadYahooCsv(
    std::string symbol,
    std::time_t period1,
    std::time_t period2,
    std::string interval
);

#endif /* CURL_UTILS_HPP */
