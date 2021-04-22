#include <iostream>

#include "../lib/calculator.hpp"

int main(){
    calc::term t;
    t.op = '*';
    t.a = std::stod("0.25");
    t.b = 4;
    t.b_front = 1;

    std::cout << calc::eval(t) << std::endl;
    std::cout << calc::strip("Te   s \n t") << std::endl;
}