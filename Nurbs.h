//
//  Nurbs.h
//  Takagism
//
//  Created by 张函祎 on 15/6/24.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Nurbs__
#define __Takagism__Nurbs__

#include <stdio.h>
#include <OpenGL/glu.h>

class Nurbs {
private:
    GLUnurbsObj *theNurb;
    GLfloat ctlpoints[4][4][3];
    GLfloat tcoords[2][2][2]={0, 0, 0, 1, 1, 0, 1, 1};
public:
    void init();
    void drawNurbs();
};

#endif /* defined(__Takagism__Nurbs__) */
