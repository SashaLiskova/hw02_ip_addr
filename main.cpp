#include "src/Parser.h"

int main()
{
    Parser parser{}; 
    auto ipStorage = parser.parseInput(std::cin);
        
    ipStorage.sort();
    ipStorage.print();
    ipStorage.filter(1).print();
    ipStorage.filter(46,70).print();
    ipStorage.filter_any(46).print();
}