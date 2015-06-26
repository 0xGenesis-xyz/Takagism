//
//  Video.h
//  Takagism
//
//  Created by 张函祎 on 15/6/25.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Video__
#define __Takagism__Video__

#include <stdio.h>
#include <cv.h>
#include <highgui.h>
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>

class Video {
private:
    int frameNum, num;
    GLuint videoTex[500];
public:
    void init();
    void play();
    void drawNext();
};

#endif /* defined(__Takagism__Video__) */
