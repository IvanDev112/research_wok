#ifndef SPRITE_RENDERER_H_
#define SPRITE_RENDERER_H_
#include "utils/Shader.h"
#include "utils/Texture2D.h"

class SpriteRenderer {
public:
    SpriteRenderer(Shader &shader);
    ~SpriteRenderer() { glDeleteVertexArrays(1, &mQuadVAO); }

    void DrawSprite(Texture2D &texture, glm::vec2 pos, glm::vec2 size = glm::vec2(10.0f, 10.0f),
            float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
    Shader mShader;
    unsigned int mQuadVAO;

    void InitRenderData();
};

#endif // SPRITE_RENDERER_H_
