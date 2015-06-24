//
//  Room4.h
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Room4__
#define __Takagism__Room4__

#include <stdio.h>
#include <OpenGL/gl.h>
#include "Nurbs.h"

class Room4 {
private:
    Nurbs nurbs;
    void drawWall(GLuint texture);
public:
    Room4();
    void init();
    void drawRoom(GLuint texture);
};

#endif /* defined(__Takagism__Room4__) */
