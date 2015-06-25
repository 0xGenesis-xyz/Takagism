//
//  Game.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include <GLUT/GLUT.h>
#include "Game.h"

static const float STEP = 0.4f;
static const float ANGLE = M_PI / 60;
static const float ddirect = M_PI / 75;
static const float dspeed = 0.1f;

void Game::init() {
    initMap();
    camera.init();
    x = 8.0f;
    y = 49.0f;
    perspAngle = 90.0f;
    moveSpeed = 0.0f;
    turnSpeed = 0.0f;
    moving = STILL;
    turning = NO_TURNING;
    smoothMove = false;
    smoothTurn = false;
    direct = M_PI * 1.5;
    camera.resetCamera(x, y, direct);
    chamber.init();
    for (int i=0; i<5; i++)
        collection[i]=true;
    for (int i=0; i<3; i++)
        toPut[i]=false;
    picked=true;
    key=false;
    video.init();
}

void Game::moveForward() {
    moving = FORWARD;
}

void Game::moveBackward() {
    moving = BACKWARD;
}

void Game::stopMove() {
    smoothMove = false;
    switch (moving) {
    case FORWARD:
        moving = STOP_FORWARD;
        break;
    case BACKWARD:
        moving = STOP_BACKWARD;
        break;
    default:
        break;
    }
}

void Game::stopTurn() {
    smoothTurn = false;
    switch (turning) {
    case LEFT:
        turning = STOP_LEFT;
        break;
    case RIGHT:
        turning = STOP_RIGHT;
        break;
    default:
        break;
    }
}

void Game::updateMoveSpeed() {
    static float time = -5.0f;
    switch (moving) {
    case FORWARD:
    case BACKWARD:
        if (time < 5.0f)
            time += 0.05f;
        else
            smoothMove = true;
        break;
    case STOP_FORWARD:
    case STOP_BACKWARD:
        if (time > -5.0f)
            time -= 0.05f;
        else {
            moving = STILL;
            time = -5.0f;
        }
    case STILL:
        time = -5.0f;
    }
    moveSpeed = STEP / (pow(M_E, time) + 1);    // STEP * 1 / (e ^ time + 1)
}

void Game::move() {
    float newx, newy;
    if (moving == FORWARD || moving == STOP_FORWARD) {
        newx = x + moveSpeed * cos(direct);
        newy = y + moveSpeed * sin(direct);
    }
    else {
        newx = x - moveSpeed * cos(direct);
        newy = y - moveSpeed * sin(direct);
    }
    if (!map[lrint(newx)][lrint(newy)]) {  // round and cast to long int
        x = newx;
        y = newy;
        camera.resetCamera(x, y, direct);
    }
}

void Game::turnLeft() {
    turning = LEFT;
    /*
    direct += ddirect;
    if (direct >= 2 * M_PI)
        direct = 0.0f;
    camera.resetCamera(x, y, direct);
    */
}

void Game::turnRight() {
    turning = RIGHT;
    /*
    direct -= ddirect;
    if (direct < 0)
        direct = 2 * M_PI;
    camera.resetCamera(x, y, direct);
    */
}

void Game::updateTurnSpeed() {
    static float time = -5.0f;
    switch (turning) {
    case LEFT:
    case RIGHT:
        if (time < 5.0f)
            time += 0.05f;
        else
            smoothTurn = true;
        break;
    case STOP_LEFT:
    case STOP_RIGHT:
        if (time > -5.0f)
            time -= 0.05f;
        else {
            turning = NO_TURNING;
            time = -5.0f;
        }
    case NO_TURNING:
        time = -5.0f;
    }
    turnSpeed = ANGLE / (pow(M_E, time) + 1);    // ANGLE * 1 / (e ^ time + 1)
}

void Game::turn() {
    if (turning == LEFT || turning == STOP_LEFT)
        direct += turnSpeed;
    else
        direct -= turnSpeed;
    if (direct >= 2 * M_PI)
        direct -= 2 * M_PI;
    if (direct < 0)
        direct += 2 * M_PI;
    camera.resetCamera(x, y, direct);
}

void Game::zoomIn() {
    if (perspAngle >= 45)
        perspAngle -= 2;
    std::cout << perspAngle << std::endl;
}

void Game::zoomOut() {
    if (perspAngle <= 120)
        perspAngle += 2;
    std::cout << perspAngle << std::endl;
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

    switch (moving) {
    case FORWARD:
        if (!smoothMove)
            updateMoveSpeed();
        move();
        break;
    case BACKWARD:
        if (!smoothMove)
            updateMoveSpeed();
        move();
        break;
    case STOP_FORWARD:
        updateMoveSpeed();
        move();
        break;
    case STOP_BACKWARD:
        updateMoveSpeed();
        move();
        break;
    case STILL:
        break;
    default:
        break;
    }

    switch (turning) {
    case LEFT:
        if (!smoothTurn)
            updateTurnSpeed();
        turn();
        break;
    case RIGHT:
        if (!smoothTurn)
            updateTurnSpeed();
        turn();
        break;
    case STOP_LEFT:
        updateTurnSpeed();
        turn();
        break;
    case STOP_RIGHT:
        updateTurnSpeed();
        turn();
        break;
    case NO_TURNING:
        break;
    default:
        break;
    }

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
    video.play();
}

void Game::screenCut(int width, int height) {
    //获取应用程序颜色缓冲区数组
    GLubyte* frameData=(GLubyte*)malloc(width*height*3);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, frameData);

    //创建IplImage结构 并指定结构头为适当格式
    IplImage* SnapImage=cvCreateImageHeader(cvSize(width, height), IPL_DEPTH_8U, 3);
    //将刚创建的IplImage结构的DATA数据指针指向之前获取到的缓冲区数组
    cvSetData(SnapImage, frameData, width*3);

    //由于opencv里颜色data存放的特点 这里要进行下上下翻转
    cvFlip(SnapImage, SnapImage, 0);//上下翻转
    //这里要进行下RGB-BGR的转换...
    cvCvtColor(SnapImage, SnapImage, CV_RGB2BGR); //转格式

    //保存图片
    time_t t=time(0);
    char strTime[64];
//    ZeroMemory(strTime,sizeof(strTime));
    strftime(strTime, 64, "%Y%m%d%H%M%S", localtime(&t));
    strcat(strTime, ".jpg");//保存为年月日时分秒.jpg
    cvSaveImage(strTime, SnapImage);

    //释放内存
    cvReleaseImage(&SnapImage);
    free(frameData);
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
