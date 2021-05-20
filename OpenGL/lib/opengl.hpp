// OpenGL 
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

// minimum aus der Standart Library
#include <vector>
#include <string>
#include <fstream>
#include <assert.h>

#ifndef opengl_hpp
#define opengl_hpp




namespace gui {
    struct vec2f{
        GLfloat x;
        GLfloat y;
    };

    struct vec3f{
        GLfloat x;
        GLfloat y;
        GLfloat z;
    };

    struct vec4f{
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat a;
    };

    int init();

    class Shape2D{
        protected:
            vec2f position; //upper left corner
            std::vector<int> index_buffer;
            std::vector<vec2f> vertex_buffer;
            vec4f colour; // r, g, b, a
            
        public:
            vec2f getPosition();
            void setPosition(vec2f pos);
            Shape2D();
            Shape2D(vec2f pos);
            ~Shape2D();
    };

    class Rectangle:Shape2D {
        private:
            GLfloat length;
            GLfloat hight;
        
        public:
            Rectangle();
            Rectangle(vec2f pos);
            ~Rectangle();
    };

    class Shader {
        private:
            std::string source;
            GLint type;
            GLuint id;
        
        public:
            Shader(std::string path);
            void compile();
            void load_source_file(std::string path);
            std::string getSource();
    };

    class Window{
        private:
            std::vector<Shape2D> objects;
            std::vector<Shader> shaders;
            std::string name;

            GLFWwindow* id;


        public:
            int init();
            void display();
            int main_loop();
            bool is_open();
            bool key_pressed(int key);
            vec2f cursor_pos();
            void add_object(Shape2D s);
            void add_shader(Shader s);
            int load_new_Shader(std::string path);

            Window();
            Window(std::string name, std::string vert_path, std::string frag_path);

            ~Window();
    };
}

#endif