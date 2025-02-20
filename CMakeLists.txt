cmake_minimum_required(VERSION 3.20.0)

project(FXHedging CXX)

# Release or Debug
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif ()

# Find Pnl
find_package(Pnl REQUIRED)
set(LIBS ${LIBS} ${PNL_LIBRARIES})
include_directories(${PNL_INCLUDE_DIRS})
if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    add_definitions(-DPNL_RANGE_CHECK_OFF)
endif()

# Find nlohmann_json to parse json files
# Add nlohmann_json::nlohmann_json to target_link_libraries
find_package(nlohmann_json REQUIRED)

set(fxhedging_hdrs  src/json_reader.hpp)
add_library(fx_hedging src/json_reader.cpp ${fxhedging_hdrs})
target_link_libraries(fx_hedging ${PNL_LIBRARIES} nlohmann_json::nlohmann_json)

# add_executable(test_fx_hedging test_fx_hedging.cpp)
# target_link_libraries(test_fx_hedging fx_hedging)
# pnl_add_postbuild(test_fx_hedging)

add_executable(hedger src/Hedger.cpp src/json_reader.cpp src/Parser.cpp src/Grid/FixedTimeGrid.cpp src/Grid/ListTimeGrid.cpp src/Risky/RiskyDynamics.cpp src/Risky/RiskyAsset.cpp src/Risky/Currency.cpp src/InterestRateModel.cpp src/Portfolio.cpp src/Options/OptionBasket.cpp src/Options/OptionCallCurrency.cpp src/Options/OptionCallQuanto.cpp src/Options/OptionForeignAsian.cpp src/Options/OptionForeignPerfBasket.cpp src/Options/OptionQuantoExchange.cpp src/MonteCarlo.cpp src/GlobalModel.cpp)
target_link_libraries(hedger ${PNL_LIBRARIES} nlohmann_json::nlohmann_json)
pnl_add_postbuild(hedger)