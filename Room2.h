//
//  Room2.h
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Room2__
#define __Takagism__Room2__

#include <stdio.h>
#include "Item.h"
#include "Texture.h"

class Room2 {
private:
    Item whiteRabbit;
    Texture wallpaper;
    void loadTextures();
    void drawWall(GLuint texture);
public:
    Room2();
    void init();
    void drawRoom(GLuint texture);
};

#endif /* defined(__Takagism__Room2__) */
