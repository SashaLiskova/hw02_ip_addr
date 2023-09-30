#include <istream>
#include "Ip_Storage.h"

class Parser
{
    public:
        Parser() = default;
        Ip_Storage parseInput(std::istream & input);
    
    private:
        Ip_Address parseIpAddress(const std::string & line);
        std::vector<std::string> split(const std::string &str, char d);

};

