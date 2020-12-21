#pragma once

#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"

class SpriteComponent : public Component {
private:
    PositionComponent *position;
    SDL_Texture *texture;
    SDL_Rect srcRect, dstRect;
public:
    SpriteComponent() = default;
    SpriteComponent(const char *filepath) {
        setTexture(filepath);
    }

    void setTexture(const char *filepath) {
        texture = TextureManager::loadTexture(filepath);
    }

    void init() override {
        position = &entity->getComponent<PositionComponent>();
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        dstRect.w = dstRect.h = 64;
    }

    void update() override {
        dstRect.x = position->getX();
        dstRect.y = position->getY();
    }

    void draw() override {
        TextureManager::draw(texture, srcRect, dstRect);
    }
};