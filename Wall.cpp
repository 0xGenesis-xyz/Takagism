#include <cmath>
#include <GLUT/glut.h>
#include "Wall.h"

static const float TILE_SIZE = 0.1;

/*
  texW0: x value of start of texture
  texH0: y value of start of texture
  x0: x value of start point
  y0: y value of start point
  x1: x value of end point
  y1: y value of end point
  h0: z value of start point
  h1: z value of end point
  texW1: x value of end of texture
  texH1: y value of end of texture
 */
void Wall::drawWall(float texW1, float texH1, float x0, float y0, float x1, float y1,
                    float h0, float h1, float texW0, float texH0) {
    if (x0 == x1) {
        if (y0 > y1) { float tmp = y0; y0 = y1; y1 = tmp; }
        int splitW = ceil((y1 - y0) / TILE_SIZE);    // horizontal split
        int splitH = ceil((h1 - h0) / TILE_SIZE);    // vertical split
        float dw = (y1 - y0) / splitW;    // delta width
        float dh = (h1 - h0) / splitH;    // delta height
        float dtw = (texW1 - texW0) / splitW;    // delta texture width
        float dth = (texH1 - texH0) / splitH;    // delta texture height

        float ww = y0, tw = texW0;    // current width, current texture width
        float nw = y0 + dw, ntw = texW0 + dtw;    // next ...
        for (int i = 0; i < splitW; i++) {
            float hh = h0, th = 0;    // current height, current texture height
            float nh = h0 + dh, nth = dth;    // next ...
            for (int j = 0; j < splitH; j++) {
                glTexCoord2d(tw, th); glVertex3f(x0, hh, ww);
                glTexCoord2d(ntw, th); glVertex3f(x0, hh, nw);
                glTexCoord2d(ntw, nth); glVertex3f(x0, nh, nw);
                glTexCoord2d(tw, nth); glVertex3f(x0, nh, ww);
                th = nth;
                nth += dth;
                hh = nh;
                nh += dh;
            }
            tw = ntw;
            ntw += dtw;
            ww = nw;
            nw += dw;
        }
    }
    else if (y0 == y1) {
        if (x0 > x1) { float tmp = x0; x0 = x1; x1 = tmp; }
        int splitW = ceil((x1 - x0) / TILE_SIZE);
        int splitH = ceil((h1 - h0) / TILE_SIZE);
        float dw = (x1 - x0) / splitW;
        float dh = (h1 - h0) / splitH;
        float dtw = (texW1 - texW0) / splitW;
        float dth = (texH1 - texH0) / splitH;

        float ww = x0, tw = texW0;
        float nw = x0 + dw, ntw = texW0 + dtw;
        for (int i = 0; i < splitW; i++) {
            float hh = h0, th = 0;
            float nh = h0 + dh, nth = dth;
            for (int j = 0; j < splitH; j++) {
                glTexCoord2d(tw, th); glVertex3f(ww, hh, y0);
                glTexCoord2d(ntw, th); glVertex3f(nw, hh, y0);
                glTexCoord2d(ntw, nth); glVertex3f(nw, nh, y0);
                glTexCoord2d(tw, nth); glVertex3f(ww, nh, y0);
                th = nth;
                nth += dth;
                hh = nh;
                nh += dh;
            }
            tw = ntw;
            ntw += dtw;
            ww = nw;
            nw += dw;
        }
    }
    /*
    if (x0 == x1) {
        if (y0 > y1) { float tmp = y0; y0 = y1; y1 = tmp; }
        float ny = y0 + TILE_SIZE;
        float nh = TILE_SIZE;
        for (float yy = y0; ny < y1; yy = ny, ny += TILE_SIZE) {
            for (float hh = 0; nh < h; hh = nh, nh += TILE_SIZE) {
                glTexCoord2d(0, 0); glVertex3f(x0, hh, yy);
                glTexCoord2d(1, 0); glVertex3f(x0, hh, ny);
                glTexCoord2d(1, 1); glVertex3f(x0, nh, ny);
                glTexCoord2d(0, 1); glVertex3f(x0, nh, yy);
            }
        }
    }
    else if (y0 == y1) {
        if (x0 > x1) { float tmp = x0; x0 = x1; x1 = tmp; }
        for (float xx = x0, nx = x0 + TILE_SIZE; nx <= x1; xx = nx, nx += TILE_SIZE) {
            for (float hh = 0, nh = TILE_SIZE; nh <= h; hh = nh, nh += TILE_SIZE) {
                glTexCoord2d(0, 0); glVertex3f(xx, hh, y0);
                glTexCoord2d(1, 0); glVertex3f(nx, hh, y0);
                glTexCoord2d(1, 1); glVertex3f(nx, nh, y0);
                glTexCoord2d(0, 1); glVertex3f(xx, nh, y0);
            }
        }
    }
    */
}
