#ifndef PRINT_H
#define PRINT_H
 
#include <iostream>
#include <string>


template <class Map>
void Print(std::string data, Map MapLink)
{
    bool isVar = false;

    if (data.find('"') == -1)
    {
        isVar = true;
    }

    data = data.substr(data.find("(") + 1, data.find(";"));
    data = data.substr(0, data.find(")"));

    if (isVar)
    {
        auto val = MapLink.getVariableValues()[data];
        std::cout << val << std::endl;
    } else {
        std::cout << data << std::endl;
    }
}

#endif