#ifndef ShaderFile_h
#define ShaderFile_h

#include <string>
#include <fstream>
#include <iostream>
#include <memory>

#include "includes/gl.hpp"

using namespace std;

class ShaderFile {
public:
    ShaderFile(string filename, GLuint shader_type);
    ~ShaderFile();

    void attachTo(GLuint shader_program);
    string getErrors();
    bool hasErrors();

    GLuint getGLId();
    string getFilename();

private:
    void printErrors();

    void setGLId(GLuint id);
    string getFileContents();
    GLuint createShader();
    GLuint loadShader();

    GLuint shader_id;
    string filename;
    GLuint shader_type;
};

#endif
