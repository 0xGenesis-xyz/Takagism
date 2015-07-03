//
//  Room4.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room4.h"
#include "Wall.h"

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
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);

    Wall::drawWall(3, 1.5, -3, 2.1, -3, -1);
    Wall::drawWall(3, 1.5, -3, -0.9, 0, -0.9);
    Wall::drawWall(2, 1.5, -0.1, -1, -0.1, 1);
    Wall::drawWall(2, 1.5, 0.1, 1.9, -2, 1.9);

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
