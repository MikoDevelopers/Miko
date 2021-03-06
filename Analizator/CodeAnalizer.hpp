#pragma once
#include <string>
#include <iostream>
#include <vector>



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
                    }
                }

                for (int i = 0; i <= 4; i++)
                {
                    if (findedBotStr.find(masApi[i]) != -1)
                    {
                        return masApi[i];
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
                    }
                }

                findedTokenStr = findedTokenStr.substr(findedTokenStr.find("\""), findedTokenStr.find(","));
                findedTokenStr = findedTokenStr.substr(findedTokenStr.find("\""), findedTokenStr.find(" "));
                findedTokenStr = findedTokenStr.substr(findedTokenStr.find("\""), findedTokenStr.find(","));

                for (int i = 1; i < findedTokenStr.length() - 1; i++)
                {
                    returnTokenStr += findedTokenStr[i];
                }

                return returnTokenStr;
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
                    }
                }

                findedAuthorStr = findedAuthorStr.substr(findedAuthorStr.find("\""), findedAuthorStr.find(","));
                findedAuthorStr = findedAuthorStr.substr(findedAuthorStr.find("\""), findedAuthorStr.find(" "));
                findedAuthorStr = findedAuthorStr.substr(findedAuthorStr.find("\""), findedAuthorStr.find(","));

                for (int i = 1; i < findedAuthorStr.length() - 1; i++)
                {
                    returnAuthorStr += findedAuthorStr[i];
                }

                return returnAuthorStr;
            }

            std::vector<std::string> changeReadedMikoDatas(std::vector<std::string> must_be_changed__ReadedMikoDatas)
            {
                std::vector<std::string> New_Vector;


                for (int i = this->end_of_settings + 1; i <= must_be_changed__ReadedMikoDatas.size() - (this->end_of_settings - this->start_of_settings); i++)
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
            
    };
}