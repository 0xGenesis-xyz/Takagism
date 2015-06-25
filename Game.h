//
//  Game.h
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef Takagism_Game_h
#define Takagism_Game_h

#include "Camera.h"
#include "Chamber.h"
#include "Video.h"

class Game {
private:
    bool collection[5];     //items to collect
    bool picked;            //item to pick up
    bool key;
    bool toPut[3];          //item to put
    void initMap();
    void move();
    void turn();
    void drawXXX();
    float x, y;
    float direct;    // from 0 to 2 pi
    float perspAngle;
    float moveSpeed;
    float turnSpeed;
    bool smoothMove;
    bool smoothTurn;
    void updateMoveSpeed();
    void updateTurnSpeed();
    enum { FORWARD, BACKWARD, STOP_FORWARD, STOP_BACKWARD, STILL } moving;
    enum { LEFT, RIGHT, STOP_LEFT, STOP_RIGHT, NO_TURNING } turning;
public:
    int map[41][51];
    float getPerspAngle() { return perspAngle; }
    void stopMove();
    void stopTurn();
    void moveForward();
    void turnLeft();
    void turnRight();
    void moveBackward();
    void zoomIn();
    void zoomOut();
    Camera camera;
    Chamber chamber;
    Video video;
    void init();
    void drawScene();
    void screenCut(int width, int height);
};

#endif
