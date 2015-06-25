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
//    CvCapture *capture=cvCreateFileCapture("sand14.avi");
    capture=cvCreateFileCapture("sand14.avi");
    assert(capture);
    frame = cvQueryFrame(capture);
    int frameH = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    int frameW = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    int fps = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
    int numFrames = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
    printf("\tvideo height : %d\n\tvideo width : %d\n\tfps : %d\n\tframe numbers : %d\n", frameH, frameW, fps, numFrames);
/*
    frameNum=0;
    while (1) {
        frame=cvQueryFrame(capture);
        if (!frame)
            break;
        glBindTexture(GL_TEXTURE_2D, videoTex[frameNum++]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, frame->width, frame->height, GL_RGB, GL_UNSIGNED_BYTE, frame->imageData);
    }
    num=0;*/
}

void Video::play() {
    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, videoTex[num]);
    glBindTexture(GL_TEXTURE_2D, videoTex);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-3.0f, 1.0f, 3.9f);
    glTexCoord2f(0.3f, 1.0f); glVertex3f(-4.5f, 1.0f, 3.9f);
    glTexCoord2f(0.3f, 0.0f); glVertex3f(-4.5f, 2.0f, 3.9f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.0f, 2.0f, 3.9f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Video::drawNext() {
    num++;
    if (num==frameNum) {
        num=0;
        std::cout<<"loop   ";
    }
}
