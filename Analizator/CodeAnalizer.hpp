#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
//#include "../MikoStruct.h"
//#define DEBUG true




namespace Analizer {
    class GetAllMaps {
        public:
            std::map <std::string, std::string> VariableTypeNames;// {"a" : "int", "b" : "str"}
            std::map <std::string, std::string> VariableValues;// {"a" : "2", "b" : "2"}
            std::map <int, bool> IEE_result;// {pos : result, 5 : true, 13 : false}
            std::map <std::string, int> PosFoo;// {"main" : 1, "add_" : 10}
            std::map <std::string, int> PosClass;// {"People" : 15}
        //public:
            template <class T>
            void SetMaps(T TestMap)
            {
                #ifdef DEBUG
                    std::cout << "GetAllMaps is runing..." << std::endl;
                #endif
                this->VariableTypeNames = TestMap.getVariableTypeNames();
                this->VariableValues = TestMap.getVariableValues();
                this->IEE_result = TestMap.getIEE_result();
                this->PosFoo = TestMap.getPosFoo();
                this->PosClass = TestMap.getPosClass();
                #ifdef DEBUG
                    std::cout << "GetAllMaps is finished..." << std::endl;
                #endif
            }
            void prinT()
            {
                std::cout << "Print" << std::endl;
            }
    };


    class RerFoo{
        public:
            void ReturnTrueOrFalse(std::string IfDatas)
            {
                
                if (IfDatas.find("==") != -1)
                {
                    auto LeftIfDatas = IfDatas.substr(0, IfDatas.find("=="));
                    auto RigthIfDatas = IfDatas.substr(IfDatas.find("==") + 2, IfDatas.length());
                    LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                    RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                    //std::cout << GetAllMaps.VariableTypeNames << std::endl;
                    /*if (LeftIfDatas == RigthIfDatas)
                    {
                        std::cout << LeftIfDatas << "  ==  " << RigthIfDatas << std::endl;
                    }*/
                }

                if (IfDatas.find("!=") != -1)
                {
                    auto LeftIfDatas = IfDatas.substr(0, IfDatas.find("!="));
                    auto RigthIfDatas = IfDatas.substr(IfDatas.find("!=") + 2, IfDatas.length());
                    LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                    RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                    if (LeftIfDatas != RigthIfDatas)
                    {
                        std::cout << LeftIfDatas << "  !=  " << RigthIfDatas << std::endl;
                    }
                }

                if (IfDatas.find(">") != -1)
                {
                    auto LeftIfDatas = IfDatas.substr(0, IfDatas.find(">"));
                    auto RigthIfDatas = IfDatas.substr(IfDatas.find(">") + 2, IfDatas.length());
                    LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                    RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                    if (LeftIfDatas > RigthIfDatas)
                    {
                        std::cout << LeftIfDatas << "  >  " << RigthIfDatas << std::endl;
                    }
                }

                if (IfDatas.find("<") != -1)
                {
                    auto LeftIfDatas = IfDatas.substr(0, IfDatas.find("<"));
                    auto RigthIfDatas = IfDatas.substr(IfDatas.find("<") + 2, IfDatas.length());
                    LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                    RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                    if (LeftIfDatas < RigthIfDatas)
                    {
                        std::cout << LeftIfDatas << "  <  " << RigthIfDatas << std::endl;
                    }
                }

                if (IfDatas.find(">=") != -1)
                {
                    auto LeftIfDatas = IfDatas.substr(0, IfDatas.find(">="));
                    auto RigthIfDatas = IfDatas.substr(IfDatas.find(">=") + 2, IfDatas.length());
                    LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                    RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                    if (LeftIfDatas >= RigthIfDatas)
                    {
                        std::cout << LeftIfDatas << "  >=  " << RigthIfDatas << std::endl;
                    }
                }

                if (IfDatas.find("<=") != -1)
                {
                    auto LeftIfDatas = IfDatas.substr(0, IfDatas.find("<="));
                    auto RigthIfDatas = IfDatas.substr(IfDatas.find("<=") + 2, IfDatas.length());
                    LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                    RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                    if (LeftIfDatas <= RigthIfDatas)
                    {
                        std::cout << LeftIfDatas << "  <=  " << RigthIfDatas << std::endl;
                    }
                }
            }
    };


