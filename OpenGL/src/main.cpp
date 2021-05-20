#include <iostream>

#include "../lib/calculator.hpp"
#include "../lib/opengl.hpp"
#include "../lib/util.hpp"

int main(){

    if(!glfwInit()){
        return -1;
    }
    
    gui::Window window("calc", "shader/SimpleVerexShader.vert", "shader/SimpleFragmentShader.frag");
    window.main_loop();

    return 0;
}

int gui::Window::main_loop(){

    while (!glfwWindowShouldClose(id))
    {
        std::cout << "loopender loop" << std::endl;
        glfwSwapBuffers(id);
    }

    glfwDestroyWindow(id);
    std::cout << "Window Closed" << std::endl;
    return 0;
}