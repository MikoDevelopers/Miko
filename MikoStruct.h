#pragma once
#include <string>
#include <map>
//#define include_foo
//#define include_lib
//#define include_var_methods

/*
#ifdef include_foo
    #include "Functions/PrintFunction/PrintFoo.h"
    #include "Functions/PrintFunction/LengthFoo.h"
    #include "Functions/PrintFunction/SizeFoo.h"
#endif

#ifdef include_lib
    #include "Libs/Math/MathLib.h"
    #include "Libs/Time/TimeLib.h"
    #include "Libs/Random/RandomLib.h"
    #include "Libs/Os_Sys/Os_SysLib.h"
    #include "Libs/Requests/RequestsLib.h"

    #include "API/Discord/DiscordApi.h"
    #include "API/Instagram/InstagramApi.h"
    #include "API/Telegram/TelegramApi.h"
    #include "API/Vk/VkApi.h"
#endif

#ifdef include_var_methods
    #include "Methods/int/IntMethods.h"
    #include "Methods/str/StrMethods.h"
    #include "Methods/bool/BoolMethods.h"
    #include "Methods/list/ListMethods.h"
    #include "Methods/float/FloatMethods.h"
#endif
*/


namespace layers_party {
    class Layer {// name, type, pos
        private:
            std::string name = "";
            std::string type = "";//class of def
            std::string MapName = name + "_" + type;//test_class of test_deg
            int pos[2]{0, 0};
        public:
    };

    class MapOfLayers {
        public:
            std::map <std::string, Layer> LayerPartyRoom;
    };
}


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
            std::map <int, bool> IEE_result;// {pos : result, 5 : true, 13 : false}
            std::map <std::string, int> PosFoo;// {"main" : 1, "add_" : 10}
            std::map <std::string, int> PosClass;// {"People" : 15}
        public:
            std::map <std::string, std::string> getVariableTypeNames(){
                return this->VariableTypeNames;
            }
            std::map <std::string, std::string> getVariableValues(){
                return this->VariableValues;
            }
            std::map <int, bool> getIEE_result(){
                return this->IEE_result;
            }
            std::map <std::string, int> getPosFoo(){
                return this->PosFoo;
            }
            std::map <std::string, int> getPosClass(){
                return this->PosClass;
            }
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