//
//  zad4.hpp
//  modelowanie_18_POlszowy_lista3
//
//  Created by Jan Śnieg on 11/04/2018.
//

#ifndef zad4_hpp
#define zad4_hpp

#include <stdio.h>
#include <random>
#include <fstream>
#include "ofMain.h"


struct rainDrop
{
    int x, y;
    int czasSpadku = 0;
    rainDrop(int h = 0)
    {
        x = 0;
        y = h;
    }
};

rainDrop raining (rainDrop);
void statistics();
#endif /* zad4_hpp */
