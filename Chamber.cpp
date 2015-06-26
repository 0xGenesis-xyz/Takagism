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
    door=false;
    doorRotate=0.0f;
    room2.init();
    room3.init();
    room4.init();
    //video.init();
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
    glEnable(GL_LIGHTING);
    GLfloat light_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_diffuse[] = {0.6f, 0.6f, 0.6f, 1.0f};
    GLfloat light_specular[] = {0.6f, 0.6f, 0.6f, 1.0f};
    
    GLfloat light1_pos[] = {3.5f, 2.8f, -2.5f};
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glEnable(GL_LIGHT1);
    
    GLfloat light2_pos[] = {-5.0f, 2.8f, -4.0f};
    
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
    glEnable(GL_LIGHT2);
    
    GLfloat light3_pos[] = {-1.2f, 2.8f, 3.8f};
    
    glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT3, GL_POSITION, light3_pos);
    glEnable(GL_LIGHT3);
    
    GLfloat light4_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light4_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light4_pos[] = {2.5f, 2.8f, 2.0f};
    
    glLightfv(GL_LIGHT4, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light4_specular);
    glLightfv(GL_LIGHT4, GL_POSITION, light4_pos);
    glEnable(GL_LIGHT4);
    
    GLfloat light5_pos[] = {5.5f, 2.8f, 3.2f};
    
    glLightfv(GL_LIGHT5, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, light4_diffuse);
    glLightfv(GL_LIGHT5, GL_SPECULAR, light4_specular);
    glLightfv(GL_LIGHT5, GL_POSITION, light5_pos);
    glEnable(GL_LIGHT5);

    glCallList(listID);
    video.play();
    drawDoor(textures[8]);
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
    glTexCoord2d(0, 0); glVertex3f(5, 0, 3);
    glTexCoord2d(1, 0); glVertex3f(5, 0, 3.78);
    glTexCoord2d(1, 1); glVertex3f(5, 2, 3.78);
    glTexCoord2d(0, 1); glVertex3f(5, 2, 3);
    
    glTexCoord2d(0, 0); glVertex3f(5.1, 0, 3);
    glTexCoord2d(1, 0); glVertex3f(5.1, 0, 3.78);
    glTexCoord2d(1, 1); glVertex3f(5.1, 2, 3.78);
    glTexCoord2d(0, 1); glVertex3f(5.1, 2, 3);
    glEnd();
    
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3f(5.1, 0, 3);
    glTexCoord2d(1, 0); glVertex3f(5, 0, 3);
    glTexCoord2d(1, 1); glVertex3f(5, 2, 3);
    glTexCoord2d(0, 1); glVertex3f(5.1, 2, 3);
    
    glTexCoord2d(0, 0); glVertex3f(5.1, 2, 3);
    glTexCoord2d(1, 0); glVertex3f(5, 2, 3.78);
    glTexCoord2d(1, 1); glVertex3f(5, 2, 3.78);
    glTexCoord2d(0, 1); glVertex3f(5.1, 2, 3);
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
    glTexCoord2d(0, 0); glVertex3f(2-0.1, 0, -3);
    glTexCoord2d(0.2, 0); glVertex3f(2+0.1, 0, -3);
    glTexCoord2d(0.2, 1); glVertex3f(2+0.1, 3, -3);
    glTexCoord2d(0, 1); glVertex3f(2-0.1, 3, -3);

    glTexCoord2d(0, 0); glVertex3f(2-0.1, 0, -2);
    glTexCoord2d(0.2, 0); glVertex3f(2+0.1, 0, -2);
    glTexCoord2d(0.2, 1); glVertex3f(2+0.1, 3, -2);
    glTexCoord2d(0, 1); glVertex3f(2-0.1, 3, -2);
    
    glTexCoord2d(0, 0); glVertex3f(-3.5, 0, 2-0.1);
    glTexCoord2d(0.2, 0); glVertex3f(-3.5, 0, 2+0.1);
    glTexCoord2d(0.2, 1); glVertex3f(-3.5, 3, 2+0.1);
    glTexCoord2d(0, 1); glVertex3f(-3.5, 3, 2-0.1);
    
    glTexCoord2d(0, 0); glVertex3f(-4.5, 0, 2-0.1);
    glTexCoord2d(0.2, 0); glVertex3f(-4.5, 0, 2+0.1);
    glTexCoord2d(0.2, 1); glVertex3f(-4.5, 3, 2+0.1);
    glTexCoord2d(0, 1); glVertex3f(-4.5, 3, 2-0.1);
    
    glTexCoord2d(0, 0); glVertex3f(-2, 0, 2-0.1);
    glTexCoord2d(0.2, 0); glVertex3f(-2, 0, 2+0.1);
    glTexCoord2d(0.2, 1); glVertex3f(-2, 3, 2+0.1);
    glTexCoord2d(0, 1); glVertex3f(-2, 3, 2-0.1);
    
    glTexCoord2d(0, 0); glVertex3f(-0.1, 0, 1);
    glTexCoord2d(0.2, 0); glVertex3f(0.1, 0, 1);
    glTexCoord2d(0.2, 1); glVertex3f(0.1, 3, 1);
    glTexCoord2d(0, 1); glVertex3f(-0.1, 3, 1);
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
