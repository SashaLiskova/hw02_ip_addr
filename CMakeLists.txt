
cmake_minimum_required(VERSION 3.12)

project(ip_filter)

set(IP_SOURCES
    Ip_Address.h
    Ip_Address.cpp
    Ip_Storage.h
    Ip_Storage.cpp
)

set(PARSER_SOURCES
    Parser.h
    Parser.cpp
)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")

add_executable(ipv4_filter main.cpp ${IP_SOURCES} ${PARSER_SOURCES})

configure_file(data/ip_filter.tsv ${CMAKE_BINARY_DIR}/ip_filter.tsv COPYONLY)

set_target_properties(
    ipv4_filter PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)