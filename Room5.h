//
//  Room5.h
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Room5__
#define __Takagism__Room5__

#include <stdio.h>
#include "Item.h"

class Room5 {
private:
    Item table;
    Item tableT;
    void drawWall(GLuint texture);
    void initTable();
    void initTableT();
public:
    void init();
    void drawRoom(GLuint texture);
};

#endif /* defined(__Takagism__Room5__) */
