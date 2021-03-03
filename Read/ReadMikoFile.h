#include <fstream>
#include <string>


std::string ReadMikoFileFunction(std::string filename)
{
    std::fstream OpenMikoFile(filename);

    std::string *numbers = new std::string;
    std::string MikoFile = "";
    std::string t = "";

    while (!OpenMikoFile.eof())
    {
        getline(OpenMikoFile, t);
        MikoFile += "\n";
        MikoFile += t;
    }

    delete numbers;

    return MikoFile;
}