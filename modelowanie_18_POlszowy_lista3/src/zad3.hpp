//
//  zad3.hpp
//  modelowanie_18_POlszowy_lista3
//
//  Created by Jan Śnieg on 11/04/2018.
//

#ifndef zad3_hpp
#define zad3_hpp

#include <iostream>
#include <random>
#include "ofMain.h"

struct WalkerPositionZad3
{
    int x, y, z;
    WalkerPositionZad3 ()
    {
        x = 0;
        y = 0;
        z = 0;
    }
};

ofPolyline walkway3(ofPolyline);

#endif /* zad3_hpp */
