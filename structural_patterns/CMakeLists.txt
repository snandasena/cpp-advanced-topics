project(structuraldesignpatterns)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

set(adapterbasic
        src/adapaterbasic/adapterclient.cpp
        src/adapaterbasic/Adaptee.cpp
        src/adapaterbasic/Adapter.cpp)

#add_executable(adapterbasic ${adapterbasic})

set(flightsim
        src/flightsim-object-method/Keyboard.cpp
        src/flightsim-object-method/AccelAdataper.cpp
        src/flightsim-object-method/Accelorometer.cpp
        src/flightsim-object-method/simapp.cpp)

#add_executable(flish-sim ${flightsim})

set(flightsimclass
        src/flightsim-class-method/Keyboard.cpp
        src/flightsim-class-method/AccelAdataper.cpp
        src/flightsim-class-method/Accelorometer.cpp
        src/flightsim-class-method/simapp.cpp)

#add_executable(flightsim-classmethod ${flightsimclass})

set(facadebasic
        src/facade-basic/A.cpp
        src/facade-basic/B.cpp
        src/facade-basic/C.cpp
        src/facade-basic/Client.cpp
        src/facade-basic/Facade.cpp
        src/facade-basic/main.cpp)

#add_executable(facadebasic ${facadebasic})

set(proxybasic
        src/proxcybasic/Proxy.cpp
        src/proxcybasic/RealSubject.cpp
        src/proxcybasic/main.cpp)

add_executable(proxyb ${proxybasic})