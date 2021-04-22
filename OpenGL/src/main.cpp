#include <iostream>

#include "../lib/calculator.hpp"

int main(){
    calc::term t;
    t.op = '/';
    t.a = 8;
    t.b = 4;
    t.b_front = 1;

    std::cout << calc::eval(t);
}