#ifndef SPOT_HPP
#define SPOT_HPP

#include <ctime>
#include <string>

/**
 * @brief Spot class
 */
class Spot {

public:

    /**
     * @brief Spot constructor
     * @param date Spot date
     * @param open Price at opening
     * @param high Highest price value
     * @param low Lowest price value
     * @param close Price at closing
     */
    Spot(std::time_t date, double open, double high, double low, double close);

    /**
     * @brief Spot constructor
     * @param date Spot date
     * @param open Price at opening
     * @param high Highest price value
     * @param low Lowest price value
     * @param close Price at closing
     */
    Spot(std::string date, double open, double high, double low, double close);

    /**
    *@brief Spot constructor
    * @param date Spot date
    * @param price Price at closing
    */
    Spot(std::time_t date, double price);

    /**
    *@brief Spot constructor
    * @param date Spot date
    * @param price Price at closing
    */
    Spot(std::string date, double price);

    /**
     * @brief Quote destructor
     */
    ~Spot();

    /**
     * @brief Date getter
     * @return Spot date
     */
    std::time_t getDate();

    /**
     * @brief Date getter
     * @return Spot date
     */
    std::string getDateToString();

    /**
     * @brief Open price getter
     * @return Price at opening
     */
    double getOpen();

    /**
     * @brief High price getter
     * @return Higher price value
     */
    double getHigh();

    /**
     * @brief Low price getter
     * @return Lower price value
     */
    double getLow();

    /**
     * @brief Close price getter
     * @return Price at closing
     */
    double getClose();

    /**
     * @brief Convert Spot into string
     * @return String containing the Spot info
     */
    std::string toString();

    /**
     * @brief Print the spots
     */
    void printSpot();

private:

    /**
     * @brief Spot date in epoch format
     */
    std::time_t date;

    /**
     * @brief Price at opening
     */
    double open;

    /**
     * @brief Highest price value at this date
     */
    double high;

    /**
     * @brief Lowest price value at this date
     */
    double low;

    /**
     * @brief Price at closing
     */
    double close;

};

#endif /* SPOT_HPP */
