#pragma once
#include "Components.h"

class PositionComponent : public Component {
private:
    int pos_x;
    int pos_y;
public:
PositionComponent() {
        pos_x = 0;
        pos_y = 0;
    }
    PositionComponent(int x, int y) {
        pos_x = x;
        pos_y = y;
    }
    void update() override {
        pos_x++;
    }
    void setPos(int x, int y) {
        pos_x = x;
        pos_y = y;
    }
    void setX(int x) {
        pos_x = x;
    }
    void setY(int y) {
        pos_y = y;
    }
    int getX() {
        return pos_x;
    }
    int getY() {
        return pos_y;
    }
};