#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


#include "MikoStruct.h"
#include "Read/ReadMikoFile.h"
//#include "Functions/PrintFunction/PrintFoo.h"





int main(int argc, char *argv[])
{
    //std::string *test = ReadMikoFileFunction("main.miko");
    //std::vector<std::string> ReadedMikoDatas = ReadMikoFileFunction("main.miko");

    main_maps::Map test;

    std::cout << test.getInt() << std::endl;


    return 0;
}


//g++ main.cpp Read/ReadMikoFile.cpp -o main && main