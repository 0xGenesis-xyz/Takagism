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
    CvCapture *capture=cvCreateFileCapture("sand14.avi");
    assert(capture);
    int frameH = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    int frameW = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    int fps = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
    int numFrames = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
    printf("\tvideo height : %d\n\tvideo width : %d\n\tfps : %d\n\tframe numbers : %d\n", frameH, frameW, fps, numFrames);

    frameNum=0;
    glGenTextures(336, videoTex);
    while (IplImage *frame=cvQueryFrame(capture)) {
        glBindTexture(GL_TEXTURE_2D, videoTex[frameNum++]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, frame->width, frame->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, frame->imageData);
    }
    num=0;
}

void Video::play() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, videoTex[num]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-3.0f, 1.0f, 3.9f);
    glTexCoord2f(0.8f, 1.0f); glVertex3f(-4.5f, 1.0f, 3.9f);
    glTexCoord2f(0.8f, 0.0f); glVertex3f(-4.5f, 2.0f, 3.9f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-3.0f, 2.0f, 3.9f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Video::drawNext() {
    num++;
    if (num==frameNum) {
        num=0;
        std::cout<<"loop\t";
    }
}
