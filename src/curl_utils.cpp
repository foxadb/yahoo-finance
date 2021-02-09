#include "curl_utils.hpp"
#include "time_utils.hpp"

#include <curl/curl.h>
#include <sstream>

size_t writeCallback(char *content, size_t size, size_t nmemb, void *userdata) {
    // Append the content to user data
    ((std::string*)userdata)->append(content, size * nmemb);

    // Return the real content size
    return size * nmemb;
}

std::string downloadYahooCsv(
    std::string symbol,
    std::time_t period1,
    std::time_t period2,
    std::string interval
) {
    std::stringstream ss1; 
    ss1 << period1; 
    std::stringstream ss2; 
    ss2 << period2;

    std::string url = "https://query1.finance.yahoo.com/v7/finance/download/"
            + symbol
            + "?period1=" + ss1.str()
            + "&period2=" + ss2.str()
            + "&interval=" + interval
            + "&events=history";

    CURL* curl = curl_easy_init();
    std::string responseBuffer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Write result into the buffer
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Cleanup
        curl_easy_cleanup(curl);
    }

    return responseBuffer;
}
