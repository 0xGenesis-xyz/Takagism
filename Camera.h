//
//  Camera.h
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef Takagism_Camera_h
#define Takagism_Camera_h

class Camera {
private:
    float dist;
    void setCenter();
    void setCamera();
public:
    float eye[3];
    float center[3];
    int direct;             //{0, 2}
    int head;               //{-1, 1}
    
    bool torch;
    float intensity;
    
    void init();
    void moveCamera();
    void changeDirect();
    void changeHead();
    void moveCenter(float p);
    void lookUpDown(float p);
    void zoomIn();
    void zoomOut();
};

#endif
