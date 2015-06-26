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
    float eye[3];  // eye[0]: y, eye[2]: x
    float center[3];

    bool torch;
    float intensity;

    void init();
    void resetCamera(float, float, float, float z = 1.6f);
    void lookUpDown(float p);
    void zoomIn();
    void zoomOut();
};

#endif
