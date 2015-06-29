//
//  Item.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/23.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include "Item.h"

void Item::init(char *fileName, float center[], float _scale, bool _display=true) {
    model=glmReadOBJ(fileName);
    glmFacetNormals(model);
    modelCenter[0]=center[0];
    modelCenter[1]=center[1];
    modelCenter[2]=center[2];
    if (!model)
        std::cout<<"load failed"<<std::endl;
    scale=_scale;
    display=_display;
}

void Item::drawItem() {
//    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    
    glPushMatrix();
    glTranslatef(modelCenter[0], modelCenter[1], modelCenter[2]);
    glScalef(scale, scale, scale);
    glmDraw(model, GLM_FLAT);
    glPopMatrix();
}

void Item::drawItem(float rotate) {
    glPushMatrix();
    glTranslatef(modelCenter[0], modelCenter[1], modelCenter[2]);
    glRotatef(rotate, 0, 1, 0);
    glScalef(scale, scale, scale);
    glmDraw(model, GLM_FLAT);
    glPopMatrix();
}

void Item::drawItem(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);
    glmDraw(model, GLM_FLAT);
    glPopMatrix();
}
