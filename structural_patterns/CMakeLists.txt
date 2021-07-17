project(structuraldesignpatterns)

set(adapterbasic
        src/adapaterbasic/adapterclient.cpp
        src/adapaterbasic/Adaptee.cpp
        src/adapaterbasic/Adapter.cpp
        )

add_executable(adapterbasic ${adapterbasic})