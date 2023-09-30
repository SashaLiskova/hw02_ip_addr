#include <gtest/gtest.h>
#include "Parser.h"
#include <sstream>

Ip_Storage runParser(const std::string & input)
{
    std::istringstream inputStream(input);
    
    Parser p{};

    return p.parseInput(inputStream);
}

TEST(Parser, FaultyIpAddressInput)
{
    auto ip_storage = runParser("226.225.333.4");
    EXPECT_EQ(ip_storage.size(), 0);
}