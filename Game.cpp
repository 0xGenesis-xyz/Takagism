//
//  Game.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#include "Game.h"

void Game::init() {
    initMap();
    camera.init();
    x=8;
    y=49;
    chamber.init();
    for (int i=0; i<5; i++)
        collection[i]=true;
    for (int i=0; i<3; i++)
        toPut[i]=false;
    picked=true;
    key=false;
    door=false;
    doorRotate=0.0f;
}

void Game::drawScene() {
    glEnable(GL_LIGHTING);
    GLfloat light_ambient[] = {camera.intensity*0.1f, camera.intensity*0.1f, camera.intensity*0.1f, 1.0f};
    GLfloat light_diffuse[] = {camera.intensity, camera.intensity, camera.intensity, 1.0f};
    GLfloat light_specular[] = {camera.intensity, camera.intensity, camera.intensity, 1.0f};
    GLfloat light_direction[] = {camera.center[0]-camera.eye[0], camera.center[1]-camera.eye[1], camera.center[2]-camera.eye[2]};
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, camera.eye);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90);
    if (camera.torch)
        glEnable(GL_LIGHT0);
    else
        glDisable(GL_LIGHT0);
    
    chamber.drawChamber();
    for (int i=0; i<5; i++)
        if (collection[i])
            drawXXX();
    for (int i=0; i<3; i++)
        if (toPut[i])
            drawXXX();
    if (picked)
        drawXXX();
    if (key)
        drawXXX();
    drawDoor();
}

void Game::drawDoor() {
    if (door && (doorRotate<90.0f))
        doorRotate+=0.01;
}

void Game::initMap() {
    for (int i=0;i<=40;i++)
        for (int j=0;j<=50;j++)
            map[i][j]=0;
    for (int i=0;i<=50;i++)
        map[0][i]=i%10;
    for (int i=0;i<=40;i++)
        map[i][0]=i%10;
    for (int i=1;i<=50;i++) {
        map[1][i]=1;
        map[40][i]=1;
    }
    for (int i=1;i<=40;i++) {
        map[i][1]=1;
        map[i][50]=1;
    }
    for (int i=10;i<=50;i++)
        map[15][i]=1;
    for (int i=1;i<=3;i++)
        map[30][i]=1;
    for (int i=7;i<=10;i++)
        map[30][i]=1;
    for (int i=15;i<=25;i++)
        map[30][i]=1;
    for (int i=1;i<=5;i++)
        map[i][35]=1;
    for (int i=10;i<=15;i++)
        map[i][35]=1;
    for (int i=15;i<=30;i++)
        map[i][10]=1;
    for (int i=15;i<=25;i++)
        map[i][25]=1;
    for (int i=30;i<=40;i++)
        map[i][25]=1;
}

void Game::drawXXX() {
    
}