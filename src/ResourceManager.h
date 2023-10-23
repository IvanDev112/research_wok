#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include "utils/Shader.h"
#include "utils/Texture2D.h"
#include <GL/glew.h>

#include <string>
#include <map>

class ResourceManager {
public:
    static Shader LoadShader(std::string name, const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr) {
        mShaders[name] = LoadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
        return mShaders[name];
    }
    static Shader &GetShader(std::string name) { return mShaders[name]; }

    static Texture2D LoadTexture(std::string name, const char *file, bool alpha) {
        mTextures[name] = LoadTextureFromFile(file, alpha);
        return mTextures[name];
    }
    static Texture2D &GetTexture(std::string name) { return mTextures[name]; }

    static void Clear() {
        for (auto iter : mShaders) {
            iter.second.Delete();
        }

        for (auto iter : mTextures) {
            iter.second.Delete();
        }
    }
private:
    static std::map<std::string, Shader> mShaders;
    static std::map<std::string, Texture2D> mTextures;

    ResourceManager() {  }

    static Shader LoadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    static Texture2D LoadTextureFromFile(const char *file, bool alpha);
};

#endif // RESOURCE_MANAGER_H_
