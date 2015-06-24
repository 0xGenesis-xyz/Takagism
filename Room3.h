//
//  Room3.h
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Room3__
#define __Takagism__Room3__

#include <stdio.h>
#include "Item.h"

class Room3 {
private:
    Item blackRabbit;
    void drawWall(GLuint texture);
public:
    Room3();
    void init();
    void drawRoom(GLuint texture);
};

#endif /* defined(__Takagism__Room3__) */
