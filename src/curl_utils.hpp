#ifndef CURL_UTILS_HPP
#define CURL_UTILS_HPP

#include <string>
#include <ctime>

/**
 * @brief Save Yahoo crumb and cookie in a file
 * @param filename Name of the save file
 * @param crumb Crumb pointer
 * @param cookie Cookie pointer
 */
void saveYahooCredentials(const char* filename, std::string *crumb, std::string *cookie);

/**
 * @brief Read the cookie last update time in the save file
 * @param filename Name of the save file
 * @return The cookie last update POSIX timestamp
 */
std::time_t readCookieTime(const char* filename);

/**
 * @brief Read the crumb value from the save file
 * @param filename Name of the save file
 * @param crumb Crumb
 */
void readCrumbCredential(const char* filename, std::string *crumb);

/**
 * @brief Read the cookie value from the save file
 * @param filename Name of the save file
 * @param cookie Cookie pointer
 */
void readCookieCredential(const char* filename, std::string *cookie);

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
 * @brief Get the Yahoo Finance crumb and cookie
 * @param url Request url
 * @param crumb Crumb pointer
 * @param cookie Cookie pointer
 */
void getYahooCrumbCookie(std::string url, std::string *crumb, std::string *cookie);

/**
 * @brief Extract the Yahoo crumb value from the response code
 * @param code Reponse code from Yahoo Finance
 * @return Crumb value
 */
std::string extractYahooCrumb(std::string code);

/**
 * @brief Extract the Yahoo cookie value from the cookie file
 * @param filename Name of the save file
 * @return Cookie value
 */
std::string extractYahooCookie(const char* filename);

/**
 * @brief Download the spots CSV file from Yahoo Finance
 * @param symbol Quote symbol
 * @param period1 Begining POSIX timestamp
 * @param period2 Ending POSIX timestamp
 * @param interval Date interval for spots, examples:
 *          daily "1d"
 *          weekly "1wk"
 *          annual "1y"
 * @param crumb Crumb pointer
 * @param cookie Cookie pointer
 * @return CSV file containing the spots
 */
std::string downloadYahooCsv(std::string symbol,
                             std::time_t period1,
                             std::time_t period2,
                             std::string interval,
                             std::string *crumb,
                             std::string *cookie);

#endif /* CURL_UTILS_HPP */
