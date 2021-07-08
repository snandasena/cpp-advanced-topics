project(designpatterns)

add_subdirectory(src/ll)
SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

#add_executable(factorymethod src/factory_method.cpp)
#add_executable(abstractfactory src/abstract_factory.cpp)
#add_executable(builder src/builder.cpp)
#add_executable(prototype src/prototype.cpp)
#add_executable(singleton src/singleton.cpp)
add_executable(chainof_responsibility src/behavioral/chainof_responsibility.cpp)
