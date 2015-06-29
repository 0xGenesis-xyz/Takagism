//
//  Chamber.h
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef Takagism_Chamber_h
#define Takagism_Chamber_h

#include <GLUT/GLUT.h>
#include "Video.h"
#include "Texture.h"
#include "Room1.h"
#include "Room2.h"
#include "Room3.h"
#include "Room4.h"
#include "Room5.h"

class Chamber {
private:
    GLint listID;
    Room1 room1;
    Room2 room2;
    Room3 room3;
    Room4 room4;
    Room5 room5;
    
    float doorRotate;
    float translate;
    float scale;
    void drawSphere();

    GLuint textures[9];
    void loadTextures();
    void drawCeilingAndFloor();
    void drawgap(GLuint texture);
    void drawDoor(GLuint texture);
public:
    Video video;
    bool door;
    void init();
    void drawChamber();
    GLint GenList();
};

#endif
