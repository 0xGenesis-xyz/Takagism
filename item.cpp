//
//  Item.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/23.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include "Item.h"

void Item::init(char *fileName, float center[], GLfloat material_ambient[], GLfloat material_diffuse[], GLfloat material_specular[]) {
    model=glmReadOBJ(fileName);
    glmFacetNormals(model);
    modelCenter[0]=center[0];
    modelCenter[1]=center[1];
    modelCenter[2]=center[2];
    for (int i=0;i<4;i++) {
        ambient[i]=material_ambient[i];
        diffuse[i]=material_diffuse[i];
        specular[i]=material_specular[i];
    }
    if (!model)
        std::cout<<"load failed"<<std::endl;
}

void Item::drawItem(float x, float y, float z) {
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.002, 0.002, 0.002);
    glmDraw(model, GLM_FLAT);
    glPopMatrix();
}