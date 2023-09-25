#include "Parser.h"
#include <limits>
#include <algorithm>

Ip_Storage parseInput(std::istream & input)
{
    std::vector<Ip_Address> ipPool;

    for(std::string line; std::getline(input, line);)
    {

        std::vector<std::string> singleLine = split(line,'\t');


        auto ip = parseIpAddress(singleLine[0]);
        
        if(ip.isIpValid())
            ipPool.push_back(ip);
        else
            std::cout<<"ERR: line \""<<line<<"\" doesn't have correct ipAdress, it was skiped"<<std::endl;
    }


    return Ip_Storage(ipPool);

}

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
        
    }

    r.push_back(str.substr(start));


    return r;
}

Ip_Address parseIpAddress(const std::string & line)
{

    auto splitedIpAdress = split(line,'.');

    if(splitedIpAdress.size()!=4)
    {
        return Ip_Address();
    }

    std::array<uint8_t,4> ipv4;

    for(int i = 0; i<splitedIpAdress.size(); ++i)
    {
        int val = stoi(splitedIpAdress[i]);
        
        if(Ip_Storage::isIpStaticCastSafe(val))
            ipv4[i]= static_cast<uint8_t>(val);
        else
            return Ip_Address();
    }

    return Ip_Address(ipv4,line);
}

