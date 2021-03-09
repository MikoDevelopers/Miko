#include <string>
#include <map>




namespace settings {
    class Setting {
        private:
            std::string Bot;
            std::string Token;
            std::string Author;
            std::vector<std::string> IncludesLibs;
        public:
            std::string setBot(std::string BotName)
            {
                this->Bot = BotName;

                return this->Bot;
            }
            std::string setToken(std::string TokenName)
            {
                this->Token = TokenName;

                return this->Token;
            }
            std::string setAuthor(std::string AuthorName)
            {
                this->Author = AuthorName;

                return Author;
            }
            std::vector<std::string> pushLibs(std::vector<std::string> LibVector)
            {
                this->IncludesLibs = LibVector;

                return this-> IncludesLibs;
            }




            std::string getBot()
            {
                return this->Bot;
            }
            std::string getToken()
            {
                return this->Token;
            }
            std::string getAuthor()
            {
                return Author;
            }
    };
}



namespace MainMaps {
    class Map {
        private:
            std::map <std::string, std::string> VariableTypeNames;// {"a" : "int", "b" : "str"}
            std::map <std::string, std::string> VariableValues;// {"a" : "2", "b" : "2"}
            std::map <int, bool> IEE_result;// {pos : result, 5 : true}
            std::map <std::string, int> PosFoo;// {"main" : 1, "add_" : 10}
            std::map <std::string, int> PosClass;// {"People" : 15}
        public:
            std::map <std::string, std::string> getVariableTypeNames(){return this->VariableTypeNames;}
            std::map <std::string, std::string> getVariableValues(){return this->VariableValues;}
            /*std::map <std::string, std::string> getMap(std::string NameOfMap)
            {
                if (NameOfMap == "VariableTypeNames")
                {
                    return this->VariableTypeNames;
                } else if (NameOfMap == "VariableValues")
                {
                    return this->VariableValues;
                } else if (NameOfMap == "IEE_result")
                {
                    return this->IEE_result;
                } else if (NameOfMap == "PosFoo")
                {
                    return this->PosFoo;
                } else if (NameOfMap == "PosClass")
                {
                    return this->PosClass;
                } else {
                    std::map <std::string, std::string> error;
                    return error;
                }
                return this->VariableTypeNames;
            }
            */



            void uppdateMaps(std::string NameOfVariable, std::string TypeOfVariable, std::string ValueOfVariable)
            {
                this->VariableTypeNames[NameOfVariable] = TypeOfVariable;
                this->VariableValues[NameOfVariable] = ValueOfVariable;
            }
    };
}







namespace var {
    const std::string ALL_TYPES[6] = {"int", "str", "float", "bool", "list", "dict"};

    std::string int_(std::string int_data)
    {
        const std::string INT = "int ";
        int_data = int_data.substr(INT.length(), int_data.length());

        return int_data;
    }
    std::string str_(std::string str_data)
    {
        const std::string STR = "str ";
        str_data = str_data.substr(STR.length(), str_data.length());

        return str_data;
    }
    std::string float_(std::string float_data)
    {
        const std::string FLOAT = "float ";
        float_data = float_data.substr(FLOAT.length(), float_data.length());

        return float_data;
    }
    std::string bool_(std::string bool_data)
    {
        const std::string BOOL = "bool ";
        bool_data = bool_data.substr(BOOL.length(), bool_data.length());

        return bool_data;
    }/*
    std::string list_()
    {
        
    }
    std::string dict_()
    {
        
    }*/
}

namespace math_operators {
    const std::string ALL_OPERATIONS[13] = {
        "+", "-", "*", "/", "//", "%","**",
        "++", "--", ">", "<", ">=", "<="
        };
}

namespace cycles {
    const std::string ALL_CYCLES[3] = {"while", "while/do", "for"};
}

namespace IEE_constr {
    const std::string IEE_CONSTR[3] = {"if", "elif", "else"};
}

namespace home_f{
    const std::string HOME_FUNCTIONS[] = {"print_", "input_"};

    std::string print_(std::string data)
    {
        return data;
    }
}