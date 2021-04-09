#pragma once
#include <string>
#include <map>
#include <vector>


namespace RESERVED_NAMES {
    class NameSpace {
        public:
            std::string KEY_WORDS [25] = {
                "int", "str", "float", "bool", "list", // type of data
                "if", "elif", "else",                  // IEE constuction
                "for", "while",                        // cycles 
                ":def", ":class",                      // classes and functions
                "return", "try", "except", "raise",    // other key words
                "break", "continue",
                "in", "and", "or", "not", "not in", "is", "is not"
            };
            std::string KEY_FUNCTION_NAME [8] = {
                "print", "input", "open", "len",
                "to_int", "to_str", "to_list", "to_float"
            };
    };
}



namespace layers_party {
    class Layer {// name, type, pos
        private:
            std::string name = "";
            std::string type = "";//class of def
            std::string MapName = name + "_" + type;//test_class of test_deg
            std::vector<std::string> PatentsOfLayer;
            std::map <std::string, std::string> LayerVariableTypeNames;
            std::map <std::string, std::string> LayerVariableValues;
            std::vector<int> pos;
        public:
            void combineVariables(
                std::map <std::string, std::string> &VariableTypeNames,
                std::map <std::string, std::string> &VariableValues)
            {
                std::swap(this->LayerVariableTypeNames, VariableTypeNames);
                this->LayerVariableTypeNames.insert(VariableTypeNames.begin(), VariableTypeNames.end());

                std::swap(this->LayerVariableValues, VariableValues);
                this->LayerVariableValues.insert(VariableValues.begin(), VariableValues.end());
            }

            void setAttributes(
                std::string name_, std::string type_, std::string MapName_,
                std::vector<std::string> PatentsOfLayer_,
                std::map <std::string, std::string> LayerVariableTypeNames_,
                std::map <std::string, std::string> LayerVariableValues_,
                std::vector<int> pos_
            )
            {
                this->name = name_;
                this->type = type_;
                this->MapName = MapName_;
                this->PatentsOfLayer = PatentsOfLayer_;
                this->LayerVariableTypeNames = LayerVariableTypeNames_;
                this->LayerVariableValues = LayerVariableValues_;
                this->pos = pos_;
            }

            std::string getName(){return this->name;}
            std::string getType(){return this->type;}
            std::string getMapName(){return this->MapName;}
            std::vector<std::string> getPatentsOfLayer(){return this->PatentsOfLayer;}
            std::map <std::string, std::string> getLayerVariableTypeNames(){return this->LayerVariableTypeNames;}
            std::map <std::string, std::string> getLayerVariableValues(){return this->LayerVariableValues;}
            std::vector<int> getPos(){return this->pos;}
    };

    class MapOfLayers {
        private:
            std::map <std::string, Layer> LayerPartyRoom;
        public:
            template <class L>
            void launchParty(L __Lr_Data__)
            {
                this->LayerPartyRoom[__Lr_Data__.getMapName()] = __Lr_Data__;
            }

            std::map <std::string, Layer> getLayerPartyRoom(){return this->LayerPartyRoom;}
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




namespace spelling{
    class Lexer {

    };
}