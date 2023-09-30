#include <gtest/gtest.h>
#include "Ip_Storage.h"

const std::vector<Ip_Address> testedIp{ {{1, 6, 234, 8}},
                                        {{1, 70, 46, 170}}, 
                                        {{222, 173, 235, 64}}, 
                                        {{222, 82, 198, 6}}};


TEST(Ip_StorageTest, CorrectSorting)
{
    std::vector<Ip_Address> expectedIp{ {{222, 173, 235, 64}},
                                        {{222, 82, 198, 6}}, 
                                        {{1, 70, 46, 170}}, 
                                        {{1, 6, 234, 8}}};
  

    Ip_Storage ipStorageTested(testedIp);
    ipStorageTested.sort();

    EXPECT_EQ(ipStorageTested,Ip_Storage(expectedIp));
}

TEST(Ip_StorageTest, CorrectFiltering)
{
    std::vector<Ip_Address> expectedIp{ {{1, 6, 234, 8}},
                                        {{1, 70, 46, 170}}};

                        

    Ip_Storage ipStorage(testedIp);
    auto filteredIpStorage = ipStorage.filter(1);

    EXPECT_EQ(filteredIpStorage,expectedIp);
}

TEST(Ip_StorageTest, CorrectFilterAny)
{

    std::vector<Ip_Address> expectedIp{ {{1, 6, 234, 8}}, 
                                        {{222, 82, 198, 6}}};

                        

    Ip_Storage ipStorage(testedIp);
    auto filteredIpStorage = ipStorage.filter_any(6);

    EXPECT_EQ(filteredIpStorage,expectedIp);
}