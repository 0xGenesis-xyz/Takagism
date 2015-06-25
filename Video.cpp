//
//  Video.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/25.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include "Video.h"

void Video::init() {
    capture=cvCreateFileCapture("video.avi");
//    capture=cvCreateCameraCapture(0);
    std::cout<<"video create"<<std::endl;
    if (!capture)
        std::cout<<"video fail"<<std::endl;
}

void Video::play() {
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5f, 1.0f, 3.9f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.5f, 1.0f, 3.9f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-4.5f, 2.0f, 3.9f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5f, 2.0f, 3.9f);
    glEnd();
    std::cout<<"video play"<<std::endl;
}
