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

void Chamber::init() {
//    listID=GenList();
    room2.init();
    room3.init();
    room4.init();
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
    drawCeilingAndFloor();
    
    glEndList();
    return lid;
}

void Chamber::drawChamber() {
    loadTextures();
    
    glEnable(GL_LIGHTING);
    GLfloat light_ambient[] = {0.6f, 0.6f, 0.6f, 1.0f};
    GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    GLfloat light1_pos[] = {3.5f, 2.8f, -2.5f};
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
//    glEnable(GL_LIGHT1);
    room1.drawRoom(textures[2]);
    
    GLfloat light2_pos[] = {-5.0f, 2.8f, -4.0f};
    
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
    glEnable(GL_LIGHT2);
    room2.drawRoom(textures[3]);
    
    GLfloat light3_pos[] = {-1.2f, 2.8f, 3.8f};
    
    glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT3, GL_POSITION, light3_pos);
//    glEnable(GL_LIGHT3);
    
    room3.drawRoom(textures[4]);
    room4.drawRoom(textures[5]);
    room5.drawRoom(textures[6]);
    
    drawCeilingAndFloor();
//    glCallList(listID);
}

void Chamber::loadTextures() {
    glGenTextures(7, textures);
    Texture wallpaper[7];
    wallpaper[0].load("wallpaper1.png", textures[0]);
    wallpaper[1].load("wallpaper2.png", textures[1]);
    wallpaper[2].load("wallpaper.png", textures[2]);
    wallpaper[3].load("wallpaper4.png", textures[3]);
    wallpaper[4].load("wallpaper.png", textures[4]);
    wallpaper[5].load("wallpaper.png", textures[5]);
    wallpaper[6].load("wallpaper.png", textures[6]);
/*
    ceilingpaper.load("wallpaper1.png");
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ceilingpaper.width, ceilingpaper.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &ceilingpaper.image[0]);
    
    floorpaper.load("wallpaper2.png");
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, floorpaper.width, floorpaper.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &floorpaper.image[0]);
/*
    wallpaper.load("wallpaper4.png");
//    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, wallpaper.width, wallpaper.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &wallpaper.image[0]);*/
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