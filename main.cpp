#include "src/Parser.h"
#include <fstream>

int main()
{
    Parser parser{}; 
    // std::ifstream input("ip_filter.tsv");

    // if(!input.is_open())
    // {
    //     std::cerr<<"no file\n";
    //     return 1;
    // }

    auto ipStorage = parser.parseInput(std::cin);
    
    //input.close();
    
    ipStorage.sort();
    ipStorage.print();
    ipStorage.filter(1).print();
    ipStorage.filter(46,70).print();
    ipStorage.filter_any(46).print();
}