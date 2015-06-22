//
//  Room2.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "Room2.h"

void Room2::drawRoom() {
    drawWall();
}

void Room2::drawWall() {
    GLfloat material_ambient[]={0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat material_diffuse[]={0.0f, 1.0f, 0.0f, 1.0f};
    GLfloat material_specular[]={0.0f, 0.0f, 0.0f, 1.0f};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    
    glPushMatrix();
    glTranslatef(-1.5, 1.5, -4+0.05);
    glScalef(7, 3, 0.1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-5+0.05, 1.5, -1);
    glScalef(0.1, 3, 6);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.5, 1.5, -1-0.05);
    glScalef(5, 3, 0.1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-3-0.05, 1.5, 0.5);
    glScalef(0.1, 3, 3);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-4.75, 1.5, 2-0.05);
    glScalef(0.5, 3, 0.1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-3.25, 1.5, 2-0.05);
    glScalef(0.5, 3, 0.1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-4, 2.5, 2-0.05);
    glScalef(1, 1, 0.1);
    glutSolidCube(1);
    glPopMatrix();

}