//
//  Room1.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room1.h"
#include "Wall.h"

void Room1::drawRoom(GLuint texture) {
    drawWall(texture);
}

void Room1::drawWall(GLuint texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);

    Wall::drawWall(1, 1, 2, -4, 5, -4);
    Wall::drawWall(1, 1, 5, -4, 5, -1);
    Wall::drawWall(1, 1, 5, -1.1, 2, -1.1);
    Wall::drawWall(0.3, 1, 2.1, -1, 2.1, -2);
    Wall::drawWall(0.3, 1, 2.1, -3, 2.1, -4);

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
