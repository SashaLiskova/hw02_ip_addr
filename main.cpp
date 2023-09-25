#include "Parser.h"
#include <fstream>


int main()
{
    auto ipStorage = parseInput(std::cin);
    
    ipStorage.sort();
    ipStorage.print();
    ipStorage.filter(1).print();
    ipStorage.filter(46,70).print();
    ipStorage.filter_any(46).print();
}