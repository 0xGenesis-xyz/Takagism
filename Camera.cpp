//
//  Camera.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <stdio.h>
#include "Camera.h"

#define STEP 0.2

void Camera::init() {
    direct=0;
    head=-1;
    dist=1;
    eye[0]=4.8;
    eye[1]=1.6;
    eye[2]=-2.4;
    setCenter();
    torch=false;
    intensity=0.6;
}

void Camera::moveCamera() {
    eye[direct]+=STEP*head;
    center[direct]+=STEP*head;
}

void Camera::changeDirect() {
    direct=2-direct;
    setCenter();
}

void Camera::changeHead() {
    head=-head;
    setCenter();
}

void Camera::moveCenter(float p) {
    center[2-direct]+=p*head*(1-direct);
}

void Camera::lookUpDown(float p) {
    center[1]+=p;
}

void Camera::zoomIn() {
    if (dist>0.2)
        dist-=0.2;
    setCamera();
}

void Camera::zoomOut() {
    if (dist<1)
        dist+=0.2;
    setCamera();
}

void Camera::setCenter() {
    for (int i=0; i<3; i++)
        center[i]=eye[i];
    center[direct]=eye[direct]+dist*head;
}

void Camera::setCamera() {
    for (int i=0; i<3; i++)
        eye[i]=center[i];
    eye[direct]=center[direct]-dist*head;
}