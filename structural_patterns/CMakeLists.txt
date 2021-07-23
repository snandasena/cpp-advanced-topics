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

#add_executable(proxyb ${proxybasic})

set(virtualp1
        src/virtual-proxy1/Image.cpp
        src/virtual-proxy1/Bitmap.cpp
        src/virtual-proxy1/BitmapProxy.cpp
        src/virtual-proxy1/main.cpp)

#add_executable(virtualpexe ${virtualp1})

set(protectionproxysrc
        src/protection-proxy/Storage.cpp
        src/protection-proxy/Repository.cpp
        src/protection-proxy/Employee.cpp
        src/protection-proxy/RepoProxy.cpp
        src/protection-proxy/main.cpp)

#add_executable(protectprox ${protectionproxysrc})


set(smartproxcy
        src/smart-proxy/Bitmap.cpp
        src/smart-proxy/Image.cpp
        src/smart-proxy/Pointer.cpp
        src/smart-proxy/main.cpp)


#add_executable(smartypxcy ${smartproxcy})

#add_executable(openclose src/SOLID/openclosed_temaplate_specilization.cpp)
#add_executable(opencloseruntime src/SOLID/openclosed_runtime_concept.cpp)


set(decoratorbasic
        src/decorator/Component.cpp
        src/decorator/ConcreteComponent.cpp
        src/decorator/ConcreteDecoratorA.cpp
        src/decorator/ConcreteDecoratorB.cpp
        src/decorator/Decorator.cpp
        src/decorator/main.cpp)

add_executable(decoratorbsc ${decoratorbasic})