    class FindSettings {
        private:
            int start_of_settings;
            int end_of_settings;
        public:
            std::vector<std::string> TempDatasForWork;

            int findStartPoint(std::vector<std::string> AcceptedDatas)
            {
                int t;
                for (int i = 0; i < AcceptedDatas.size(); i++)
                {
                    std::string tempData = AcceptedDatas[i];
                    std::string find = "settings";

                    t = tempData.find(find);
                    if (t != -1)
                    {
                        this->start_of_settings = i;
            
                        break;
                    }
                }
                return this->start_of_settings;
            }

            int findEndPoint(std::vector<std::string> AcceptedDatas)
            {
                int fep;
                for (int e = 0; e < AcceptedDatas.size(); e++)
                {
                    std::string tempData = AcceptedDatas[e];
                    std::string findEnd = ")";

                    fep = tempData.find(findEnd);
                    if (fep != -1)
                    {
                        this->end_of_settings = e;

                        break;
                    }
                }
                return this->end_of_settings;
            }

            void appendTempDatasForWork(std::vector<std::string> AcceptedDatas)
            {
                for (int i = this->start_of_settings; i <= this->end_of_settings; i++)
                {
                    TempDatasForWork.push_back(AcceptedDatas[i]);
                }
            }



            int getStartPoint()
            {
                return this->start_of_settings;
            }
            int getEndPoint()
            {
                return this->end_of_settings;
            }



            std::string findBot()
            {
                std::string findBotStr = "Bot";
                std::string findedBotStr = "";
                std::string masApi[4]{"Telegram", "Discord", "Instagram", "Vk"};
                
                for (int i = 0; i <= TempDatasForWork.size(); i++)
                {
                    int tempBot = TempDatasForWork[i].find(findBotStr);

                    if (tempBot != -1)
                    {
                        findedBotStr += TempDatasForWork[i].substr(TempDatasForWork[i].find(":"), TempDatasForWork[i].find(","));

                        for (int i = 0; i <= 4; i++)
                        {
                            if (findedBotStr.find(masApi[i]) != -1)
                            {
                                return masApi[i];
                            }
                        }
                    }
                }
                return "";
            }

            std::string findToken()
            {
                std::string findTokenStr = "Token";
                std::string findedTokenStr = "";
                std::string returnTokenStr = "";

                for (int i = 0; i <= TempDatasForWork.size(); i++)
                {
                    int tempToken = TempDatasForWork[i].find(findTokenStr);

                    if (tempToken != -1)
                    {
                        findedTokenStr += TempDatasForWork[i].substr(TempDatasForWork[i].find(":"), TempDatasForWork[i].find(","));
                        findedTokenStr = findedTokenStr.substr(findedTokenStr.find("\""), findedTokenStr.find(","));
                        findedTokenStr = findedTokenStr.substr(findedTokenStr.find("\""), findedTokenStr.find(" "));
                        findedTokenStr = findedTokenStr.substr(findedTokenStr.find("\""), findedTokenStr.find(","));

                        for (int i = 1; i < findedTokenStr.length() - 1; i++)
                        {
                            returnTokenStr += findedTokenStr[i];
                        }

                        return returnTokenStr;
                    }
                }
               return "";
            }


            std::string findAuthor()
            {
                std::string findAuthorStr = "Author";
                std::string findedAuthorStr = "";
                std::string returnAuthorStr = "";

                for (int i = 0; i <= TempDatasForWork.size(); i++)
                {
                    int tempAuthor = TempDatasForWork[i].find(findAuthorStr);

                    if (tempAuthor != -1)
                    {
                        findedAuthorStr += TempDatasForWork[i].substr(TempDatasForWork[i].find(":"), TempDatasForWork[i].length());
                        findedAuthorStr = findedAuthorStr.substr(findedAuthorStr.find("\""), findedAuthorStr.find(","));
                        findedAuthorStr = findedAuthorStr.substr(findedAuthorStr.find("\""), findedAuthorStr.find(" "));
                        findedAuthorStr = findedAuthorStr.substr(findedAuthorStr.find("\""), findedAuthorStr.find(","));

                        for (int i = 1; i < findedAuthorStr.length() - 1; i++)
                        {
                            returnAuthorStr += findedAuthorStr[i];
                        }

                        return returnAuthorStr;
                    }
                }
                return "";
            }

