# yahoo-finance

C++ library to get stock data from Yahoo Finance.

*Support Yahoo Finance Novembrer 2017 API change.*

## Dependencies

To use the project, you'll need to install the following dependencies:
- c++11
- cmake >= 3.6.3
- curl

## Build

Build the code using CMake by running the following commands in order:
```
mkdir build
cd build
cmake ..
make
```

## Unit Tests

Launch unit tests using [googletest](https://github.com/google/googletest).
```
make test
```

To recompile the project before running the tests, just run:
```
make all test
```

## Usage

Use the following header to import ``Quote`` class.
```c++
#include "quote.hpp"
```

Code sample:
```c++
// S&P 500
Quote *snp500 = new Quote("^GSPC");

// Get the historical spots from Yahoo Finance
snp500->getHistoricalSpots("2017-12-01", "2017-12-31", "1d");

// Print the spots
snp500->printSpots();

// Print a spot
try {
  Spot spot = snp500->getSpot("2017-12-01");
  spot.printSpot();
} catch(const std::exception &e) {
  std::cerr << e.what() << std::endl;
}

// Get the historical EUR/USD rates
Quote *eurusd = new Quote("EURUSD=X");
eurusd->getHistoricalSpots("2018-01-01", "2018-01-10", "1d");
eurusd->printSpots();

// Get the historical EUR/AUD rates
Quote *euraud = new Quote("EURAUD=X");
euraud->getHistoricalSpots("2018-01-01", "2018-01-10", "1d");
euraud->printSpots();

// Free memory
delete snp500;
delete eurusd;
delete euraud;
```
