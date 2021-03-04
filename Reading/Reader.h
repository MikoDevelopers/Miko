#pragma once
#include<string>
#include<iostream>
#include <fstream>
class Reader{
    public:
        void read(std::string file_name = "main.miku");
    private:
        struct params{
            std::string server;
            std::string token;
            std::string cmd_list;  
        };
        params settings;

};