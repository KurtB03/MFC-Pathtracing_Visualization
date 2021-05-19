#include "calculator.hpp"

namespace calc{
    std::vector<term> split(std::string s){
        std::vector<term> result;
        std::string number = "0";
        term tmp = clearTerm();
        bool post_op = false;

        //std::cout << s << std::endl;

        for (auto i : s){
            switch (i)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                number += i;               
                break;
            
            case '+':
            case '-':
            case '*':
            case '/':
                if(post_op){
                    tmp.b = std::stod(number);
                    number = "0";
                    if(tmp.a == 0) {
                        tmp.op = i;
                        tmp.b_front = true;
                    }
                    result.push_back(tmp);
                    tmp = clearTerm();
                }
                tmp.a = std::stod(number);
                number = "0";
                tmp.op = i;
                post_op = true;
                break;
            
            default:
                break;
            }
        }

        tmp.b = std::stod(number);
        if(tmp.a == 0) {
        tmp.b_front = true;
        }
        result.push_back(tmp);

        return result;
    }

    double calc(std::string s){
        std::vector<term> parts = split(ownStrip(s));
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

    term clearTerm(){
        term t;
        t.op = '+';
        t.a = 0;
        t.b = 0;
        t.b_back = false;
        t.b_front = false;

        return t;
    }
}