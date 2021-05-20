#include <iostream>

#include "../lib/calculator.hpp"
#include "../lib/opengl.hpp"
#include "../lib/util.hpp"



int main(){

    if(int i = gui::init()){
        return i;
    }


    
    gui::Window window("calc", "shader/SimpleVerexShader.vert", "shader/SimpleFragmentShader.frag"); 
    window.main_loop();
    gui::Window test;
    test.main_loop();

    std::cout << "end main" << std::endl;

    
    return 0;
}