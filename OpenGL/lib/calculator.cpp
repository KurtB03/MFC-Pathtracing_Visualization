#include "calculator.hpp"

namespace calc{

    std::vector<term> split(std::string s){
        std::vector<term> result;

        return result;
    }

    double calc(std::string s){
        std::vector<term> parts = split(s);
        double result = 0;

        for (auto i : parts){
            result += eval(i);
        }

        return result;
    }

    double eval(term t){
        return -1;
    }

    double strToDouble(std::string){
        return -1;
    }
}