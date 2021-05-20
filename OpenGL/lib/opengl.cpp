#include "opengl.hpp"

namespace gui {

    // Shape2D class

    vec2f Shape2D::getPosition(){
        return position;
    }

    Shape2D::Shape2D(){}

    Shape2D::Shape2D(vec2f pos){
        position = pos;
    }

    Shape2D::~Shape2D(){}

    // Rectangle class

    Rectangle::Rectangle(){}

    Rectangle::Rectangle(vec2f pos):Shape2D(pos){
        vertex_buffer.push_back(pos); // upper left corner
        index_buffer.push_back(0);
        vertex_buffer.push_back(vec2f{pos.x, pos.y - hight}); // lower left corner
        index_buffer.push_back(1);
        vertex_buffer.push_back(vec2f{pos.x + length, pos.y - hight}); // lower right corner
        index_buffer.push_back(2);
        vertex_buffer.push_back(vec2f{pos.x + length, pos.y}); // upper right corner
        index_buffer.push_back(3);
        index_buffer.push_back(0);
        index_buffer.push_back(2);
    }

    Rectangle::~Rectangle(){}

    // Shader class

    void Shader::load_source_file(std::string path){
        std::string line;
        std::ifstream myfile (path);

        if(path.find(".vert") != std::string::npos){
            type = GL_VERTEX_SHADER;
        }
        else if(path.find(".frag") != std::string::npos){
            type = GL_FRAGMENT_SHADER;
        }
        else{
            // TODO : log Error
            return;
        }

        source = "";

        if (myfile.is_open()){
            while (getline(myfile, line)){
                source += line;
                line = "";
        }
        myfile.close();

        }
        else{
            // TODO: Log Error
            return;
        }

    }

    std::string Shader::getSource(){
        return source;
    }

    void Shader::compile(){

    }

    Shader::Shader(std::string path){
        load_source_file(path);
        compile();
    }

    //Window class

    int Window::init(){
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        id = glfwCreateWindow(640, 480, name.c_str(), NULL, NULL);
        int width, height;
        glfwGetFramebufferSize(id, &width, &height);
        glViewport(0, 0, width, height);
        glfwSwapInterval(1);

        return 0;
    }

    bool Window::is_open(){
        return false;
    }

    bool Window::key_pressed(int key){
        return (glfwGetKey(this->id, key) == GLFW_PRESS);
    }

    vec2f Window::cursor_pos(){
        double x, y;
        glfwGetCursorPos(this->id, &x, &y);
        return vec2f{(float)x, (float)y};
    }

    void Window::add_shader(Shader s){
        shaders.push_back(s);
    }

    Window::Window(){}

    Window::Window(std::string name, std::string vert_path, std::string frag_path){
        this->name = name;
        add_shader(Shader(vert_path));
        add_shader(Shader(frag_path));
        init();
    }

}