cmake_minimum_required(VERSION 3.14)

project(conc1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Concurrent Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Concurrent Core)

add_executable(conc1
  main.cpp
)
target_link_libraries(conc1 Qt${QT_VERSION_MAJOR}::Concurrent Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS conc1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
