#define BOOST_TEST_MODULE QuoteTest
#include <boost/test/unit_test.hpp>

#include "quote.hpp"
#include "time_utils.hpp"


BOOST_AUTO_TEST_CASE(TestGetHistoricalCsv) {
    // S&P 500
    Quote quote("^GSPC");
    std::time_t epoch = dateToEpoch("2017-12-01") + 72000;
    std::string csv = quote.getHistoricalCsv(epoch, epoch, "1d");

    // Test the two CSV lines
    std::istringstream csvStream(csv);
    std::string line, expected;

    std::getline(csvStream, line);
    expected = "Date,Open,High,Low,Close,Adj Close,Volume";
    BOOST_CHECK_EQUAL(expected, line);

    std::getline(csvStream, line);
    expected = "2017-12-01,2645.100098,2650.620117,2605.520020,2642.219971,2642.219971,3942320000";
    BOOST_CHECK_EQUAL(expected, line);
}

BOOST_AUTO_TEST_CASE(TestGetHistoricalSpots) {
    // Euro Stoxx 50
    Quote quote("^STOXX50E");
    quote.getHistoricalSpots("2017-12-01", "2017-12-04", "1d");

    // Test the spot at 2017-12-01
    Spot spot = quote.getSpot("2017-12-01");
    BOOST_CHECK_CLOSE(3527.550049, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(3527.550049, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(3527.550049, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(3527.550049, spot.getClose(), 0.001f);

    // Test the spot at 2017-12-04
    spot = quote.getSpot("2017-12-04");
    BOOST_CHECK_CLOSE(3576.219971, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(3576.219971, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(3576.219971, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(3576.219971, spot.getClose(), 0.001f);
}

BOOST_AUTO_TEST_CASE(TestEurUsd) {
    // EUR/USD rate
    Quote quote("EURUSD=X");
    quote.getHistoricalSpots("2017-12-01", "2017-12-31", "1d");

    // Test the spot at 2017-12-08
    Spot spot = quote.getSpot("2017-12-08");
    BOOST_CHECK_CLOSE(1.17744, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(1.17772, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(1.17319, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(1.17722, spot.getClose(), 0.001f);

    // Test the spot at 2017-12-21
    spot = quote.getSpot("2017-12-21");
    BOOST_CHECK_CLOSE(1.18778, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(1.1892, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(1.18502, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(1.18782, spot.getClose(), 0.001f);
}

BOOST_AUTO_TEST_CASE(TestEurAud) {
    // EUR/AUD rate
    Quote quote("EURAUD=X");
    quote.getHistoricalSpots("2017-12-01", "2017-12-31", "1d");

    // Test the spot at 2017-12-13
    Spot spot = quote.getSpot("2017-12-13");
    BOOST_CHECK_CLOSE(1.553756, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(1.552764, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(1.545433, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(1.553957, spot.getClose(), 0.001f);

    // Test the spot at 2017-12-27
    spot = quote.getSpot("2017-12-27");
    BOOST_CHECK_CLOSE(1.534314, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(1.533646, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(1.531682, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(1.533925, spot.getClose(), 0.001f);
}
