#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include <vector>

#ifndef opengl_hpp
#define opengl_hpp

/**********************************
Koordinaten : float array index 0 = x, 1 = y, 2 = z

************************************/


namespace gui {
    struct vec2f{
        GLfloat x;
        GLfloat y;
    };

    class Shape2D{
        private:
            vec2f position; //upper left corner
            std::vector<int> index_buffer;
            std::vector<vec2f> vertex_buffer;
            
        public:
            vec2f getPosition();
            Shape2D();
            ~Shape2D();
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