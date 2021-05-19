#include <vector>
#include <string>

#include <iostream>

#include "util.hpp"

#ifndef calc_hpp
#define calc_hpp

namespace calc{
    struct term{
        // operator
        char op;
        // 1st value
        double a;
        // 2nd value
        double b;
        // the result, of the last term is used as b !!defaults to 0!!
        bool b_front; 
        //the result, of the next term is used as b - prioritises b_front
        bool b_back; 
    };
    

    std::vector<term> split(std::string s);
    double calc(std::string s);
    double eval(term t);
    term clearTerm();
}

#endif