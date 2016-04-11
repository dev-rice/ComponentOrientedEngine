#ifndef Texture_h
#define Texture_h

#include <string>
#include <iostream>

#include "includes/gl.hpp"
#include "includes/glm.hpp"
#include "includes/sdl.hpp"
#include "includes/soil.hpp"

using namespace std;

class Texture {
public:
    Texture();

    static Texture createFromFile(string filepath);
    static Texture createFromColor(glm::vec4 color);

    GLuint getGLId();
    void bind(GLenum target);
private:
    Texture(string filename);
    Texture(glm::vec4 color);

    void create();

    void loadTextureFromBytes(GLubyte* data, GLuint width, GLuint height, GLuint filter, bool anisotropic_filtering);

    void loadTextureFromFile(string filepath, GLuint filter, bool anisotropic_filtering);

    GLuint gl_texture_id;

};

#endif
