//
//  Room4.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room4.h"

Room4::Room4() {
//    init();
}

void Room4::init() {
    nurbs.init();
}

void Room4::drawRoom(GLuint texture) {
    drawWall(texture);
    nurbs.drawNurbs();
}

void Room4::drawWall(GLuint texture) {
    
}