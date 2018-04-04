//
//  zad2.hpp
//  modelowanie_18_POlszowy_lista3
//
//  Created by Jan Śnieg on 28/03/2018.
//

#ifndef zad2_hpp
#define zad2_hpp

#include <stdio.h>
#include <random>
#include <vector>
#include "ofMain.h"

struct Walker2
{
    int x,y;
    Walker2 ()
    {
        x = ofGetWidth()/2;
        y = ofGetHeight()/2;
    }
};
ofPolyline walkway2(ofPolyline);


#endif /* zad2_hpp */
