//
//  Chamber.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include "Chamber.h"
#include "Wall.h"

void Chamber::init() {
    translate=-3.6f;
    scale=0.36f;
    door=false;
    doorRotate=0.0f;
    tex=0;
    room2.init();
    room3.init();
    room4.init();
    room5.init();
    video.init();
    listID=GenList();
}

GLint Chamber::GenList() {
    GLint lid=glGenLists(1);
    loadTextures();

    glNewList(lid, GL_COMPILE);

    room1.drawRoom(textures[2]);
    room2.drawRoom(textures[3]);
    room3.drawRoom(textures[4]);
    room4.drawRoom(textures[5]);
    room5.drawRoom(textures[6]);
    drawgap(textures[7]);
    drawCeilingAndFloor();

    glEndList();
    return lid;
}

void Chamber::drawChamber() {
    static float ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};
    static float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    static float specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    static float shininess = 40.0f;

    glCallList(listID);

    drawSphere();
    drawDoor(textures[8]);
    video.play();
}

void Chamber::drawSphere() {
    translate+=0.1f;
    if (translate>-1.4f)
        translate=-3.6f;
    scale+=0.02f;
    if (scale>0.8f)
        scale=0.36f;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[tex]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glPushMatrix();
    glTranslatef(-4.6, 2.6, translate);
    glScalef(scale, scale, scale);
    glutSolidSphere(0.4, 50, 50);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void Chamber::drawDoor(GLuint doorTex) {
    if (door && (doorRotate<95.0f))
        doorRotate+=1;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, doorTex);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glTranslatef(5, 0, 3.78);
    glRotatef(doorRotate, 0, 1, 0);
    glTranslatef(-5, 0, -3.78);

    glBegin(GL_QUADS);
    Wall::drawWall(1, 1, 5, 3, 5, 3.78, 0, 2);
    Wall::drawWall(1, 1, 5.1, 3, 5.1, 3.78, 0, 2);
    glEnd();

    glBegin(GL_QUADS);
    Wall::drawWall(1, 1, 5.1, 3, 5, 3, 0, 2);
    Wall::drawWall(1, 1, 5.1, 3, 5, 3.78, 2, 3);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Chamber::drawgap(GLuint texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);

    Wall::drawWall(0.2, 1, 1.9, -3, 2.1, -3);
    Wall::drawWall(0.2, 1, 1.9, -2, 2.1, -2);
    Wall::drawWall(0.2, 1, -3.5, 1.9, -3.5, 2.1);
    Wall::drawWall(0.2, 1, -4.5, 1.9, -4.5, 2.1);
    Wall::drawWall(0.2, 1, -2, 1.9, -2, 2.1);
    Wall::drawWall(0.2, 1, -0.1, 1, 0.1, 1);

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Chamber::loadTextures() {
    glGenTextures(9, textures);
    Texture wallpaper[9];
    wallpaper[0].load("wallpaper1.png", textures[0]);
    wallpaper[1].load("wallpaper2.png", textures[1]);
    wallpaper[2].load("wallpaper3.png", textures[2]);
    wallpaper[3].load("wallpaper4.png", textures[3]);
    wallpaper[4].load("wallpaper5.png", textures[4]);
    wallpaper[5].load("wallpaper6.png", textures[5]);
    wallpaper[6].load("wallpaper7.png", textures[6]);
    wallpaper[7].load("wallpaper8.png", textures[7]);
    wallpaper[8].load("doorpaper.png", textures[8]);
}

void Chamber::drawCeilingAndFloor() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(-5, 3, 4);
    glTexCoord2d(5, 0); glVertex3f(5, 3, 4);
    glTexCoord2d(5, 4); glVertex3f(5, 3, -4);
    glTexCoord2d(0, 4); glVertex3f(-5, 3, -4);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(-5, 0, 4);
    glTexCoord2d(5, 0); glVertex3f(5, 0, 4);
    glTexCoord2d(5, 4); glVertex3f(5, 0, -4);
    glTexCoord2d(0, 4); glVertex3f(-5, 0, -4);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
