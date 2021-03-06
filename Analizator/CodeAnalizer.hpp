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
    };
}