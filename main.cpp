//
//  main.cpp
//  Takagism
//
//  Created by 张函祎 on 15/6/22.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>

#include "Game.h"

GLint window;
int window_width  = 1000;
int window_height = 750;

Game game;

/// Keyboard Messenge
void keyboard(unsigned char key, int x, int y)
{
    switch ( key )
    {
        case 'a': {
            game.turnLeft();
            break;
        }
        case 'd': {
            game.turnRight();
            break;
        }
        case 'w': {
            game.moveForward();
            break;
        }
        case 's': {
            game.moveBackward();
            break;
        }
        case 'f': {
            game.zoomToFit();
            break;
        }
        case 'z': {
            game.camera.lookUpDown(-0.1);
            break;
        }
        case 'c': {
            game.camera.lookUpDown(0.1);
            break;
        }
        case 'i': {
            game.zoomIn();
            break;
        }
        case 'o': {
            game.zoomOut();
            break;
        }
        case 'p': {
            game.pickup();
            break;
        }
        case 'u': {
            game.put();
            break;
        }
        case 'y': {
            game.chamber.tex++;
            game.chamber.tex%=8;
            break;
        }
        case 'x': {
            game.camera.torch=!game.camera.torch;
            break;
        }
        case '=': {
            if (game.camera.intensity<1.0)
                game.camera.intensity+=0.1;
            break;
        }
        case '-': {
            if (game.camera.intensity>0)
                game.camera.intensity-=0.1;
            break;
        }
        case 'v': {
            game.screenCut(window_width, window_height);
            break;
        }
        case 'q': {
            game.printPos();
            break;
        }

        default:
            break;
    }

    glutPostRedisplay();
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
    case 's':
        game.stopMove();
        break;
    case 'a':
    case 'd':
        game.stopTurn();
        break;
    }
}

/// Display the Object
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(game.getPerspAngle(), (float)window_width/(float)window_height, 0.01f, 200.0f);

    //glMatrixMode(GL_MODELVIEW);

    gluLookAt(game.camera.eye[0], game.camera.eye[1], game.camera.eye[2],
              game.camera.center[0], game.camera.center[1], game.camera.center[2],
              0, 1, 0);

    glEnable(GL_DEPTH_TEST);

    game.drawScene();

    glFlush();
    glutSwapBuffers();
}

void init() {
    game.init();
}

/// Idle function
void idle(void)
{
    game.chamber.video.drawNext();
    
    glutPostRedisplay();
}

/// Reshape the Window
void reshape(int w, int h)
{
    // Update the window's width and height
    window_width  = w;
    window_height = h;

    // Reset the viewport
    glViewport(0, 0, window_width, window_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, (float)window_width/(float)window_height, 0.01f, 200.0f);

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    // Initialize the GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(150, 120);
    window=glutCreateWindow("TAKAGISM");
    init();

    // Set the callback function
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}
/*
#include <cv.h>
#include <highgui.h>

#include <stdio.h>
#include <string.h>
#include <GLUT/GLUT.h>

#define VIEWPORT_WIDTH              720
#define VIEWPORT_HEIGHT             480
#define KEY_ESCAPE                  27


CvCapture* g_Capture;
GLint g_hWindow;

GLvoid InitGL();
GLvoid OnDisplay();
GLvoid OnReshape(GLint w, GLint h);
GLvoid OnKeyPress (unsigned char key, GLint x, GLint y);
GLvoid OnIdle();

int main(int argc, char* argv[])
{
    
    // Create GLUT Window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    
    g_hWindow = glutCreateWindow("Video Texture");
    
    // Create OpenCV camera capture
    // If multiple cameras are installed, please choose correct index
    g_Capture = cvCreateFileCapture("sand14.avi");
    assert(g_Capture);
    int frameH = (int) cvGetCaptureProperty(g_Capture, CV_CAP_PROP_FRAME_HEIGHT);
    int frameW = (int) cvGetCaptureProperty(g_Capture, CV_CAP_PROP_FRAME_WIDTH);
    int fps = (int) cvGetCaptureProperty(g_Capture, CV_CAP_PROP_FPS);
    int numFrames = (int) cvGetCaptureProperty(g_Capture, CV_CAP_PROP_FRAME_COUNT);
    printf("\tvideo height : %d\n\tvideo width : %d\n\tfps : %d\n\tframe numbers : %d\n", frameH, frameW, fps, numFrames);
    
    // Initialize OpenGL
    InitGL();
    
    glutMainLoop();
    
    return 0;
}

GLvoid InitGL()
{
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    
    glutDisplayFunc(OnDisplay);
    glutReshapeFunc(OnReshape);
    glutKeyboardFunc(OnKeyPress);
    glutIdleFunc(OnIdle);
    
}

GLvoid OnDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    
    // Set Projection Matrix
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, VIEWPORT_WIDTH, VIEWPORT_HEIGHT, 0);
    
    // Switch to Model View Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Draw a textured quad
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(VIEWPORT_WIDTH, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, VIEWPORT_HEIGHT);
    glEnd();
    
    glFlush();
    glutSwapBuffers();
    
}


GLvoid OnReshape(GLint w, GLint h)
{
    glViewport(0, 0, w, h);
}

GLvoid OnKeyPress(unsigned char key, int x, int y)
{
    switch (key) {
        case KEY_ESCAPE:
            cvReleaseCapture(&g_Capture);
            glutDestroyWindow(g_hWindow);
            exit(0);
            break;
    }
    glutPostRedisplay();
}


GLvoid OnIdle()
{
    // Capture next frame
    IplImage *image = cvQueryFrame(g_Capture);
    assert(image);
    
    // Convert to RGB
    cvCvtColor(image, image, CV_BGR2RGB);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->imageData);
    // Create Texture
//    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image->width, image->height, GL_RGB, GL_UNSIGNED_BYTE, image->imageData);
    
    // Update View port
    glutPostRedisplay();
}
*/
