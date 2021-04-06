#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>
#include <stdexcept>

#include "MikoStruct.h"// главный заголовойный файл
#include "Read/ReadMikoFile.h"// файл для получения исходника .miko
#include "Analizator/CodeAnalizer.hpp"// анализатор исходного кода .miko

#include "Functions/PrintFunction/PrintFoo.hpp"


//#define _debug_mode_




int main(int argc, char *argv[])
{
    #ifdef _debug_mode_
        std::cout << "Start reading...\n" << std::endl;// начало программы
    #endif
    std::vector<std::string> ReadedMikoDatas = ReadMikoFileFunction("main.miko");// получение исходного кода программы

    #ifdef _debug_mode_
        std::cout << "Datas was readed..." << std::endl;
    #endif

    Analizer::FindSettings Anlzr;
    Anlzr.findStartPoint(ReadedMikoDatas);// поиск точки начала settings
    Anlzr.findEndPoint(ReadedMikoDatas);// поиск точки конца settings
    Anlzr.appendTempDatasForWork(ReadedMikoDatas);

    #ifdef _debug_mode_
        std::cout << "Points of settings is finded...\n" << std::endl;
    #endif

    ReadedMikoDatas = Anlzr.changeReadedMikoDatas(ReadedMikoDatas);// удаление обработанных данных

    #ifdef _debug_mode_
        std::cout << "Set settings..." << std::endl;
    #endif

    settings::Setting GlobalSettings;
    GlobalSettings.setBot(Anlzr.findBot()); // установка типа бота в глобальных настройках
    GlobalSettings.setToken(Anlzr.findToken());// установка токена в глобальные настройки
    GlobalSettings.setAuthor(Anlzr.findAuthor());// установка автора в глобальные настройки

    #ifdef _debug_mode_
        std::cout << "Successfully...\n" << std::endl;
        std::cout << "Finding points of includes..." << std::endl;
    #endif

    Analizer::FindIncludes FindInc;// класс для поиска подключённых библиотек
    FindInc.findStartPoint(ReadedMikoDatas);// поиск точки начала подключённых библиотек
    FindInc.findEndPoint(ReadedMikoDatas);// поиск точки конца подключённых библиотек

    #ifdef _debug_mode_
        std::cout << "Points of includes is finded...\nLibs was includes..." << std::endl;
    #endif

    GlobalSettings.pushLibs(FindInc.findLibs(ReadedMikoDatas));// добавление подключёееых библиотек в глобальные настройки

    ReadedMikoDatas = Anlzr.changeReadedMikoDatas(ReadedMikoDatas);// удаление обработанных данных

    #ifdef _debug_mode_
        std::cout << "\n\tStart analize " << "main.miko" << " file...\n" << std::endl;
    #endif

    MainMaps::Map mainMap;          // создание объекта клсса который отвечает за словарь   
//                                     example:   ->    mainMap.getVariableValues()["a"]
    Analizer::GetAllMaps setM;
    setM.SetMaps(mainMap);

    Analizer::MainAnalizerCycle AnalizerCycle;

    layers_party::Layer __MainLayerPoint__;
    layers_party::MapOfLayers __LayersParty__;

    RESERVED_NAMES::NameSpace MainNames;

    AnalizerCycle.runAnalizerCycle(ReadedMikoDatas, mainMap, __MainLayerPoint__, __LayersParty__, MainNames);

//    std::cout <<  __LayersParty__.getLayerPartyRoom()["test_def"].getName() << std::endl;
//    std::cout <<  __LayersParty__.getLayerPartyRoom()["test2_def"].getName() << std::endl;


    #ifdef _debug_mode_
        std::cout << "----------------" << std::endl;
        std::cout << "Close program..." << std::endl;//конец программы
    #endif

//    system("pause");
    return 0;
}

//g++ main.cpp Analizator/CodeAnalizer.cpp Read/ReadMikoFile.cpp -o main && main
//x86_64-w64-mingw32-gcc -mconsole -DSIZEOF_VOID_P=8 -DMS_WIN64 lib.c -ID:\Python37\Python\include -LD:\Python37\Python\libs -lpython37 -o output
//x86_64-w64-mingw32-gcc main.cpp Analizator/CodeAnalizer.cpp Read/ReadMikoFile.cpp -mconsole -DSIZEOF_VOID_P=8 -DMS_WIN64 Python\lib.c -ID:\Python37\Python\include -LD:\Python37\Python\libs -lpython37 -o main


/*
    Flags which you can use for start programm:
        -D, --debug    ->   Start file with debug-informations

*/

//https://prom.ua/p1336780069-mikrokompyuter-raspberry-pico.html?