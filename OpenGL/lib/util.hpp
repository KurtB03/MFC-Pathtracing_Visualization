#include <iostream>

#ifndef util_hpp
#define util_hpp

std::string ownStrip(std::string s){
        std::string result = "";

        for (char i : s){
            switch (i)
            {
            case ' ' :
            case '\n':
            case '\t':
            case '\r':
            case '\f':
            case '\v':
                break;
            
            default:
                result += i;
                break;
            }
        }

        return result;
}
#endif