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
        case 'q': {
            //game.camera.moveCenter(-0.1);
            break;
        }
        case 'e': {
            //game.camera.moveCenter(0.1);
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
        }
        case 't': {
            game.chamber.door=!game.chamber.door;
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
//    cvSetCaptureProperty(game.video.capture, CV_CAP_PROP_POS_FRAMES, 0);
    // Capture next frame
    game.video.frame = cvQueryFrame(game.video.capture);
//    std::cout<<cvGrabFrame(game.video.capture)<<std::endl;
//    assert(cvRetrieveFrame(game.video.capture));

    // Create Texture

//    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, game.video.frame->width, game.video.frame->height, GL_RGB, GL_UNSIGNED_BYTE, game.video.frame->imageData);
    
    // Update View port
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
#include <highgui.h>

int main( int argc, char** argv ) {
    cvNamedWindow( "Example2", CV_WINDOW_AUTOSIZE );
    //CvCapture* capture = cvCaptureFromAVI( argv[1] ); // either one will work
    CvCapture* capture = cvCreateFileCapture("tree.avi");
    if (capture==NULL)
        printf("error\n");
    IplImage* frame;
    while(1) {
        frame = cvQueryFrame( capture );
//        if( !frame ) break;
        cvShowImage( "Example2", frame );
        char c = cvWaitKey(33);
        if( c == 27 ) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Example2" );
}
*/