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
    public:
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
    
    template <class ar>
    void set(std::string name, std::vector <ar> arr){
        ar type;
        switch (sizeof(ar)){
            case sizeof(int):
                this->type[name] = 'i';
                Int[name] = arr;
                break;
            case sizeof(bool):
                this->type[name] = 'b';
                Bool[name] = arr;
                break;
            case sizeof(std::string)
                this->type[name] = 's';
                Str[name] = arr;
                break;
        }
    }
    void create(std::string name, char type){
        std::vector<int> created_int;
        std::vector<bool> created_bool;
        std::vector<std::string> created_string;
        switch (type){
            case 'i':
                set(name, created_int);
                break;
            case 'b':
               set(name, created_bool);
                break;
            case 's':
                set(name, created_string);
                break;
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
            default:
                return -1;
                break;

        }
    }
};