
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

add_library(ipv4_storage ${IP_SOURCES} ${PARSER_SOURCES})