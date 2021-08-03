project(structuraldesignpatterns)

#find_package(PkgConfig REQUIRED)


SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")
#SET(CMAKE_CXX_FLAGS "-lsimple2d -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -lGL -lm -lSDL2_image -lSDL2_mixer -lSDL2_ttf")
#SET(CMAKE_CXX_FLAGS "-lSDL2 -lGL -lm -lSDL2_image -lSDL2_mixer -lSDL2_ttf")
#add_compile_options(`simple2d --libs`)

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

#add_executable(decoratorbsc ${decoratorbasic})

set(streamdeco
        src/streaming-decorator/FileInputStream.cpp
        src/streaming-decorator/FileOutputStream.cpp
        src/streaming-decorator/BufferOutputStream.cpp
        src/streaming-decorator/BufferedInputStream.cpp
        src/streaming-decorator/main.cpp)

#add_executable(streamdecorator ${streamdeco})

#add_executable(funcdeco src/func-decorator/main.cpp)

set(compositebasic
        src/composite-basic/Component.cpp
        src/composite-basic/Leaf.cpp
        src/composite-basic/Composite.cpp
        src/composite-basic/main.cpp)

#add_executable(compobasic ${compositebasic})

set(uicompo
        src/UIComposite/Button.cpp
        src/UIComposite/Frame.cpp
        src/UIComposite/main.cpp)

#add_executable(uicomposite ${uicompo})

#pkg_check_modules(MY_PKG REQUIRED IMPORTED_TARGET )

set(SIMPLE2D_IBS -lsimple2d -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -lGL -lm -lSDL2_image -lSDL2_mixer -lSDL2_ttf)

#add_executable(bridge src/bridge/main.cpp)
#target_link_libraries(bridge ${SIMPLE2D_IBS})

#target_compile_options(bridge simple2d --libs)

set(bridgebasic
        src/bridge-basic/ConcreateImplementationA.cpp
        src/bridge-basic/ConcreteImplementorB.cpp
        src/bridge-basic/main.cpp)

add_executable(bridgebasic ${bridgebasic})