            std::vector<std::string> changeReadedMikoDatas(std::vector<std::string> must_be_changed__ReadedMikoDatas)
            {
                std::vector<std::string> New_Vector;

                for (int i = this->end_of_settings + 1; i < must_be_changed__ReadedMikoDatas.size(); i++)
                {
                    New_Vector.push_back(must_be_changed__ReadedMikoDatas[i]);
                }

                return New_Vector;
            }
    };


    class FindIncludes {
        private:
            int start_include_point;
            int end_include_point;
        public:
            std::vector<std::string> IncludesLibsVector;

            int findStartPoint(std::vector<std::string> AcceptedDatas)
            {
                int temp;
                for (int i = 0; i < AcceptedDatas.size(); i++)
                {
                    std::string tempData = AcceptedDatas[i];
                    std::string find = "include";

                    temp = tempData.find(find);
                    if (temp != -1)
                    {
                        this->start_include_point = i;
            
                        return this->start_include_point;
                    }
                }
                return this->start_include_point;
            }

            int findEndPoint(std::vector<std::string> AcceptedDatas)
            {
                int fep;
                for (int e = 0; e < AcceptedDatas.size(); e++)
                {
                    std::string tempData = AcceptedDatas[e];
                    std::string findEnd = ")";

                    fep = tempData.find(findEnd);
                    if (fep != -1)
                    {
                        this->end_include_point = e;

                        return this->end_include_point;
                    }
                }
                return this->end_include_point;
            }


            std::vector<std::string> findLibs(std::vector<std::string> AcceptedDatas)
            {
                for (int i = this->start_include_point + 1; i < this->end_include_point; i++)
                {
                    std::string tempLibData = "";
                    tempLibData = AcceptedDatas[i].substr(AcceptedDatas[i].find("\""), AcceptedDatas[i].find(","));
                    tempLibData = tempLibData.substr(tempLibData.find("\""), tempLibData.find(","));
                    tempLibData = tempLibData.substr(tempLibData.find("\"") + 1, tempLibData.length() - 2);
                    
                    this->IncludesLibsVector.push_back(tempLibData);
                }

                return this->IncludesLibsVector;
            }


            std::vector<std::string> changeReadedMikoDatas(std::vector<std::string> must_be_changed__ReadedMikoDatas)
            {
                std::vector<std::string> New_Vector;


                for (int i = this->end_include_point; i < must_be_changed__ReadedMikoDatas.size(); i++)
                {
                    New_Vector.push_back(must_be_changed__ReadedMikoDatas[i]);
                }

                return New_Vector;
            }
    };


    class Find_IEE {//if elif else
        private:
            int startPoint;
            int endPoint;

            bool DataIsFinded = false;
            int if_data_start;
            int if_data_end;
            std::string IfDatas = "";
            bool IfDatasIsFull = false;
        public:
            int findIEE_Foo(std::vector<std::string> &Datas, int &PositionOfDatas)
            {
                for (int i = PositionOfDatas; i < Datas.size(); i++)
                {
                    if (this->DataIsFinded != true)
                    {
                        if (Datas[i].find("(") != -1)
                        {
                            this->if_data_start = Datas[i].find("(");
                        }
                        if (Datas[i].find(")") != -1)
                        {
                            this->if_data_end = Datas[i].find(")");
                            this->DataIsFinded = true;
                        }
                    }
                    if (this->DataIsFinded && this->IfDatasIsFull != true)
                    {
                        for (int DataInfoPos = this->if_data_start + 1; DataInfoPos < this->if_data_end; DataInfoPos++)
                        {
                            this->IfDatas += Datas[i][DataInfoPos];
                        }
                        this->IfDatasIsFull = true;
                    }

                    if (
                        (this->IfDatas.find("==") != -1) || (this->IfDatas.find("!=") != -1) ||
                        (this->IfDatas.find(">") != -1) || (this->IfDatas.find("<") != -1) ||
                        (this->IfDatas.find("<=") != -1) || (this->IfDatas.find(">=") != -1)
                    )
                    {
                        RerFoo run_check_foo;
                        run_check_foo.ReturnTrueOrFalse(IfDatas);
                    }


                    /*if (Datas[i].find("{") != -1)
                    {
                        this->startPoint = i;
                    } else if (Datas[i].find("}") != -1)
                    {
                        this->endPoint = i;
                    }*/


                    return_back();// возврат значений по умолчанию
                }


                return PositionOfDatas;
            }

