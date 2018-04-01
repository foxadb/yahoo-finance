#ifndef QUOTE_HPP
#define QUOTE_HPP

#include "spot.hpp"

#include <vector>

/**
 * @brief Quote class
 */
class Quote {

public:

    /**
     * @brief Quote constructor
     * @param symbol
     */
    Quote(std::string symbol);

    /**
     * @brief Quote destructor
     */
    ~Quote();

    /**
     * @brief Spots number
     * @return Number of spots in the quote
     */
    size_t nbSpots();

    /**
     * @brief Spot getter by index
     * @param i spot index
     * @return spots(i)
     */
    Spot getSpot(size_t i);

    /**
     * @brief Spot getter by date
     * @param date Spot date
     * @return spots(date)
     */
    Spot getSpot(std::time_t date);

    /**
     * @brief Spot getter by date
     * @param date Spot date
     * @return spots(date)
     */
    Spot getSpot(std::string date);

    /**
     * @brief Print all the spots
     */
    void printSpots();

    /**
     * @brief Clear all the spots
     */
    void clearSpots();

    /**
     * @brief Get the historical spot CSV file string
     * @param period1 Begining date (POSIX timestamp)
     * @param period2 Ending date (POSIX timestamp)
     * @param interval Date interval for spots, examples:
     *          daily "1d"
     *          weekly "1wk"
     *          annual "1y"
     * @return string containing the historical csv file
     */
    std::string getHistoricalCsv(std::time_t period1,
                                 std::time_t period2,
                                 const char *interval);

    /**
     * @brief Fill spots vector on a period
     * @param period1 Begining date (POSIX timestamp)
     * @param period2 Ending date (POSIX timestamp)
     * @param interval Date interval for spots, examples:
     *          daily "1d"
     *          weekly "1wk"
     *          annual "1y"
     */
    void getHistoricalSpots(std::time_t period1,
                            std::time_t period2,
                            const char *interval);

    /**
     * @brief Fill spots vector on a period
     * @param period1 Begining date (format yyyy-MM-dd)
     * @param period2 Ending date (format yyyy-MM-dd)
     * @param interval Date interval for spots, examples:
     *          daily "1d"
     *          weekly "1wk"
     *          annual "1y"
     */
    void getHistoricalSpots(const char *period1,
                            const char *period2,
                            const char *interval);

private:

    /**
     * @brief Quote symbol
     */
    std::string symbol;

    /**
     * @brief Spots vector
     */
    std::vector<Spot> spots;
};

#endif /* QUOTE_HPP */
