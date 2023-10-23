#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"

SpriteRenderer *renderer;

Game::Game(unsigned int width, unsigned int height)
    : mState(GAME_ACTIVE), mKeys(), mWidth(width), mHeight(height) {

}

Game::~Game() {
    delete renderer;
}

void Game::Init() {
    ResourceManager::LoadShader("sprite","res/shaders/sprite.vert", "res/shaders/sprite.frag");
    glm::mat4 projection = glm::ortho(0.0f, (float)mWidth, (float)mHeight, 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use();
    ResourceManager::GetShader("sprite").SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    ResourceManager::LoadTexture("face", "res/textures/awesomeface.png", true);
}

void Game::ProccessInput(float dt) {

}

void Game::Update() {

}

void Game::Render() {
    renderer->DrawSprite(ResourceManager::GetTexture("face"),
            glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f),
            45.0f, glm::vec3(0.0f, 1.0f, 0.0f));

}
