#include "ShaderFile.hpp"

ShaderFile::ShaderFile(string filename, GLuint shader_type) : filename(filename), shader_type(shader_type) {

    setGLId(loadShader());
    printErrors();
}

ShaderFile::~ShaderFile() {
    glDeleteShader(getGLId());
}

GLuint ShaderFile::getGLId() {
    return shader_id;
}

string ShaderFile::getFilename() {
    return filename;
}

void ShaderFile::setGLId(GLuint id) {
    shader_id = id;
}

void ShaderFile::attachTo(GLuint shader_program) {
    glAttachShader(shader_program, getGLId());
}

string ShaderFile::getErrors() {
    char info_log[512] = "";

    if (hasErrors()){
        glGetShaderInfoLog(getGLId(), 512, NULL, info_log);
    }

    return string(info_log);
}

bool ShaderFile::hasErrors() {
    GLint status;
    glGetShaderiv(getGLId(), GL_COMPILE_STATUS, &status);
    return status != GL_TRUE;
}

string ShaderFile::getFileContents() {
    ifstream input_stream(filename);
    string contents((istreambuf_iterator<char>(input_stream)), istreambuf_iterator<char>());
    return contents;
}

void ShaderFile::printErrors() {
    if (hasErrors()) {
        cout << "Error compiling shader '" << getFilename() << "':\n" << getErrors() << "\n";
    }
}

GLuint ShaderFile::createShader() {
    if (shader_type == GL_VERTEX_SHADER){
        return glCreateShader(GL_VERTEX_SHADER);
    } else {
        return glCreateShader(GL_FRAGMENT_SHADER);
    }
}

GLuint ShaderFile::loadShader(){
    GLuint shader = createShader();

    string contents = getFileContents();
    const char* contents_as_cstr = contents.c_str();

    glShaderSource(shader, 1, &contents_as_cstr, NULL);

    // Compile it
    glCompileShader(shader);

    return shader;
}
