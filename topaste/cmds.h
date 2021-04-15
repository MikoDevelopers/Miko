#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#define DEBUGMODE 0
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
                if(DEBUGMODE){
                    std::cout << in << std::endl;
                }
            }
            
        }
        void prefix_reader(){
            char in = input.get();
            prefixes = new char [prefix_count];
            while(in != '\n'){
                prefixes[prefix_count-1] = in;
                char *copy = new char [prefix_count];
                for(int i = 0; i < prefix_count; i++){
                    copy[i] = prefixes[i];
                    if(DEBUGMODE) std::cout <<"copied array:"<< copy[i] << ' ' << i << '\n';
                }
                prefix_count++;
                delete[] prefixes;
                prefixes = new char [prefix_count];
                for(int i = 0; i < prefix_count-1; i++){
                    prefixes[i] = copy[i];
                    if(DEBUGMODE) std::cout << "changed array:" << prefixes[i] << ' ' << i << '\n';
                }
                in = input.get();
                if(in == ' ') in = input.get();
            }
        }
    public:
        cmd_reader(std::string filename){
            if(filename != "/default")
                this->filename = filename;
            if(DEBUGMODE) std::cout << this->filename << '\n';
            input.open(this->filename);
            prefix_reader();
            cmds_reader();
        }
        ~cmd_reader(){
            if(DEBUGMODE) std::cout << "cmd_reader destructor caller\n";
            delete [] prefixes;
        }
        cmd_reader operator=(const cmd_reader &cl){
            delete[]prefixes;
            prefixes = new char[cl.prefix_count];
            prefix_count = cl.prefix_count;
            for(int i = 0; i < prefix_count; i++){
                prefixes[i] = cl.prefixes[i];
            }
            commands = cl.commands;
        }
        void print_cmds(){
            for(int i = 0; i < commands.size(); i++){
                std::cout << "Command:" << commands[i] << std::endl;
            }
        }
        void print_prefix(){
            for(int i = 0; i < prefix_count; i++){
                std::cout << "Prefix:" << prefixes[i] << std::endl;
            }
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