#pragma once
#include <string>
#include <map>
#include <vector>
class arr{
    private:
        std::map<std::string, char> type;
        std::map <std::string, std::vector<int>> Int;
        std::map <std::string, std::vector<bool>> Bool;
        std::map <std::string, std::vector<std::string>> Str;
        std::map <std::string, std::vector<double>> Double;
    public:
        void set_int(std::string name, std::vector <int> a){
            type[name] = 'i';
            Int[name] = a;
        }
        void set_bool(std::string name, std::vector <bool> a){
            type[name] = 'b';
            Bool[name] = a;
        }
        void set_string(std::string name, std::vector <std::string> a){
            type[name] = 's';
            Str[name] = a;
        }
         void set_double(std::string name, std::vector <double> a){
             type[name] = 'd';
            Double[name] = a;
        }
    char get_type(std::string name){
        if(type.find(name) != type.end())
            return type[name];
        return '0';
    }
    int get_int(std::string name, size_t index){
        return Int[name][index];
    }
    bool get_bool(std::string name, size_t index){
        return Bool[name][index];
    }
    double get_double(std::string name, size_t index){
        return Double[name][index];
    }
    std::string get_string (std::string name, size_t index){
        return Str[name][index];
    }
    void set_int(std::string name, int val){
        Int[name].push_back(val);
    }
    
    void set_bool(std::string name, bool val){
        Bool[name].push_back(val);
    }
    void set_string(std::string name, std::string val){
        Str[name].push_back(val);
    }
    void set_double(std::string name, double val){
        Double[name].push_back(val);
    }
    
    void create(std::string name, char type){
        std::vector<int> created_int;
        std::vector<bool> created_bool;
        std::vector<std::string> created_string;
        std::vector<double> created_double;
        switch (type){
            case 'i':
                set_int(name, created_int);
                break;
            case 'b':
               set_bool(name, created_bool);
                break;
            case 's':
                set_string(name, created_string);
                break;
            case 'd':
                set_double(name, created_double);
        }
    }
    template<class t>
    void change(std::string name, size_t index,t value){
        switch(get_type(name)){
            case 'i':
                Int[name][index] = value;
                break;
            case 'b':
                Bool[name][index] = value;
                break;
            case 's':
                Str[name][index] = value;
                break;
            case 'd':
                Double[name][index] = value;
        }
    }
    long size(std::string name){
        switch(get_type(name)){
            case 'i':
                return Int[name].size();
                break;
            case 'b':
                return Bool[name].size();
                break;
            case 's':
                return Str[name].size();
                break;
            case 'd':
                return Double[name].size();
            default:
                return -1;
                break;

        }
    }
    bool del(std::string name, unsigned long elem){
        switch(get_type(name)){
            case 'i':
                if(elem < Int[name].size()) return 0;
                Int[name].erase(Int[name].begin() + elem);
                return 1;
                break;
            case 'b':
                if(elem < Bool[name].size()) return 0;
                Bool[name].erase(Bool[name].begin() + elem);
                return 1;
                break;
            case 's':
                if(elem < Str[name].size()) return 0;
                Str[name].erase(Str[name].begin() + elem);
                return 1;
                break;
            case 'd':
                if(elem < Double[name].size()) return 0;
                Double[name].erase(Double[name].begin() + elem);
                return 1;
                break;
            default:
                return -1;
                break;

        }
    }
    bool del(std::string name){
        std::map<std::string, char>::iterator itType;
        std::map<std::string,std::vector<int>>::iterator itInt;
        std::map<std::string,std::vector<bool>>::iterator itBool;
        std::map<std::string,std::vector<double>>::iterator itDouble;
        std::map<std::string, std::vector<std::string>>::iterator itString;
        switch(get_type(name)){
            case 'i':
                itType = type.find(name);
                type.erase(itType);
                itInt = Int.find(name);
                Int.erase(itInt);
                return 1;
             case 'b':
                itType = type.find(name);
                type.erase(itType);
                itBool = Bool.find(name);
                Bool.erase(itBool);
                return 1;
             case 's':
                itType = type.find(name);
                type.erase(itType);
                itString = Str.find(name);
                Str.erase(itString);
                return 1;
            case 'd':
                itType = type.find(name);
                type.erase(itType);
                itDouble = Double.find(name);
                Double.erase(itDouble);
                return 1;
            default: return 0;
        }
    }
};