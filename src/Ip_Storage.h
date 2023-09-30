#include <iostream>
#include <algorithm>
#include <type_traits>
#include "Ip_Address.h"


class Ip_Storage{
    public:
    Ip_Storage() = default;
    Ip_Storage(std::vector<Ip_Address> ipPool);

    bool operator==(const Ip_Storage& other) const;

    void print();
    void sort();
    int size();

    template <typename... Args>
    Ip_Storage filter(Args... args){
        std::vector<uint8_t> filters = {static_cast<uint8_t>(args)...};

        std::vector<Ip_Address> rez;

        std::copy_if(mIpPool.begin(),mIpPool.end(), std::back_inserter(rez), [&filters](const Ip_Address & ip){
            return ip.filter(filters);
        });

        return Ip_Storage(rez);
    }

    Ip_Storage filter_any(const u_int8_t val);


    private:
    std::vector<Ip_Address> mIpPool;
};