#include "Ip_Address.h"
#include <algorithm>


Ip_Address::Ip_Address()
{
    isEmpty = true;
}

Ip_Address::Ip_Address(ipv4 ip):
    mIp(ip),
    isEmpty(false)
{}

Ip_Address::Ip_Address( const Ip_Address& other)
{  
    mIp = other.mIp;
    isEmpty = other.isEmpty;
}

std::string Ip_Address::getStringIp() const
{
    std::string ipString = "";
    std::for_each(mIp.begin(),mIp.end()-1,[&ipString](const auto &num){
        ipString +=std::to_string(num);
        ipString+=".";
    });

    ipString +=std::to_string(mIp[3]);

    return ipString;


}

bool Ip_Address::isIpValid()
{
    return !isEmpty;
}

ipv4 Ip_Address::getIpv4()
{
    return mIp;
}

bool Ip_Address::operator<(const Ip_Address& other) const 
{
    return this->mIp<other.mIp;
}
bool Ip_Address::operator>(const Ip_Address& other) const
{
    return this->mIp>other.mIp;
}

bool Ip_Address::operator==(const Ip_Address& other) const
{
    return this->mIp==other.mIp;
}

bool Ip_Address::filter(std::vector <uint8_t> filters) const
{
   auto mismatchResult = std::mismatch(filters.begin(), filters.end(), mIp.begin());
   return mismatchResult.first == filters.end();
}

bool Ip_Address::filter_any(const u_int8_t val) const
{
    return std::any_of(mIp.begin(),mIp.end(),[&val](const u_int8_t ipVal){
        return ipVal == val;
    });

}
