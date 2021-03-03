#pragma once
#include <fstream>
#include <string>

class Reader{
    public:
        void read(std::string filename = "main.miko");
    private:
        struct params{
            std::string server;
            std::string token;
            std::string command_list;
        };


};