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
#include "Object.h"

#define RANGE 1.8

static const float STEP = 0.4f;
static const float ANGLE = M_PI / 60;
static const float TIME_RANGE = 2.0f;
static const float DTIME = 0.4f;
static const int ZOOM_TO_FIT_FRAMES = 20;
static const float COLLISION_ALLOWENCE = 0.15;

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
    zooming = NO_ZOOM_TO_FIT;
    fitItem = -1;
    smoothMove = false;
    smoothTurn = false;
    direct = M_PI * 1.5;
    camera.resetCamera(x, y, direct);
    chamber.init();
    initItems();
    toPut=false;
}

void Game::initItems() {
    initWhiteRabbit();
    initBlackRabbit();
    initCrystal();
    initBook();
    initVase();
}

void Game::initWhiteRabbit() {
    char fileName[128]="bunny.obj";
    float center[]={-4.5f, 1.1f, -3.6f};
    GLfloat material_ambient[]={0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat material_diffuse[]={0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat material_specular[]={0.0f, 0.0f, 0.0f, 1.0f};
    collection[0].init(fileName, center, 0.001f, true);
    itemPos[0] = Object(4.0f, 3.5f, 1.3f, M_PI * 1.25, 1.6f);
}

void Game::initBlackRabbit() {
    char fileName[128]="bunny.obj";
    float center[]={-0.5f, 1.0f, 3.5f};
    GLfloat material_ambient[]={0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat material_diffuse[]={0.1f, 0.1f, 0.1f, 1.0f};
    GLfloat material_specular[]={0.0f, 0.0f, 0.0f, 1.0f};
    collection[1].init(fileName, center, 0.001f, true);
    itemPos[1] = Object(36.0f, 22.0f, 1.1f, M_PI * 0.25, 1.6f);
}

void Game::initCrystal() {
    char fileName[128]="Crystal.obj";
    float center[]={-2.3f, 0.1f, -0.6f};
    collection[2].init(fileName, center, 0.1f, true);
    itemPos[2] = Object(17.0f, 12.5f, 0.2f, M_PI * 0.3, 1.2f);
}

void Game::initBook() {
    char fileName[128]="book.obj";
    float center[]={-0.7f, 0.9f, 3.5f};
    collection[3].init(fileName, center, 0.1f, false);
    itemPos[3] = Object(36.0f, 20.0f, 1.1f, M_PI * 0.25, 1.2f);
}

void Game::initVase() {
    char fileName[128]="vase.obj";
    float center[]={3.0f, 0.8f, 3.5f};
    collection[4].init(fileName, center, 0.004f, true);
    itemPos[4] = Object(37.0f, 40.0f, 1.0f, M_PI * 0, 1.8f);
}

void Game::moveForward() {
    if (zooming == NO_ZOOM_TO_FIT)
        moving = FORWARD;
}

void Game::moveBackward() {
    if (zooming == NO_ZOOM_TO_FIT)
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
    static float time = -TIME_RANGE;
    switch (moving) {
    case FORWARD:
    case BACKWARD:
        if (time < TIME_RANGE)
            time += DTIME;
        else
            smoothMove = true;
        break;
    case STOP_FORWARD:
    case STOP_BACKWARD:
        if (time > -TIME_RANGE)
            time -= DTIME;
        else {
            moving = STILL;
            time = -TIME_RANGE;
        }
        break;
    case STILL:
        time = -TIME_RANGE;
    }
    moveSpeed = STEP / (pow(M_E, -time) + 1);    // STEP * 1 / (e ^ time + 1)
}

void Game::move() {
    float newx, newy;
    //std::cout << x << " " << y << std::endl;
    if (moving == FORWARD || moving == STOP_FORWARD) {
        newx = x + moveSpeed * cos(direct);
        newy = y + moveSpeed * sin(direct);
    }
    else {
        newx = x - moveSpeed * cos(direct);
        newy = y - moveSpeed * sin(direct);
    }
    if (!map[lrint(newx)][lrint(newy)] &&
        !map[lrint(newx + COLLISION_ALLOWENCE)][lrint(newy + COLLISION_ALLOWENCE)] &&
        !map[lrint(newx - COLLISION_ALLOWENCE)][lrint(newy - COLLISION_ALLOWENCE)]) {
        // round and cast to long int
        x = newx;
        y = newy;
        camera.resetCamera(x, y, direct);
    }
}

void Game::turnLeft() {
    if (zooming == NO_ZOOM_TO_FIT)
        turning = LEFT;
}

void Game::turnRight() {
    if (zooming == NO_ZOOM_TO_FIT)
        turning = RIGHT;
}

void Game::updateTurnSpeed() {
    static float time = -TIME_RANGE;
    switch (turning) {
    case LEFT:
    case RIGHT:
        if (time < TIME_RANGE)
            time += DTIME;
        else
            smoothTurn = true;
        break;
    case STOP_LEFT:
    case STOP_RIGHT:
        if (time > -TIME_RANGE)
            time -= DTIME;
        else {
            turning = NO_TURNING;
            time = -TIME_RANGE;
        }
        break;
    case NO_TURNING:
        time = -TIME_RANGE;
    }
    turnSpeed = ANGLE / (pow(M_E, -time) + 1);    // ANGLE * 1 / (e ^ time + 1)
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
}

void Game::zoomOut() {
    if (perspAngle <= 120)
        perspAngle += 2;
}

void Game::zoomToFit() {
    for (int i=0; i<4; i++) {
        if (collection[i].display && distance(collection[i].modelCenter)<RANGE)
            switch (i) {
            case 0:
                fitItem = i;
                break;
            case 1:
            case 3:
                if (y < 24.4)
                    fitItem = i;
                break;
            case 2:
                if (y > 10.4 && x > 15.4)
                    fitItem = i;
                break;
            case 4:
                if (toPut && !collection[3].display)
                    fitItem = 4;
                break;
            }
        //if ((i == 2 && y > 10.4 && x > 15.4) ||
        //((i == 1 || i == 3) && y < 24.4))
    }

    if (distance(collection[4].modelCenter)<RANGE && collection[4].display && toPut && !collection[3].display) {
        fitItem = 4;
    }

    if (fitItem != -1) {
    std::cout << "Fit " << fitItem << std::endl;
        switch (zooming) {
        case NO_ZOOM_TO_FIT:
            zooming = OPERATING;
            break;
        case ZOOM_TO_FIT:
            zooming = RESTORING;
            break;
        case OPERATING:
        case RESTORING:
            break;    // zoomToFit state cannot be changed
        }
    }
}

void Game::updateZoomToFit(Object& obj) {
    static float dx, dy, dz, dd;
    static float nx, ny, nz, nd;
    static int count;
    static bool calc = false;
    if (!calc) {
        float targetX = obj.x - obj.size * cos(obj.direct);
        float targetY = obj.y - obj.size * sin(obj.direct);
        float targetZ = obj.z;
        float targetD = obj.direct;
        if (zooming == OPERATING) {
            nx = x;
            ny = y;
            nz = z;
            nd = direct;
            dx = (targetX - x) / ZOOM_TO_FIT_FRAMES;
            dy = (targetY - y) / ZOOM_TO_FIT_FRAMES;
            dz = (targetZ - z) / ZOOM_TO_FIT_FRAMES;
            dd = (targetD - direct);
        }
        else if (zooming == RESTORING) {
            nx = targetX;
            ny = targetY;
            nz = targetZ;
            nd = targetD;
            dx = (x - targetX) / ZOOM_TO_FIT_FRAMES;
            dy = (y - targetY) / ZOOM_TO_FIT_FRAMES;
            dz = (z - targetZ) / ZOOM_TO_FIT_FRAMES;
            dd = (direct - targetD);
        }
        if (dd >= M_PI) dd -= 2 * M_PI;
        if (dd <= -M_PI) dd += 2 * M_PI;
        dd /= ZOOM_TO_FIT_FRAMES;
        count = 0;
        calc = true;
    }
    else {
        if (count < ZOOM_TO_FIT_FRAMES) {
            nx += dx;
            ny += dy;
            nz += dz;
            nd += dd;
            count++;
            camera.resetCamera(nx, ny, nd, nz);
        }
        else {
            if (zooming == OPERATING)
                zooming = ZOOM_TO_FIT;
            else if (zooming == RESTORING) {
                zooming = NO_ZOOM_TO_FIT;
                fitItem = -1;
            }
            count = 0;
            calc = false;
        }
    }
}

void Game::pickup() {
    /*
    for (int i=0; i<4; i++)
        if (distance(collection[i].modelCenter)<RANGE && collection[i].display) {
            collection[i].display=false;
            std::cout<<"pick up "<<i<<std::endl;
        }
    if (distance(collection[4].modelCenter)<RANGE && collection[4].display && toPut && !collection[3].display) {
        collection[4].display=false;
        std::cout<<"pick up 4"<<std::endl;
        chamber.door=!chamber.door;
    }
    */
    if (fitItem != -1) {
        collection[fitItem].display = false;
        if (fitItem == 4)
            chamber.door = !chamber.door;
    }
}

void Game::put() {
    float table[3]={2.5f, 0.2f, -0.7f};
    if (!toPut && distance(table)<RANGE) {
        bool flag=false;
        for (int i=0; i<3; i++)
            flag=flag || collection[i].display;
        if (!flag) {
            toPut=true;
            collection[3].display=true;
        }
    }
}

float Game::distance(float position[]) {
    return sqrtf(pow(camera.eye[0]-position[0], 2)+pow(camera.eye[2]-position[2], 2));
}

void Game::drawScene() {
    glEnable(GL_LIGHTING);
//    GLfloat light_ambient[] = {camera.intensity*0.1f, camera.intensity*0.1f, camera.intensity*0.1f, 1.0f};
    GLfloat light_ambient[] = {camera.intensity, camera.intensity, camera.intensity, 1.0f};
    GLfloat light_diffuse[] = {camera.intensity, camera.intensity, camera.intensity, 1.0f};
    GLfloat light_specular[] = {camera.intensity, camera.intensity, camera.intensity, 1.0f};
    GLfloat light_direction[] = {camera.center[0]-camera.eye[0], camera.center[1]-camera.eye[1], camera.center[2]-camera.eye[2]};
    static float angle = 0;
    angle += M_PI / 180;
    if (angle >= 2 * M_PI)
        angle = 0;
    //GLfloat light_direction[] = {static_cast<GLfloat>(sin(angle)), 0, static_cast<GLfloat>(cos(angle))};
    //std::cout << camera.center[0] - camera.eye[0] << " " << camera.center[1] - camera.eye[1] << " " << camera.center[2] - camera.eye[2] << std::endl;
    //GLfloat light_direction[] = {camera.center[0]-camera.eye[0], camera.center[2]-camera.eye[2], camera.center[1]-camera.eye[1]};
    //GLfloat light_direction[] = {camera.center[1]-camera.eye[1], camera.center[0]-camera.eye[0], camera.center[2]-camera.eye[2]};
    //GLfloat light_direction[] = {camera.center[1]-camera.eye[1], camera.center[2]-camera.eye[2], camera.center[0]-camera.eye[0]};
    //GLfloat light_direction[] = {camera.center[2]-camera.eye[2], camera.center[0]-camera.eye[0], camera.center[1]-camera.eye[1]};
    //GLfloat light_direction[] = {camera.center[2]-camera.eye[2], camera.center[1]-camera.eye[1], camera.center[0]-camera.eye[0]};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, camera.eye);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 127.0);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90);
    if (camera.torch)
        glEnable(GL_LIGHT0);
    else
        glDisable(GL_LIGHT0);

    switch (moving) {
    case FORWARD:
    case BACKWARD:
        if (!smoothMove)
            updateMoveSpeed();
        move();
        break;
    case STOP_FORWARD:
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
    case RIGHT:
        if (!smoothTurn)
            updateTurnSpeed();
        turn();
        break;
    case STOP_LEFT:
    case STOP_RIGHT:
        updateTurnSpeed();
        turn();
        break;
    case NO_TURNING:
        break;
    default:
        break;
    }

    switch (zooming) {
    case OPERATING:
    case RESTORING:
        updateZoomToFit(itemPos[fitItem]);
        break;
    default:
        break;
    }

    chamber.drawChamber();
    if (collection[0].display) collection[0].drawItem(90);
    if (collection[1].display) collection[1].drawItem(270);

    if (collection[4].display) collection[4].drawItem(180);
    for (int i=2; i<5; i++)
        if (collection[i].display)
            collection[i].drawItem();
    if (toPut)
        drawXXX();
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
    for (int i=19;i<=21;i++)
        for (int j=13;j<=22;j++)
            map[i][j]=1;
    for (int i=6;i<=9;i++)
        for (int j=9;j<=11;j++)
            map[i][j]=1;
    for (int i=7;i<=8;i++) {
        for (int j=14;j<=16;j++)
            map[i][j]=1;
        for (int j=19;j<=21;j++)
            map[i][j]=1;
        for (int j=24;j<=26;j++)
            map[i][j]=1;
    }
}

void Game::drawXXX() {
    glPushMatrix();
    collection[0].drawItem(2.8f, 1.1f, -0.5f);
    collection[2].drawItem(3.2f, 1.0f, -0.4f);
    collection[1].drawItem(3.6f, 1.1f, -0.3f);
    glPopMatrix();
}