            void return_back()
            {
                this->startPoint = 0;
                this->endPoint = 0;

                this->DataIsFinded = false;
                this->if_data_start = 0;
                this->if_data_end = 0;
                this->IfDatas = "";
                this->IfDatasIsFull = false;
            }
    };


    class FindCycles {
        private:
            int pos_of_start_condition_ = 0;
            int pos_of_end_condition_ = 0;

            int pos_of_start_BodyCycle_ = 0;
            int pos_of_end_BodyCycle_ = 0;

            bool result_of_condition = false;
        public:
            void findPosOfCondition(std::vector<std::string> &Datas, int &PositionOfDatas)
            {
                this->pos_of_start_condition_ = Datas[PositionOfDatas].find("(") + 1;
                this->pos_of_end_condition_ = Datas[PositionOfDatas].find(")") - 1;

                std::cout << Datas[PositionOfDatas][this->pos_of_start_condition_] << std::endl;
                std::cout << Datas[PositionOfDatas][this->pos_of_end_condition_] << std::endl;

            }
    };


    class FindFoo {
       private:
            int start_placeArgs = 0;
            int end_placeArgs = 0;

            bool first_is_find = false;
            int start_bodyFunc = 0;
            int end_bodyFunc = 0;
            std::string FuncName = "";
            
            int number_of_start = 0;
            int number_of_end = 0;

            std::map <std::string, std::string> InsideVariableTypeNames;
            std::map <std::string, std::string> InsideVariableValues;
        public:
            template <class T, class Y>
            void FindFoo_(std::vector<std::string> &Datas, int &PositionOfDatas, T &LayersPpartyLink, Y &L_Map)
            {
                //std::cout << Datas[PositionOfDatas] << std::endl;
                this->start_placeArgs = Datas[PositionOfDatas].find("(") + 1;   //get start point for args in function
                this->end_placeArgs = Datas[PositionOfDatas].find(")") - 1;     //get end point for args in function

                this->FuncName = Datas[PositionOfDatas].substr(                         //get name of function
                    Datas[PositionOfDatas].find(":def") + 5,
                    Datas[PositionOfDatas].find("(")
                    );
                this->FuncName = this->FuncName.substr(0, this->FuncName.find("("));


                for (int i = PositionOfDatas; i < Datas.size(); i++)
                {
                    //std::cout << Datas[i] << std::endl;
                    if (i == PositionOfDatas)
                    {
                        if ((Datas[i].find("{") != -1))
                        {
                            this->number_of_start += 1;
                            
                            if (!this->first_is_find)
                            {
                                this->start_bodyFunc = i;
                                this->first_is_find = true;
                            }

                        } else if (Datas[i].find("}") != -1)
                        {
                            this->number_of_end += 1;
                        }
                    } else {
                        if (Datas[i].find("{") != -1)
                        {
                            this->number_of_start += 1;

                            if (!this->first_is_find)
                            {
                                this->start_bodyFunc = i;
                                this->first_is_find = true;
                            }
                        } else if (Datas[i].find("}") != -1)
                        {
                            this->number_of_end += 1;
                        }


                        if (this->number_of_start == this->number_of_end)     // if values is ... break
                        {
                            this->end_bodyFunc = i;
                            //std::cout << i << std::endl;
                            break;
                        }
                    }
                }

                //std::cout << this->number_of_start << " " << this->number_of_end << std::endl;
                //std::cout << this->start_bodyFunc << " body " << this->end_bodyFunc << std::endl;
                //std::cout << this->FuncName << std::endl;

                updateArgs(Datas, PositionOfDatas, LayersPpartyLink, L_Map);
            }

