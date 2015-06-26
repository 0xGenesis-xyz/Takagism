//
//  Camera.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include <iostream>
#include "Camera.h"

static const float PROPORTION = 0.2f;

void Camera::init() {
    dist=1;
    eye[0]=4.8;
    center[1] = eye[1]=1.6;
    eye[2]=-2.4;
    torch=false;
    intensity=0.6;
}

void Camera::resetCamera(float x, float y, float direct, float z) {
    eye[0] = y * PROPORTION - 5;
    eye[2] = x * PROPORTION - 4;
    center[0] = eye[0] + sin(direct);
    center[2] = eye[2] + cos(direct);
    center[1] = eye[1] = z;
    //std::cout << x << " " << y << " " << direct << std::endl;
}

void Camera::lookUpDown(float p) {
    center[1]+=p;
}

void Camera::zoomIn() {
    if (dist>0.2)
        dist-=0.2;
    //setCamera();
}

void Camera::zoomOut() {
    if (dist<1)
        dist+=0.2;
    //setCamera();
}
