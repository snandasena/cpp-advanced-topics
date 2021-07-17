project(structuraldesignpatterns)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

set(adapterbasic
        src/adapaterbasic/adapterclient.cpp
        src/adapaterbasic/Adaptee.cpp
        src/adapaterbasic/Adapter.cpp)


set(flightsim
        src/flightsim/Keyboard.cpp
        src/flightsim/AccelAdataper.cpp
        src/flightsim/Accelorometer.cpp
        src/flightsim/simapp.cpp)

#add_executable(adapterbasic ${adapterbasic})
add_executable(flish-sim ${flightsim})