#include "PrintFoo.h"
#include <algorithm>

template <typename PrintType>
void Print(PrintType data)
{
    std::cout << data << std::endl;
}
char get_ch(){
    return std::cin.get();
}
std::string get(){
    std::string in;
    std::cin >> in;
    return in;
}
std::string get_line(){
    std::string in;
    getline(std::cin, in);
    return in;
}
namespace algo{
    template <class T>
    void sort(T &array, unsigned int first, unsigned int last){
        std::sort(array+first, array + last);
    }
    template <class T>
    void reverse(T &array, unsigned int first, unsigned int last){
        std::reverse(array+first, array + last);
    }
    template <class T>
    void swap(T &a, T &b){
        T sw = b;
        b = a;
        a = sw;
    }
}
namespace math{
    const double PI = 3.14159265359;
    const double EILER = 2,71828;
    template <class T1, class T2>
    T1 pow (T1 num, T2 times){
        if(times == 0){
            return 1;
        }
        else if(times > 0)
        {
            T1 result = num;
            for(T2 i = 0; i < times; i++) result*=num;
            return result;
        }
        else if(times < 0)
        {
            T1 result = num;
            for(T2 i = 0; i < times; i++) result*=num;
            return 1/result;
        }
    }
    template <class T1>
    double exp (T1 num){
       return pow(EILER, num);
    }
    template <class m, clas M>
    long i_rand(m min, M max){
        return rand()%std::abs(max-min)+min;
    }
    template <class m, clas M, class p>
    double d_rand(m min, m max, p point){
        return rand()%std::abs(max-min)+min + (rand()%point)*pow(10, point);
    }
}