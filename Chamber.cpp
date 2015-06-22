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

void Chamber::drawChamber() {
    glEnable(GL_LIGHTING);
    GLfloat light_ambient[] = {0.6f, 0.6f, 0.6f, 1.0f};
    GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    GLfloat light1_pos[] = {3.5f, 2.8f, -2.5f};
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glEnable(GL_LIGHT1);
    room1.drawRoom();
    
    GLfloat light2_pos[] = {-5.0f, 2.8f, -4.0f};
    
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
//    glEnable(GL_LIGHT2);
    room2.drawRoom();
    
    drawCeilingAndFloor();
}

void Chamber::drawCeilingAndFloor() {
    GLfloat material_ambient[]={0.1f, 0.1f, 0.1f, 1.0f};
    GLfloat material_diffuse[]={0.1f, 0.1f, 0.1f, 1.0f};
    GLfloat material_specular[]={0.0f, 0.0f, 0.0f, 1.0f};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    
    glPushMatrix();
    glTranslatef(0, 3, 0);
    glScalef(10, 0.1, 8);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(10, 0.1, 8);
    glutSolidCube(1);
    glPopMatrix();
}