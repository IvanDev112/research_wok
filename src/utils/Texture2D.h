#ifndef TEXTURE2D_H_
#define TEXTURE2D_H_
#include <GL/glew.h>

class Texture2D {
public:
    Texture2D() { glGenTextures(1, &mId); }
    void Generate(unsigned int width, unsigned int height, unsigned char *data);
    void Bind() const { glBindTexture(GL_TEXTURE_2D, mId); }

    void ChangeToRGBA() {
        mInternalFormat = GL_RGBA;
        mImageFormat = GL_RGBA;
    }

    void Delete() { glDeleteTextures(1, &mId); }
private:
    unsigned int mId;
    unsigned int mWidth = 0, mHeight = 0;
    unsigned int mInternalFormat = GL_RGB, mImageFormat = GL_RGB;
    unsigned int mWrapS = GL_REPEAT, mWrapT = GL_REPEAT;
    unsigned int mFilterMin = GL_LINEAR, mFilterMax = GL_LINEAR;
};

#endif // TEXTURE2D_H_
