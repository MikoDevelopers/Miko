#include "ReadMikoFile.h"



//std::string *ReadMikoFileFunction(std::string filename)
std::vector<std::string> ReadMikoFileFunction(std::string filename)
{
    std::fstream OpenMikoFile(filename);

    std::vector<std::string> datas = {};
    std::string MikoFile = "";
    std::string t = "";

    int step = 1;
    while (!OpenMikoFile.eof())
    {
        getline(OpenMikoFile, t);
        MikoFile += ("\n" + t);

        datas.push_back("\n" + t);
    }

    return datas;
}