            template <class T, class Y>
            void updateArgs(std::vector<std::string> &Datas, int &PositionOfDatas, T &LayersPpartyLink, Y &L_Map)//std::string NameOfVariable, std::string TypeOfVariable, std::string ValueOfVariable
            {
                std::string tempArgsData = "";
                std::string tempData__ = "";

                for (int i = this->start_placeArgs; i < Datas[PositionOfDatas].length(); i++)
                {
                    tempArgsData += Datas[PositionOfDatas][i];
                }

                for (int i = 0; i < this->end_placeArgs; i++)
                {
                    //int a, int b, str "123"
                    tempData__ = tempArgsData.substr(0, tempArgsData.find(","));
                    std::string var_type = tempData__.substr(0, tempData__.find(" "));
                    std::string var_value = tempData__.substr(tempData__.find(" "), tempData__.length());

//                    var_type.replace(var_type.find(" "), 1, "");
                    var_value.replace(var_value.find(" "), 1, "");
                    if (var_type.length() == 0)
                    {
                        var_type = var_value.substr(0, var_value.find(" "));
                        var_value = var_value.substr(var_value.find(" ") + 1, var_value.find(")"));
                        var_value = var_value.substr(0, var_value.find(")"));
                    }

                    this->InsideVariableTypeNames[var_value] = var_type;
                    this->InsideVariableValues[var_value] = "None";
    
//                    std::cout << var_type << " " << var_type.length() << "    " << var_value << " " << var_value.length() << std::endl;

                    tempArgsData = tempArgsData.substr(tempArgsData.find(",") + 1, tempArgsData.length());
                }

                pushLayerIntoParty(Datas, PositionOfDatas, LayersPpartyLink, L_Map);
            }

/*
    *        std::string name = "";
    *        std::string type = "";//class of def
    *        std::string MapName = name + "_" + type;//test_class of test_deg
            std::vector<std::string> PatentsOfLayer;
    *        std::map <std::string, std::string> LayerVariableTypeNames;
    *        std::map <std::string, std::string> LayerVariableValues;
    *        int pos[2]{0, 0};*/
            template <class LayerType, class LMap>
            void pushLayerIntoParty(std::vector<std::string> &Datas, int &PositionOfDatas, LayerType &LayersPpartyLink, LMap &L_Map)
            {
                std::string MapNameStr = this->FuncName + "_" + "def";
                std::vector<std::string> PatentsOfLayer;
                PatentsOfLayer.push_back("None");
                
                std::vector<int> pos;//[2];
                pos.push_back(this->start_bodyFunc);
                pos.push_back(this->end_bodyFunc);
                

                LayerType layerObject;

                layerObject.setAttributes(
                    FuncName, "def", MapNameStr, PatentsOfLayer,
                    InsideVariableTypeNames, InsideVariableValues, pos
                );

                L_Map.launchParty(layerObject);
            }
    };


    class FindClass {

    };


