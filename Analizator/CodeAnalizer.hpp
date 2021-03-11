#pragma once
#include <string>
#include <iostream>
#include <vector>
//#include "../MikoStruct.h"


namespace Analizer {
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




                    if (this->IfDatas.find("==") != -1)
                    {
                        auto LeftIfDatas = this->IfDatas.substr(0, this->IfDatas.find("=="));
                        auto RigthIfDatas = this->IfDatas.substr(this->IfDatas.find("==") + 2, this->IfDatas.length());
                        LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                        RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                        if (LeftIfDatas == RigthIfDatas)
                        {
                            std::cout << LeftIfDatas << "  ==  " << RigthIfDatas << std::endl;
                        }
                        break;
                    }

                    if (this->IfDatas.find("!=") != -1)
                    {
                        auto LeftIfDatas = this->IfDatas.substr(0, this->IfDatas.find("!="));
                        auto RigthIfDatas = this->IfDatas.substr(this->IfDatas.find("!=") + 2, this->IfDatas.length());
                        LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                        RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                        if (LeftIfDatas != RigthIfDatas)
                        {
                            std::cout << LeftIfDatas << "  !=  " << RigthIfDatas << std::endl;
                        }
                        break;
                    }

                    if (this->IfDatas.find(">") != -1)
                    {
                        auto LeftIfDatas = this->IfDatas.substr(0, this->IfDatas.find(">"));
                        auto RigthIfDatas = this->IfDatas.substr(this->IfDatas.find(">") + 2, this->IfDatas.length());
                        LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                        RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                        if (LeftIfDatas > RigthIfDatas)
                        {
                            std::cout << LeftIfDatas << "  >  " << RigthIfDatas << std::endl;
                        }
                        break;
                    }

                    if (this->IfDatas.find("<") != -1)
                    {
                        auto LeftIfDatas = this->IfDatas.substr(0, this->IfDatas.find("<"));
                        auto RigthIfDatas = this->IfDatas.substr(this->IfDatas.find("<") + 2, this->IfDatas.length());
                        LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                        RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                        if (LeftIfDatas < RigthIfDatas)
                        {
                            std::cout << LeftIfDatas << "  <  " << RigthIfDatas << std::endl;
                        }
                        break;
                    }

                    if (this->IfDatas.find(">=") != -1)
                    {
                        auto LeftIfDatas = this->IfDatas.substr(0, this->IfDatas.find(">="));
                        auto RigthIfDatas = this->IfDatas.substr(this->IfDatas.find(">=") + 2, this->IfDatas.length());
                        LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                        RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                        if (LeftIfDatas >= RigthIfDatas)
                        {
                            std::cout << LeftIfDatas << "  >=  " << RigthIfDatas << std::endl;
                        }
                        break;
                    }

                    if (this->IfDatas.find("<=") != -1)
                    {
                        auto LeftIfDatas = this->IfDatas.substr(0, this->IfDatas.find("<="));
                        auto RigthIfDatas = this->IfDatas.substr(this->IfDatas.find("<=") + 2, this->IfDatas.length());
                        LeftIfDatas = LeftIfDatas.substr(0, LeftIfDatas.find(" "));
                        RigthIfDatas = RigthIfDatas.substr(RigthIfDatas.find(" ") + 1, RigthIfDatas.length());


                        if (LeftIfDatas <= RigthIfDatas)
                        {
                            std::cout << LeftIfDatas << "  <=  " << RigthIfDatas << std::endl;
                        }
                        break;
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

    };


    class FindFoo {

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
            void runAnalizerCycle(std::vector<std::string> &CopyVector, auto &mainMapLink)
            {
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
                        Find_IEE test;
                        test.findIEE_Foo(CopyVector, i);


                    } else if (CopyVector[i].find("elif") != -1)
                    {
                        std::cout << CopyVector[i] << std::endl;
                    } else if (CopyVector[i].find("else") != -1)
                    {
                        std::cout << CopyVector[i] << std::endl;
                    }

                }
            }
    };
}