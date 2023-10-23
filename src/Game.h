#ifndef GAME_H_
#define GAME_H_
#include "utils/State.h"

class Game {
public:
    Game(unsigned int width, unsigned int height);
    ~Game();

    void Init();
    void ProccessInput(float dt);
    void Update();
    void Render();

    void ActivateKey(int key) { mKeys[key] = true; }
    void DeactivateKey(int key) { mKeys[key] = false; }
private:
    unsigned int mWidth, mHeight;
    bool mKeys[1024];
    GameState mState;
};

#endif // GAME_H_
