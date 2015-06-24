//
//  Room5.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room5.h"

void Room5::drawRoom(GLuint texture) {
    drawWall(texture);
}

void Room5::drawWall(GLuint texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(0.1, 0, 1);
    glTexCoord2d(0.42, 0); glVertex3f(0.1, 0, -1);
    glTexCoord2d(0.42, 1); glVertex3f(0.1, 3, -1);
    glTexCoord2d(0, 1); glVertex3f(0.1, 3, 1);
    
    glTexCoord2d(0.42, 0); glVertex3f(0, 0, -1+0.1);
    glTexCoord2d(1.46, 0); glVertex3f(5, 0, -1+0.1);
    glTexCoord2d(1.46, 1); glVertex3f(5, 3, -1+0.1);
    glTexCoord2d(0.42, 1); glVertex3f(0, 3, -1+0.1);
/*
    glTexCoord2d(1.46, 0); glVertex3f(5, 0, -1);
    glTexCoord2d(2.5, 0); glVertex3f(5, 0, 4);
    glTexCoord2d(2.5, 1); glVertex3f(5, 3, 4);
    glTexCoord2d(1.46, 1); glVertex3f(5, 3, -1);
*/
    glTexCoord2d(1.46, 0); glVertex3f(5, 0, -1);
    glTexCoord2d(2.29, 0); glVertex3f(5, 0, 3);
    glTexCoord2d(2.29, 1); glVertex3f(5, 3, 3);
    glTexCoord2d(1.46, 1); glVertex3f(5, 3, -1);
    
    glTexCoord2d(2.29, 0.67); glVertex3f(5, 2, 3);
    glTexCoord2d(2.45, 0.67); glVertex3f(5, 2, 3.78);
    glTexCoord2d(2.45, 1); glVertex3f(5, 3, 3.78);
    glTexCoord2d(2.29, 1); glVertex3f(5, 3, 3);
    
    glTexCoord2d(2.45, 0); glVertex3f(5, 0, 3.78);
    glTexCoord2d(2.5, 0); glVertex3f(5, 0, 4);
    glTexCoord2d(2.5, 1); glVertex3f(5, 3, 4);
    glTexCoord2d(2.45, 1); glVertex3f(5, 3, 3.78);
    
    glTexCoord2d(2.5, 0); glVertex3f(5, 0, 4);
    glTexCoord2d(3.54, 0); glVertex3f(0, 0, 4);
    glTexCoord2d(3.54, 1); glVertex3f(0, 3, 4);
    glTexCoord2d(2.5, 1); glVertex3f(5, 3, 4);
    
    glTexCoord2d(2.5, 0); glVertex3f(0.1, 0, 4);
    glTexCoord2d(2.92, 0); glVertex3f(0.1, 0, 2-0.1);
    glTexCoord2d(2.92, 1); glVertex3f(0.1, 3, 2-0.1);
    glTexCoord2d(2.5, 1); glVertex3f(0.1, 3, 4);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
