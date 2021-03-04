#include "vars.h"
template<typename T>
bool vars::set (std::string name, char type, T t){
    using namespace std;
    
    switch (type)
    {
    case 'i':
        types.insert(make_pair(name, 'i'));
        integer.insert(make_pair(name, t));
        return 1;
        break;
    case 'b':
        types.insert(make_pair(name, 'b'));
        boolean.insert(make_pair(name, t));
        return 1;
        break;
    case 's':
        types.insert(make_pair(name, 's'));
        str.insert(make_pair(name, t));
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

template<typename T>
T vars::get(std::string name){
    using namespace std;
    map <string, char> ::iterator it;
    it = types.find(name);
    if(it->second == 'i')
        return integer[name];
    
    else if (it->second == 'b')
        return boolean[name];
    else if(it->second == 's')
        return str[name];
    else{
        cout << "Error, invalid type of vars" << endl;
        system("pause");
        exit(1);
    }
}