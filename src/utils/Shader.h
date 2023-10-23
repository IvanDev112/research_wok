#ifndef SHADER_H_
#define SHADER_H_

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    Shader() {  }

    Shader &Use() { glUseProgram(mId); return *this; }
    void Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr);

    void SetFloat(const char *name, float value, bool useShader = false) {
        if (useShader)
            Use();
        glUniform1f(glGetUniformLocation(mId, name), value);
    }
    void SetInteger(const char *name, int value, bool useShader = false) {
        if (useShader)
            Use();
        glUniform1i(glGetUniformLocation(mId, name), value);
    }
    void SetVector2f(const char *name, float x, float y, bool useShader = false) {
        if (useShader)
            Use();
        glUniform2f(glGetUniformLocation(mId, name), x, y);
    }
    void SetVector2f(const char *name, const glm::vec2 &value, bool useShader = false) {
        if (useShader)
            Use();
        glUniform2f(glGetUniformLocation(mId, name), value.x, value.y);
    }
    void SetVector3f(const char *name, float x, float y, float z, bool useShader = false) {
        if (useShader)
            Use();
        glUniform3f(glGetUniformLocation(mId, name), x, y, z);
    }
    void SetVector3f(const char *name, const glm::vec3 &value, bool useShader = false) {
        if (useShader)
            Use();
        glUniform3f(glGetUniformLocation(mId, name), value.x, value.y, value.z);
    }
    void SetVector4f(const char *name, float x, float y, float z, float w, bool useShader = false) {
        if (useShader)
            Use();
        glUniform4f(glGetUniformLocation(mId, name), x, y, z, w);
    }
    void SetVector4f(const char *name, const glm::vec4 &value, bool useShader = false) {
        if (useShader)
            Use();
        glUniform4f(glGetUniformLocation(mId, name), value.x, value.y, value.z, value.w);
    }
    void SetMatrix4(const char *name, const glm::mat4 &matrix, bool useShader = false) {
        if (useShader)
            Use();
        glUniformMatrix4fv(glGetUniformLocation(mId, name), 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void Delete() { glDeleteProgram(mId); }
private:
    unsigned int mId;
    void CheckCompileErrors(unsigned int object, std::string type); 
};

#endif // SHADER_H_
