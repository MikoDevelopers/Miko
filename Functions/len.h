#ifndef LEN_H
#define LEN_H

#include <iostream>
#include <string>


template <class Map>
int Len(std::string lineForLen, Map MapLink)
{
    if (lineForLen.find('"') == -1)
    {
        std::string variable_name = lineForLen.substr(lineForLen.find("(") + 1, lineForLen.length());
        variable_name = variable_name.substr(0, variable_name.find(")"));
        std::string dataVar = MapLink.getVariableValues()[variable_name];

        return dataVar.length();
    }

    return 0;
}

#endif