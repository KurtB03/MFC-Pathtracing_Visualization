#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <string>
#include <fstream>

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
            GLuint ID;
        
        public:
            void load_source_file(std::string path);
    };

    class Window{
        private:
            GLuint id;
            Shape2D objects[];

        public:
        int init();
        int display();
    };
}

#endif