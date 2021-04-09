#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>


std::string Input(std::string lineInput)
{
    std::string self = lineInput;
    self = self.substr(self.find("(") + 1, self.find(";"));
    self = self.substr(0, self.find(")"));
    self = self.substr(1, self.length());
    self = self.substr(0, self.find('"'));

    std::cout << self;
    std::string data;
    std::cin >> data;
    return data;
}

#endif