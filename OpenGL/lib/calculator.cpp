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
        double result = 0;

        switch (t.op)
        {
        case '+':
            result = t.a + t.b;
            break;

        case '-':
            if(t.b_front)
                result = t.b - t.a;
            else
                result = t.a - t.b;
            break;
        
        case '*':
            result = t.a * t.b;
            break;

        case '/':
            if(t.b_front)
                result = t.b / t.a;
            else
                result = t.a / t.b;
            break;

        default:
            break;
        }
        return result;
    }

    double strToDouble(std::string){
        return -1;
    }
}