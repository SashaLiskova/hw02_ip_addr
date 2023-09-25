#include "Ip_Address.h"
#include <algorithm>


Ip_Address::Ip_Address()
{
    mStringIp = FAULTY_IP;
}

Ip_Address::Ip_Address(ipv4 ip, std::string stringIp):
    mIp(ip),
    mStringIp(stringIp)
{}

Ip_Address::Ip_Address( const Ip_Address& other)
{  
    mStringIp = other.mStringIp;
    mIp = other.mIp;
}

std::string Ip_Address::getStringIp() const
{
    return mStringIp;
}

bool Ip_Address::isIpValid()
{
    return mStringIp!=FAULTY_IP;
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
