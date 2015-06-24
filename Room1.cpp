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
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
/*    GLfloat material_ambient[]={0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat material_diffuse[]={1.0f, 0.0f, 0.0f, 1.0f};
    GLfloat material_specular[]={0.0f, 0.0f, 0.0f, 1.0f};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    
    glPushMatrix();
    glTranslatef(3.5, 1.5, -4+0.05);
    glScalef(3, 3, 0.1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(3.5, 1.5, -1-0.05);
    glScalef(3, 3, 0.1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(5-0.05, 1.5, -2.5);
    glScalef(0.1, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2+0.05, 1.5, -1.5);
    glScalef(0.1, 3, 1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2+0.05, 1.5, -3.5);
    glScalef(0.1, 3, 1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2+0.05, 2.5, -2.5);
    glScalef(0.1, 1, 1);
    glutSolidCube(1);
    glPopMatrix();*/
}