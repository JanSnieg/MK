//
//  zad1.hpp
//  modelowanie_18_POlszowy_lista4
//
//  Created by Jan Śnieg on 25/04/2018.
//

#ifndef zad1_hpp
#define zad1_hpp
#define WIDTH 1024
#define HEIGHT 768
#define STEP 5

#include <stdio.h>
#include <vector>
#include <random>
#include "ofMain.h"

extern int mainArray[WIDTH][HEIGHT];
/*Legenda:
 0 - za daleko do wpisania
 1 - mozliwe do wpisania
 2 - zajete miejsce*/
extern bool canGo;

struct zlepek
{
    std::vector<ofVec2f> position;
    ofColor color = (0,0,0);
    zlepek()
    {
        addPos(WIDTH/2,HEIGHT/2);
    }
    void addPos(int x, int y)
    {
        position.push_back(ofVec2f(x,y));
        mainArray[x][y] = 0;
        addOnes(ofVec2f(x, y));
    }
    void addPos(ofVec2f vec)
    {
        position.push_back(vec);
        mainArray[(int)vec.x][(int)vec.y];
        addOnes(vec);
    }
private:
    void addOnes(ofVec2f vec)
    {
        int x = (int)vec.x;
        int y = (int)vec.y;
        if (x<WIDTH && y<HEIGHT && x>0 && y>0)
        {
            //sprawdznie wszystkich miejsc wokół x,y
            if(mainArray[x+STEP][y] == 0)//prawo
                mainArray[x+STEP][y] = 1;
            
            if(mainArray[x-STEP][y] == 0)//lewo
                mainArray[x-STEP][y] = 1;
            
            if(mainArray[x][y+STEP] == 0)//góra
                mainArray[x][y+STEP] = 1;
            
            if(mainArray[x][y-STEP] == 0)//dół
                mainArray[x][y-STEP] = 1;
        }
        else
            canGo = false;
    }
};
std::vector<ofVec2f> checkOnes();
zlepek zadanie1(zlepek);
void drawZlep(zlepek);

#endif /* zad1_hpp */
