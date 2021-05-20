/*#include "opengl.hpp"

namespace gui {

    // Independant Functions

    int init(){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
        glClearDepth(1.0f);                   // Set background depth to farthest
        glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
        glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
        glShadeModel(GL_SMOOTH);   // Enable smooth shading
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections

        return 0;
    }

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
        id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        // Error handling
        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if ( result == GL_FALSE ){
            glDeleteShader(id) ;
            return;
        }
    }

    Shader::Shader(std::string path){
        load_source_file(path);
        compile();
    }

    //Window class

    int Window::init(){
        
        id = glfwCreateWindow(640, 480, name.c_str(), NULL, NULL);
        glfwMakeContextCurrent(id);
        glewInit();


        return 0;
    }

    void Window::display(){
        
        glfwMakeContextCurrent(id);

        glClearColor(0.f, 0.f, 0.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-5.f, 0.f, -4.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(5.f, 0.f, -4.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.f, 6.f);
        glEnd();  

        glfwSwapBuffers(id);
    }

    int Window::main_loop(){
        if(id == NULL){
            return 6;
        }

        display();
        return 0;
    }

    bool Window::is_open(){
        return false;
    }

    bool Window::key_pressed(int key){
        return false;
    }

    vec2f Window::cursor_pos(){
        return vec2f{(float)0, (float)0};
    }

    void Window::add_object(Shape2D s){
        objects.push_back(s);
    }

    void Window::add_shader(Shader s){
        shaders.push_back(s);
    }

    Window::Window(){
        name = "unnamed";
        init();
    }

    Window::Window(std::string name, std::string vert_path, std::string frag_path){
        this->name = name;
        add_shader(Shader(vert_path));
        add_shader(Shader(frag_path));
        init();
    }

    Window::~Window(){
        
    }

}
*/