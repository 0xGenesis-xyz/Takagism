//
//  Room3.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room3.h"
#include "Wall.h"

Room3::Room3() {
//    init();
}

void Room3::init() {
}

void Room3::drawRoom(GLuint texture) {
    drawWall(texture);
    drawBox();
}

void Room3::drawBox() {
    glPushMatrix();
    glTranslatef(-0.5f, 0.4f, 3.5f);
    glutSolidCube(0.8);
    glPopMatrix();
}

void Room3::drawWall(GLuint texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);

    Wall::drawWall(5, 3, 0, 4, -5, 4);
    Wall::drawWall(2, 3, -5, 4, -5, 2);
    Wall::drawWall(2, 3, -0.1, 2, -0.1, 4);
    Wall::drawWall(2, 3, -2, 2.1, 0, 2.1);
    Wall::drawWall(0.5, 3, -5, 2.1, -4.5, 2.1);
    Wall::drawWall(0.5, 3, -3.5, 2.1, -3, 2.1);

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
