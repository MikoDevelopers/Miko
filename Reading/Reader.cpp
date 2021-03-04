#include "Reader.h"

void Reader::read(std::string filename){
    using namespace std;
    ifstream in (filename);
    if(!in.is_open()){
        cout << "Can't find the file: " << filename << endl;
        
    }
}