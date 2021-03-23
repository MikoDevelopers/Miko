#include "StrMethods.h"


class StrMethods
{
    private:
        std::string strVariable = "";
    public:
        std::string setVar(std::string StrData)
        {
            this->strVariable = StrData;
            return this->strVariable;
        };
        std::string getVar(){return this->strVariable;};
        int len()
        {
            return this->strVariable.length();
        }
        int index(std::string findData)
        {
            return this->strVariable.find(findData);
        }
        std::string split(std::string separator)
        {
            std::string tempData = "";

            for (int i = 0; i < this->strVariable.length(); i++)
            {
                tempData += (this->strVariable[i] + separator);
            }

            return tempData.substr(0, tempData.length() - 1);
        }
        int count (std::string CData)
        {
            int countD = 0;
            std::string tempStr = this->strVariable;

            for (int index = 0; index < tempStr.length(); index++)
            {
                if (tempStr[index].find(CData) != -1)
                {
                    countD += 1;
                }

            }
            return countD;
        }
};


int main()
{
    StrMethods name;
    name.setVar("123");

    std::cout << "Get value: " <<  name.getVar() << std::endl;
    std::cout << "Len: " << name.len() << std::endl;
    std::cout << "Index: " << name.index("3") << std::endl;
    std::cout << "Split: " << name.split("|") << std::endl;
    std::cout << "Count: " << name.count("/") << std::endl;

    return 0;
}