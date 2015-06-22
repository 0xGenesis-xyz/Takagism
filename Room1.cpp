//
//  Room1.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room1.h"

void Room1::drawRoom() {
    drawWall();
}

void Room1::drawWall() {
    GLfloat material_ambient[]={0.2f, 0.2f, 0.2f, 1.0f};
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
    glPopMatrix();
}