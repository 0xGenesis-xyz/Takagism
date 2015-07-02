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
    initTable();
}

void Room2::initTable() {
    char fileName[128]="Table de nuit_Final.obj";
    float center[]={-4.9f, 0.1f, -3.05f};
    table.init(fileName, center, 0.02f, true);
}

void Room2::drawRoom(GLuint texture) {
    drawWall(texture);
    table.drawItem(90);

    glPushMatrix();
    glTranslatef(0.0f, 0.1f, -2.5f);
    glRotatef(90, -1, 0, 0);
    GLUquadric *cylinder=gluNewQuadric();
    gluCylinder(cylinder, 0.3, 0.3, 1.8, 32, 5);

    glTranslatef(-1.0f, 0.0f, 0.0f);
    gluCylinder(cylinder, 0.3, 0.0, 1.8, 32, 5);

    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRotatef(90, 1, 0, 0);
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.173f, 0.0f, 0.1f);
    glVertex3f(0.173f, 1.0f, 0.1f);
    glVertex3f(0.0f, 0.0f, -0.2f);
    glVertex3f(0.0f, 1.0f, -0.2f);
    glVertex3f(-0.173f, 0.0f, 0.1f);
    glVertex3f(-0.173f, 1.0f, 0.1f);
    glVertex3f(0.173f, 0.0f, 0.1f);
    glVertex3f(0.173f, 1.0f, 0.1f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.173f, 1.0f, 0.1f);
    glVertex3f(0.0f, 1.0f, -0.2f);
    glVertex3f(-0.173f, 1.0f, 0.1f);
    glEnd();

    glTranslatef(-1.0f, 0.0f, 0.0f);
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.2f, 0.0f, 0.2f);
    glVertex3f(0.1f, 1.0f, 0.1f);
    glVertex3f(0.2f, 0.0f, -0.2f);
    glVertex3f(0.1f, 1.0f, -0.1f);
    glVertex3f(-0.2f, 0.0f, -0.2f);
    glVertex3f(-0.1f, 1.0f, -0.1f);
    glVertex3f(-0.2f, 0.0f, 0.2f);
    glVertex3f(-0.1f, 1.0f, 0.1f);
    glVertex3f(0.2f, 0.0f, 0.2f);
    glVertex3f(0.1f, 1.0f, 0.1f);
    glEnd();

    glPopMatrix();
}

void Room2::drawWall(GLuint texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
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
