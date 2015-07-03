//
//  Room5.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room5.h"
#include "Wall.h"

void Room5::init() {
    initTable();
    initTableT();
}

void Room5::initTable() {
    char fileName[128]="Table de nuit_Final.obj";
    float center[]={3.6f, 0.1f, 3.9f};
    table.init(fileName, center, 0.02f, true);
}

void Room5::initTableT() {
    char fileName[128]="Granit kitchen table.obj";
    float center[]={2.5f, 0.2f, -0.7f};
    tableT.init(fileName, center, 0.01f, true);
}

void Room5::drawRoom(GLuint texture) {
    drawWall(texture);

    table.drawItem(180.0f);
    tableT.drawItem();
}

void Room5::drawWall(GLuint texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);

    Wall::drawWall(0.42, 1, 0.1, 1, 0.1, -1);
    Wall::drawWall(1.46, 1, 0, -0.9, 5, -0.9, 0, 3, 0.42, 0);
    Wall::drawWall(2.29, 1, 5, -1, 5, 3, 0, 3, 1.46, 0);
    Wall::drawWall(2.45, 1, 5, 3, 5, 3.78, 2, 3, 2.29, 0.67);
    Wall::drawWall(2.5, 1, 5, 3.78, 5, 4, 0, 3, 2.45, 0);
    Wall::drawWall(3.54, 1, 5, 4, 0, 4, 0, 3, 2.5, 0);
    Wall::drawWall(2.92, 1, 0.1, 4, 0.1, 1.9, 0, 3, 2.5, 0);

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
