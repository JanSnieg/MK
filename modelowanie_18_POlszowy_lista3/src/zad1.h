#ifndef zad1_h
#define zad1_h

#include <stdio.h>
#include <random>
#include "ofMain.h"

struct WalkerPosition
{
    int x, y;
    WalkerPosition ()
    {
        x = ofGetWidth()/2;
        y = ofGetHeight()/2;
    }
};

ofPolyline walkway(ofPolyline);
int walker10000();



#endif /* zad1_h */