    class MainAnalizerCycle {
        private:
            std::vector<std::string> MainVector;
        public:
            std::vector<std::string> getMainVector()
            {
                return this->MainVector;
            }
            template <class Map, class Layer, class LMap>
            void runAnalizerCycle(std::vector<std::string> &CopyVector, Map &mainMapLink, Layer &Lay, LMap &LayersPartyLink) // start analizer
            {
                // check all key words in miko-file
                for (int i = 0; i < CopyVector.size(); i++)
                {
                    if ((CopyVector[i].find("int ") != -1))
                    {
                        std::string variableData = CopyVector[i].substr(CopyVector[i].find("int ") + 4, CopyVector[i].length());
                        
                        std::string name = variableData.substr(0, variableData.find("=")).substr(0, variableData.substr(0, variableData.find("=")).find(" "));

                        std::string Fvalue = variableData.substr(variableData.find("=") + 1, variableData.length());
                        std::string value = Fvalue.substr(Fvalue.find(" ") + 1, Fvalue.find(";") - 1);


                        mainMapLink.uppdateMaps(name, "int", value);


                    } else if (CopyVector[i].find("str ") != -1)
                    {
                        std::string variableData = CopyVector[i].substr(CopyVector[i].find("str ") + 4, CopyVector[i].length());
                        
                        std::string name = variableData.substr(0, variableData.find("=")).substr(0, variableData.substr(0, variableData.find("=")).find(" "));
                        
                        std::string Fvalue = variableData.substr(variableData.find("=") + 1, variableData.length());
                        std::string value = Fvalue.substr(Fvalue.find(" ") + 1, Fvalue.find(";") - 1);
                        value = value.substr(1, value.length() - 2);


                        mainMapLink.uppdateMaps(name, "str", value);
                        

                    } else if (CopyVector[i].find("float ") != -1)
                    {
                        std::string variableData = CopyVector[i].substr(CopyVector[i].find("float ") + 6, CopyVector[i].length());
                        
                        std::string name = variableData.substr(0, variableData.find("=")).substr(0, variableData.substr(0, variableData.find("=")).find(" "));
                        
                        std::string Fvalue = variableData.substr(variableData.find("=") + 1, variableData.length());
                        std::string value = Fvalue.substr(Fvalue.find(" ") + 1, Fvalue.find(";") - 1);

                        mainMapLink.uppdateMaps(name, "float", value);

                    } else if (CopyVector[i].find("list ") != -1)
                    {
                        std::string variableData = CopyVector[i].substr(CopyVector[i].find("list ") + 5, CopyVector[i].length());
                        
                        std::string name = variableData.substr(0, variableData.find("=")).substr(0, variableData.substr(0, variableData.find("=")).find(" "));
                        
                        std::string Fvalue = variableData.substr(variableData.find("=") + 1, variableData.length());
                        std::string value = Fvalue.substr(Fvalue.find(" ") + 1, Fvalue.find(";") - 1);
                        

                        mainMapLink.uppdateMaps(name, "list", value);
                     
                    } else if (CopyVector[i].find("typle ") != -1)
                    {
                        std::string variableData = CopyVector[i].substr(CopyVector[i].find("typle ") + 6, CopyVector[i].length());
                        
                        std::string name = variableData.substr(0, variableData.find("=")).substr(0, variableData.substr(0, variableData.find("=")).find(" "));
                        
                        std::string Fvalue = variableData.substr(variableData.find("=") + 1, variableData.length());
                        std::string value = Fvalue.substr(Fvalue.find(" ") + 1, Fvalue.find(";") - 1);
                        

                        mainMapLink.uppdateMaps(name, "typle", value);
                    }



                    if (CopyVector[i].find("if") != -1)
                    {
                        Find_IEE start_iee;
                        start_iee.findIEE_Foo(CopyVector, i);
                    }
                    /*} else if (CopyVector[i].find("elif") != -1)
                    {
                        std::cout << CopyVector[i] << std::endl;
                    } else if (CopyVector[i].find("else") != -1)
                    {
                        std::cout << CopyVector[i] << std::endl;
                    }*/


                    if ((CopyVector[i].find("for (") != -1) || (CopyVector[i].find("for(") != -1))
                    {
                        FindCycles start_cycle;
                        start_cycle.findPosOfCondition(CopyVector, i);
                    }


                    if (((CopyVector[i].find(":def") != -1) || (CopyVector[i].find(":def ") != -1)) &&
                        (CopyVector[i].find("(") != -1) &&
                        (CopyVector[i].find(")") != -1))
                    {
                        FindFoo findFoo__start;
                        findFoo__start.FindFoo_(CopyVector, i, Lay, LayersPartyLink);
                        //findFoo__start.updateArgs();
                    }

                }
            }


            void runCode(std::vector<std::string> &CopyVector) // run miko-file, get all information after runAnalizerCycle()
            {

            }
    };
}