#include <map>
#include <string>
#include <stdlib.h>
class vars{
    private:
        std::map <std::string, char> types;
        std::map <std::string, int> integer;
        std::map <std::string, bool> boolean;
        std::map <std::string, std::string> str;
    public:
        template <typename T>
        T get(std::string name);
        template<typename T>
        bool set(std::string name, char type, T t);
};