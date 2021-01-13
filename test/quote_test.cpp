#include "gtest/gtest.h"
#include "quote.hpp"
#include "time_utils.hpp"

TEST(Quote, TestGetHistoricalCsv) {
    // S&P 500
    Quote *quote = new Quote("^GSPC");
    std::time_t epoch = dateToEpoch("2020-12-01") + 72000;
    std::string csv = quote->getHistoricalCsv(epoch, epoch, "1d");

    // Test the two CSV lines
    std::istringstream csvStream(csv);
    std::string line, expected;

    std::getline(csvStream, line);
    expected = "Date,Open,High,Low,Close,Adj Close,Volume";
    EXPECT_EQ(expected, line);

    std::getline(csvStream, line);
    expected = "2020-12-01,3645.870117,3678.449951,3645.870117,3662.449951,3662.449951,5403660000";
    EXPECT_EQ(expected, line);
}

TEST(Quote, TestGetHistoricalSpots) {
    // Euro Stoxx 50
    Quote *quote = new Quote("^STOXX50E");
    quote->getHistoricalSpots("2020-12-01", "2020-12-02", "1d");

    // Test the spot at 2020-12-01
    Spot spot = quote->getSpot("2020-12-01");
    EXPECT_NEAR(3499.280029, spot.getOpen(), 0.001f);
    EXPECT_NEAR(3532.909912, spot.getHigh(), 0.001f);
    EXPECT_NEAR(3499.280029, spot.getLow(), 0.001f);
    EXPECT_NEAR(3525.239990, spot.getClose(), 0.001f);
}

TEST(Quote, TestEurUsd) {
    // EUR/USD rate
    Quote *quote = new Quote("EURUSD=X");
    quote->getHistoricalSpots("2020-12-01", "2020-12-02", "1d");

    // Test the spot at 2020-12-01
    Spot spot = quote->getSpot("2020-12-01");
    EXPECT_NEAR(1.193773, spot.getOpen(), 0.001f);
    EXPECT_NEAR(1.205357, spot.getHigh(), 0.001f);
    EXPECT_NEAR(1.193599, spot.getLow(), 0.001f);
    EXPECT_NEAR(1.193816, spot.getClose(), 0.001f);
}

TEST(Quote, TestEurAud) {
    // EUR/AUD rate
    Quote *quote = new Quote("EURAUD=X");
    quote->getHistoricalSpots("2020-12-01", "2020-12-02", "1d");

    // Test the spot at 2020-12-01
    Spot spot = quote->getSpot("2020-12-01");
    EXPECT_NEAR(1.622020, spot.getOpen(), 0.001f);
    EXPECT_NEAR(1.637390, spot.getHigh(), 0.001f);
    EXPECT_NEAR(1.621700, spot.getLow(), 0.001f);
    EXPECT_NEAR(1.622550, spot.getClose(), 0.001f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
