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

class Game {
private:
    void initMap();
public:
    int x,y;
    int map[41][51];
    Camera camera;
    Chamber chamber;
    void init();
    void drawScene();
};

#endif
