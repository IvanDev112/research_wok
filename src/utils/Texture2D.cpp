#include "Texture2D.h"

void Texture2D::Generate(unsigned int width, unsigned int height, unsigned char *data) {
    mWidth = width;
    mHeight = height;

    Bind();
    glTexImage2D(GL_TEXTURE_2D, 0, mInternalFormat, width, height, 0, mImageFormat, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mWrapS);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mWrapT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mFilterMin);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mFilterMax);

    glBindTexture(GL_TEXTURE_2D, 0);
}
