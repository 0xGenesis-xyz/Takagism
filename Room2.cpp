//
//  Room2.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room2.h"

Room2::Room2() {
//    init();
}

void Room2::init() {
    char fileName[128]="bunny.obj";
    float center[]={-4.6f, 0.4f, -3.6f};
    GLfloat material_ambient[]={0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat material_diffuse[]={0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat material_specular[]={0.0f, 0.0f, 0.0f, 1.0f};
    whiteRabbit.init(fileName, center, material_ambient, material_diffuse, material_specular);
}

void Room2::drawRoom(GLuint texture) {
    drawWall(texture);
    whiteRabbit.drawItem(-4.6f, 0.4f, -3.6f);
}

void Room2::drawWall(GLuint texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(-5, 0, -4);
    glTexCoord2d(7, 0); glVertex3f(2, 0, -4);
    glTexCoord2d(7, 3); glVertex3f(2, 3, -4);
    glTexCoord2d(0, 3); glVertex3f(-5, 3, -4);
    
    glTexCoord2d(0, 0); glVertex3f(-5, 0, 2);
    glTexCoord2d(6, 0); glVertex3f(-5, 0, -4);
    glTexCoord2d(6, 3); glVertex3f(-5, 3, -4);
    glTexCoord2d(0, 3); glVertex3f(-5, 3, 2);
    
    glTexCoord2d(0, 0); glVertex3f(2, 0, -1-0.1);
    glTexCoord2d(5, 0); glVertex3f(-3-0.1, 0, -1-0.1);
    glTexCoord2d(5, 3); glVertex3f(-3-0.1, 3, -1-0.1);
    glTexCoord2d(0, 3); glVertex3f(2, 3, -1-0.1);
    
    glTexCoord2d(0, 0); glVertex3f(-3-0.1, 0, -1-0.1);
    glTexCoord2d(6, 0); glVertex3f(-3-0.1, 0, 2);
    glTexCoord2d(6, 3); glVertex3f(-3-0.1, 3, 2);
    glTexCoord2d(0, 3); glVertex3f(-3-0.1, 3, -1-0.1);
    
    glTexCoord2d(0, 0); glVertex3f(2-0.1, 0, -1);
    glTexCoord2d(1, 0); glVertex3f(2-0.1, 0, -2);
    glTexCoord2d(1, 3); glVertex3f(2-0.1, 3, -2);
    glTexCoord2d(0, 3); glVertex3f(2-0.1, 3, -1);
    
    glTexCoord2d(0, 0); glVertex3f(2-0.1, 0, -3);
    glTexCoord2d(1, 0); glVertex3f(2-0.1, 0, -4);
    glTexCoord2d(1, 3); glVertex3f(2-0.1, 3, -4);
    glTexCoord2d(0, 3); glVertex3f(2-0.1, 3, -3);
    
    glTexCoord2d(0, 0); glVertex3f(-5, 0, 2-0.1);
    glTexCoord2d(0.5, 0); glVertex3f(-4.5, 0, 2-0.1);
    glTexCoord2d(0.5, 3); glVertex3f(-4.5, 3, 2-0.1);
    glTexCoord2d(0, 3); glVertex3f(-5, 3, 2-0.1);
    
    glTexCoord2d(0, 0); glVertex3f(-3.5, 0, 2-0.1);
    glTexCoord2d(0.5, 0); glVertex3f(-3, 0, 2-0.1);
    glTexCoord2d(0.5, 3); glVertex3f(-3, 3, 2-0.1);
    glTexCoord2d(0, 3); glVertex3f(-3.5, 3, 2-0.1);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}