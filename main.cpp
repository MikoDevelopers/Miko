#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

//#include <D:\Python37\Python\include\Python.h>

#include "Python/lib.h"


#include "MikoStruct.h"// главный заголовойный файл
#include "Read/ReadMikoFile.h"// файл для получения исходника .miko
//#include "Functions/PrintFunction/PrintFoo.h"

#include "Analizator/CodeAnalizer.hpp"// анализатор исходного кода .miko





int main(int argc, char *argv[])
{
    std::cout << "Start reading...\n" << std::endl;// начало программы
    std::vector<std::string> ReadedMikoDatas = ReadMikoFileFunction("main.miko");// получение исходного кода программы

    std::cout << "Datas was readed..." << std::endl;

    Analizer::FindSettings Anlzr;
    Anlzr.findStartPoint(ReadedMikoDatas);// поиск точки начала settings
    Anlzr.findEndPoint(ReadedMikoDatas);// поиск точки конца settings
    Anlzr.appendTempDatasForWork(ReadedMikoDatas);

    std::cout << "Points of settings is finded...\n" << std::endl;

    ReadedMikoDatas = Anlzr.changeReadedMikoDatas(ReadedMikoDatas);// удаление обработанных данных

    std::cout << "Set settings..." << std::endl;

    settings::Setting GlobalSettings;
    GlobalSettings.setBot(Anlzr.findBot()); // установка типа бота в глобальных настройках
    GlobalSettings.setToken(Anlzr.findToken());// установка токена в глобальные настройки
    GlobalSettings.setAuthor(Anlzr.findAuthor());// установка автора в глобальные настройки

    std::cout << "Successfully...\n" << std::endl;

    std::cout << "Finding points of includes..." << std::endl;
    Analizer::FindIncludes FindInc;// класс для поиска подключённых библиотек
    FindInc.findStartPoint(ReadedMikoDatas);// поиск точки начала подключённых библиотек
    FindInc.findEndPoint(ReadedMikoDatas);// поиск точки конца подключённых библиотек

    std::cout << "Points of includes is finded...\nLibs was includes..." << std::endl;

    GlobalSettings.pushLibs(FindInc.findLibs(ReadedMikoDatas));// добавление подключёееых библиотек в глобальные настройки

    ReadedMikoDatas = Anlzr.changeReadedMikoDatas(ReadedMikoDatas);// удаление обработанных данных

    std::cout << "\n\tStart analize " << "main.miko" << " file...\n" << std::endl;

    
    MainMaps::Map mainMap;// создание объекта клсса который отвечает за словарь   
    //example:   ->    mainMap.getVariableValues()["a"]
    

    Analizer::MainAnalizerCycle AnalizerCycle;
    //MainMaps::Map *LinkOfMap = new MainMaps::Map;

//    std::cout << typeid(Analizer::returnMap(mainMap)).name() << std::endl;

    AnalizerCycle.runAnalizerCycle(ReadedMikoDatas, mainMap);






    std::cout << "----------------" << std::endl;
    std::cout << "Close program..." << std::endl;//конец программы




    return 0;
}


//g++ main.cpp Analizator/CodeAnalizer.cpp Read/ReadMikoFile.cpp -o main && main
//x86_64-w64-mingw32-gcc -mconsole -DSIZEOF_VOID_P=8 -DMS_WIN64 lib.c -ID:\Python37\Python\include -LD:\Python37\Python\libs -lpython37 -o output

//x86_64-w64-mingw32-gcc main.cpp Analizator/CodeAnalizer.cpp Read/ReadMikoFile.cpp -mconsole -DSIZEOF_VOID_P=8 -DMS_WIN64 Python\lib.c -ID:\Python37\Python\include -LD:\Python37\Python\libs -lpython37 -o main