#include "Shader.h"
#include <iostream>

void Shader::Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource) {
    unsigned int vs, fs, gs;
    
    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexSource, nullptr);
    glCompileShader(vs);
    CheckCompileErrors(vs, "VERTEX");

    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentSource, nullptr);
    glCompileShader(fs);
    CheckCompileErrors(fs, "FRAGMENT");

    if (geometrySource != nullptr) {
        gs = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(gs, 1, &geometrySource, nullptr);
        glCompileShader(gs);
        CheckCompileErrors(gs, "GEOMETRY");
    }

    mId = glCreateProgram();
    glAttachShader(mId, vs);
    glAttachShader(mId, fs);
    if (geometrySource)
        glAttachShader(mId, gs);

    glLinkProgram(mId);
    CheckCompileErrors(mId, "PROGRAM");

    glDeleteShader(vs);
    glDeleteShader(fs);
    if (geometrySource)
        glDeleteShader(gs);

}

void Shader::CheckCompileErrors(unsigned int object, std::string type) {
    int success;
    char infoLog[1024];

    if (type == "PROGRAM") {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(object, 1024, nullptr, infoLog);
            std::cout << "Linking-time shader error: Type: " << type << "\n" << infoLog << std::endl;
        }
    } else {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(object, 1024, nullptr, infoLog);
            std::cout << "Compile-time shader error: Type " << type << "\n" << infoLog << std::endl;
        }
    }
}
