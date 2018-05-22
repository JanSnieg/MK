//
//  zad3.hpp
//  modelowanie_18_POlszowy_lista4
//
//  Created by Jan Śnieg on 25/04/2018.
//

#ifndef zad3_hpp
#define zad3_hpp
#define WIDTH 1024
#define HEIGHT 768
#define LENGTH 300
#define STEP 1

#include <stdio.h>
#include <vector>
#include <random>
#include "ofMain.h"

extern int mainArray[WIDTH][HEIGHT];
/*Legenda:
 0 - za daleko do wpisania
 1 - mozliwe do wpisania
 2 - zajete miejsce*/
extern bool canExtand;
extern ofVec2f wedrownik;

struct zlepek
{
    std::vector<ofVec2f> position;
    ofColor color = (0,0,0);
    zlepek()
    {
        addPos(WIDTH/2,HEIGHT/2);
    }
    zlepek(int length)
    {
        ofVec2f start = ofVec2f((WIDTH/2)-length, (HEIGHT/2)-length);
        ofVec2f stop = ofVec2f((WIDTH/2)+length, (HEIGHT/2)+length);
        std::vector<ofVec2f> punkty;
        for (int i=start.x; i<stop.x; i++)
        {
            //        dodawanie punktów na granicy górnej i dolnej kwadrawtu
            addPos(i, start.y);
            addPos(i, stop.y);
        }
        for (int i=start.y; i<stop.y; i++)
        {
            //        dodawania punktów na granicy lewej i pracej kwadratu
            addPos(start.x, i);
            addPos(stop.x, i);
        }
    }
    void addPos(int x, int y)
    {
        position.push_back(ofVec2f(x,y));
        mainArray[x][y] = 2;
        addOnes(ofVec2f(x, y));
    }
    void addPos(ofVec2f vec)
    {
        position.push_back(vec);
        mainArray[(int)vec.x][(int)vec.y] = 2;
        addOnes(vec);
    }
private:
    void addOnes(ofVec2f vec)
    {
        ofVec2f middle = ofVec2f(WIDTH/2, HEIGHT/2);
        int x = (int)vec.x;
        int y = (int)vec.y;
        if (middle.distance(vec) < STEP)
            canExtand = false;
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
            canExtand = false;
    }
};
std::vector<ofVec2f> checkOnes();
zlepek zadanie3(zlepek);
void drawZlep(zlepek);

#endif /* zad3_hpp */
