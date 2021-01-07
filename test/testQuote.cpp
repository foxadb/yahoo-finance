#define BOOST_TEST_MODULE QuoteTest
#include <boost/test/unit_test.hpp>

#include "quote.hpp"
#include "time_utils.hpp"


BOOST_AUTO_TEST_CASE(TestGetHistoricalCsv) {
    // S&P 500
    Quote *quote = new Quote("^GSPC");
    std::time_t epoch = dateToEpoch("2020-12-01") + 72000;
    std::string csv = quote->getHistoricalCsv(epoch, epoch, "1d");

    // Test the two CSV lines
    std::istringstream csvStream(csv);
    std::string line, expected;

    std::getline(csvStream, line);
    expected = "Date,Open,High,Low,Close,Adj Close,Volume";
    BOOST_CHECK_EQUAL(expected, line);

    std::getline(csvStream, line);
    expected = "2020-12-01,3645.870117,3678.449951,3645.870117,3662.449951,3662.449951,5403660000";
    BOOST_CHECK_EQUAL(expected, line);
}

BOOST_AUTO_TEST_CASE(TestGetHistoricalSpots) {
    // Euro Stoxx 50
    Quote *quote = new Quote("^STOXX50E");
    quote->getHistoricalSpots("2020-12-01", "2020-12-02", "1d");

    // Test the spot at 2020-12-01
    Spot spot = quote->getSpot("2020-12-01");
    BOOST_CHECK_CLOSE(3499.280029, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(3532.909912, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(3499.280029, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(3525.239990, spot.getClose(), 0.001f);
}

BOOST_AUTO_TEST_CASE(TestEurUsd) {
    // EUR/USD rate
    Quote *quote = new Quote("EURUSD=X");
    quote->getHistoricalSpots("2020-12-01", "2020-12-02", "1d");

    // Test the spot at 2020-12-01
    Spot spot = quote->getSpot("2020-12-01");
    BOOST_CHECK_CLOSE(1.193773, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(1.205357, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(1.193599, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(1.193816, spot.getClose(), 0.001f);
}

BOOST_AUTO_TEST_CASE(TestEurAud) {
    // EUR/AUD rate
    Quote *quote = new Quote("EURAUD=X");
    quote->getHistoricalSpots("2020-12-01", "2020-12-02", "1d");

    // Test the spot at 2020-12-01
    Spot spot = quote->getSpot("2020-12-01");
    BOOST_CHECK_CLOSE(1.622020, spot.getOpen(), 0.001f);
    BOOST_CHECK_CLOSE(1.637390, spot.getHigh(), 0.001f);
    BOOST_CHECK_CLOSE(1.621700, spot.getLow(), 0.001f);
    BOOST_CHECK_CLOSE(1.622550, spot.getClose(), 0.001f);
}
