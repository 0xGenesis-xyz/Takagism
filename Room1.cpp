//
//  Room1.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room1.h"

void Room1::drawRoom(GLuint texture) {
    drawWall(texture);
}

void Room1::drawWall(GLuint texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(2, 0, -4);
    glTexCoord2d(1, 0); glVertex3f(5, 0, -4);
    glTexCoord2d(1, 1); glVertex3f(5, 3, -4);
    glTexCoord2d(0, 1); glVertex3f(2, 3, -4);

    glTexCoord2d(0, 0); glVertex3f(5, 0, -4);
    glTexCoord2d(1, 0); glVertex3f(5, 0, -1);
    glTexCoord2d(1, 1); glVertex3f(5, 3, -1);
    glTexCoord2d(0, 1); glVertex3f(5, 3, -4);

    glTexCoord2d(0, 0); glVertex3f(5, 0, -1-0.1);
    glTexCoord2d(1, 0); glVertex3f(2, 0, -1-0.1);
    glTexCoord2d(1, 1); glVertex3f(2, 3, -1-0.1);
    glTexCoord2d(0, 1); glVertex3f(5, 3, -1-0.1);

    glTexCoord2d(0, 0); glVertex3f(2+0.1, 0, -1);
    glTexCoord2d(0.3, 0); glVertex3f(2+0.1, 0, -2);
    glTexCoord2d(0.3, 1); glVertex3f(2+0.1, 3, -2);
    glTexCoord2d(0, 1); glVertex3f(2+0.1, 3, -1);
    
    glTexCoord2d(0, 0); glVertex3f(2+0.1, 0, -3);
    glTexCoord2d(0.3, 0); glVertex3f(2+0.1, 0, -4);
    glTexCoord2d(0.3, 1); glVertex3f(2+0.1, 3, -4);
    glTexCoord2d(0, 1); glVertex3f(2+0.1, 3, -3);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}