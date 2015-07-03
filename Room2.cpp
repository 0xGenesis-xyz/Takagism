//
//  Room2.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room2.h"
#include "Wall.h"

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
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);

    Wall::drawWall(7, 3, -5, -4, 2, -4);
    Wall::drawWall(6, 3, -5, 2, -5, -4);
    Wall::drawWall(5, 3, 2, -1.1, -3.1, -1.1);
    Wall::drawWall(6, 3, -3.1, -1.1, -3.1, 2);
    Wall::drawWall(1, 3, 1.9, -1, 1.9, -2);
    Wall::drawWall(1, 3, 1.9, -3, 1.9, -4);
    Wall::drawWall(0.5, 3, -5, 1.9, -4.5, 1.9);
    Wall::drawWall(0.5, 3, -3.5, 1.9, -3, 1.9);

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
