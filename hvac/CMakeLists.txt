cmake_minimum_required(VERSION 3.9)
project(restsample)

set(cpprestsdk_DIR /usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}/cmake/)
#find_package(Boost REQUIRED system)
find_package(cpprestsdk REQUIRED)

set(BOOST_INCLUDE_DIR "/usr/include/boost")
#set(BOOST_LIBS "/usr/lib/libboost_system.so.1.79.0")
set(SYSTEM_INCLUDE_DIR "/usr/include/")

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(restsample ${SRC_DIR}/restsample.cpp ${INCLUDE_DIR}/json.hpp)
target_include_directories(restsample PUBLIC ${INCLUDE_DIR}/ ${BOOST_INCLUDE_DIR})
target_link_libraries(restsample cpprestsdk::cpprest ${BOOST_LIBS})
# include_directories(/usr/include)
#link_directories(/usr/lib)
# target_link_libraries (${SYSTEM_INCLUDE_DIR} sqlite3.h)
#endif (SQLITE3_FOUND)

include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(restsample sqlite3)

