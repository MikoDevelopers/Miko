#include "ReadMikoFile.h"

void Reader::read(std::string filename){
    using namespace std;
    fstream in(miko);
    if(!in.is_open()){
        cout << "Error, can't open file main.miko";
    }


}