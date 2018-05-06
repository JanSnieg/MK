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
        x = 0;
        y = 0;
    }
};

ofPolyline walkway(ofPolyline);
int walker10000();



#endif /* zad1_h */
