//
//  Item.h
//  Takagism
//
//  Created by 张函祎 on 15/6/23.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Item__
#define __Takagism__Item__

#include <iostream>
#include <stdio.h>
#include <GLUT/GLUT.h>
#include "glm.h"

class Item {
private:
    float scale;
    float ambient[4];
    float diffuse[4];
    float specular[4];
public:
    GLMmodel* model;
    float modelCenter[3];
    bool display;
    void init(char *fileName, float center[], float _scale, bool _display);
//    void init(char *fileName, float center[], GLfloat material_ambient[], GLfloat material_diffuse[], GLfloat material_specular[]);
    void drawItem();
    void drawItem(float rotate);
    void drawItem(float x, float y, float z);
    void drawItem(float x, float y, float z, float rotate);
};

#endif /* defined(__Takagism__Item__) */
