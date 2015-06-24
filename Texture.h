//
//  Texture.h
//  Takagism
//
//  Created by 张函祎 on 15/6/23.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Texture__
#define __Takagism__Texture__

#include <stdio.h>
#include <vector>
#include <GLUT/GLUT.h>
#include "lodepng.h"

class Texture {
public:
    std::vector<unsigned char> image;
    unsigned width, height;
    void load(char *fileName, GLuint &texture);
};

#endif /* defined(__Takagism__Texture__) */
