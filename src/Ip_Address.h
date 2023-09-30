#include <array>
#include <iostream>
#include <vector>

#define FAULTY_IP "FAULTY_IP"

using ipv4 =  std::array<uint8_t,4>;

class Ip_Address
{
    public:
    Ip_Address();
    Ip_Address(ipv4 ip);
    Ip_Address(const Ip_Address& other);

    bool isIpValid();

    std::string getStringIp()const;
    ipv4 getIpv4();

    bool operator<(const Ip_Address& other) const ;
    bool operator>(const Ip_Address& other) const;
    bool operator==(const Ip_Address& other) const;

    bool filter(std::vector<uint8_t> filters) const;
    bool filter_any(const u_int8_t val) const;



    private:
    ipv4 mIp;
    bool isEmpty; 



};