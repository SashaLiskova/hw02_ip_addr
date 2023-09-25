#include <iostream>
#include <istream>
#include "Ip_Storage.h"


Ip_Storage parseInput(std::istream & input);
Ip_Address parseIpAddress(const std::string & line);
std::vector<std::string> split(const std::string &str, char d);

