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
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(-3, 0, 2.1);
    glTexCoord2d(3, 0); glVertex3f(-3, 0, -1);
    glTexCoord2d(3, 3.0/2); glVertex3f(-3, 3, -1);
    glTexCoord2d(0, 3.0/2); glVertex3f(-3, 3, 2.1);
    
    glTexCoord2d(0, 0); glVertex3f(-3, 0, -1+0.1);
    glTexCoord2d(3, 0); glVertex3f(0, 0, -1+0.1);
    glTexCoord2d(3, 3.0/2); glVertex3f(0, 3, -1+0.1);
    glTexCoord2d(0, 3.0/2); glVertex3f(-3, 3, -1+0.1);
    
    glTexCoord2d(0, 0); glVertex3f(-0.1, 0, -1);
    glTexCoord2d(2, 0); glVertex3f(-0.1, 0, 1);
    glTexCoord2d(2, 3.0/2); glVertex3f(-0.1, 3, 1);
    glTexCoord2d(0, 3.0/2); glVertex3f(-0.1, 3, -1);
    
    glTexCoord2d(0, 0); glVertex3f(0.1, 0, 2-0.1);
    glTexCoord2d(2, 0); glVertex3f(-2, 0, 2-0.1);
    glTexCoord2d(2, 3.0/2); glVertex3f(-2, 3, 2-0.1);
    glTexCoord2d(0, 3.0/2); glVertex3f(0.1, 3, 2-0.1);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}