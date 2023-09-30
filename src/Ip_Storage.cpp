#include "Ip_Storage.h"

Ip_Storage::Ip_Storage( std::vector<Ip_Address> ipPool):mIpPool(ipPool)
{

}

bool Ip_Storage::operator==(const Ip_Storage& other) const
{
    return mIpPool == other.mIpPool;
}


void Ip_Storage::print()
{
    for_each(mIpPool.begin(),mIpPool.end(),[](const Ip_Address & ip){
        std::cout<<ip.getStringIp()<<std::endl;
    });
};

void Ip_Storage::sort()
{
    std::sort(mIpPool.begin(),mIpPool.end(),[](const Ip_Address &lIp,const Ip_Address &rIp){
        return lIp>rIp;
    });
}

int Ip_Storage::size()
{
    return mIpPool.size();

}

Ip_Storage Ip_Storage::filter_any(const u_int8_t val)
{
    std::vector<Ip_Address> rez;

    auto valIp = static_cast<u_int8_t>(val);

    std::copy_if(mIpPool.begin(),mIpPool.end(), std::back_inserter(rez), [&valIp](const Ip_Address & ip){
            return ip.filter_any(valIp);
        });
        
    return Ip_Storage(rez);
}


