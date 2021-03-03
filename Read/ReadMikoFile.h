#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>


std::string ReadMikoFileFunction(std::string filename)
{
    std::fstream OpenMikoFile(filename);

    int size_of_mas = 1;
    std::vector<std::string> datas(size_of_mas);
    std::string MikoFile = "";
    std::string t = "";


    while (!OpenMikoFile.eof())
    {
        getline(OpenMikoFile, t);
        MikoFile += ("\n" + t);

        datas.push_back("\n" + t);

        size_of_mas += 1;
    }

    /*for (int i = 0; i < size_of_mas; i++)
    {
        std::cout << datas[i] << std::endl;
    }*/


    return datas;
}