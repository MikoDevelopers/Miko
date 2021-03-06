#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


#include "MikoStruct.h"
#include "Read/ReadMikoFile.h"
//#include "Functions/PrintFunction/PrintFoo.h"

#include "Analizator/CodeAnalizer.hpp"






int main(int argc, char *argv[])
{
    std::cout << "Start reading..." << std::endl;
    //std::string *test = ReadMikoFileFunction("main.miko");
    std::vector<std::string> ReadedMikoDatas = ReadMikoFileFunction("main.miko");

    std::cout << "Datas was readed..." << std::endl;

    Analizer::FindSettings Anlzr;
    Anlzr.findStartPoint(ReadedMikoDatas);
    Anlzr.findEndPoint(ReadedMikoDatas);
    Anlzr.appendTempDatasForWork(ReadedMikoDatas);

    ReadedMikoDatas = Anlzr.changeReadedMikoDatas(ReadedMikoDatas);


    settings::Setting GlobalSettings;
    GlobalSettings.setBot(Anlzr.findBot());
    GlobalSettings.setToken(Anlzr.findToken());
    GlobalSettings.setAuthor(Anlzr.findAuthor());

    
    Analizer::FindIncludes FindInc;
    FindInc.findStartPoint(ReadedMikoDatas);
    FindInc.findEndPoint(ReadedMikoDatas);


    GlobalSettings.pushLibs(FindInc.findLibs(ReadedMikoDatas));



    std::cout << "----------------" << std::endl;
    std::cout << "Close program..." << std::endl;


    return 0;
}


//g++ main.cpp Analizator/CodeAnalizer.cpp Read/ReadMikoFile.cpp -o main && main