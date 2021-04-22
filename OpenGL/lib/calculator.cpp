#include "calculator.hpp"

namespace calc{

    std::vector<term> split(std::string s){
        std::vector<term> result;
        term tmp;
        bool post_op = false;

        for (auto i : s){
            switch (i)
            {
            case '1':
                /* code */
                break;
            
            default:
                break;
            }
        }

        return result;
    }

    std::string strip(std::string s){
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
                continue;
                break;
            
            default:
                result += i;
                break;
            }
        }

        return result;
    }

    double calc(std::string s){
        std::vector<term> parts = split(strip(s));
        double result = 0;
        double last = 0;

        term tmp;
        tmp.b_front = true;
        bool do_tmp;
        bool pre_tmp; 

        for (auto i : parts){
            if (i.b_front){
                i.b = last;
            }

            if (i.b_back){
                tmp.a = i.a;
                pre_tmp = true;
                do_tmp = false;
                continue;
            }

            if (do_tmp){
                last = eval(tmp);
                result += last;

                pre_tmp = false;
                do_tmp = false;

                continue;
            }

            if (pre_tmp){
                do_tmp = true;
            }
            
            last = eval(i);
            result += last;
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

}