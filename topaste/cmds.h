#pragma once
#include <fstream>
#include <vector>
#include <string>
class cmd_reader{
    private:
        std::string filename = "commands.mc";
        char *prefixes;
        unsigned short prefix_count = 1;
        std::vector <std::string> commands;
        std::ifstream input; 
        void cmds_reader(){
            while(!input.eof()){
                std::string in;
                input >> in;
                commands.push_back(in);
            }
            
        }
        void prefix_reader(){
            char in = '!';
            prefixes = new char[prefix_count];
            while(in != '\n'){
                prefix_count++;
                char *copy = prefixes;
                delete [] prefixes;
                prefixes = new char[prefix_count];
                for(int i = 0; i < prefix_count-1; ++i){
                    prefixes[i] = copy[i];
                }
                prefixes[prefix_count-1] = in;
                input >> in;
            }
        }
    public:
        cmd_reader(){
            input.open(filename);
            prefix_reader();
        }
        cmd_reader(std::string filename){
            this->filename = filename;
            input.open(filename);
            prefix_reader();
        }
        ~cmd_reader(){
            delete [] prefixes;
        }
        bool is_prefix(char p){
            for(int i = 0; i < prefix_count; ++i){
                if(p = prefixes[i]) return true;
            }
            return false;
        }
        bool is_cmnd(std::string cm){
            for(int i = 0; i < commands.size(); i++){
                if(commands[i] == cm) return 1;
            }  
            return false;    
        }
        void add_cmd(std::string cmd){
            commands.push_back(cmd);
        }
};