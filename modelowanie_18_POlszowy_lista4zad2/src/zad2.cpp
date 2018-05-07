//
//  zad2.cpp
//  modelowanie_18_POlszowy_lista4
//
//  Created by Jan Śnieg on 25/04/2018.
//

#include "zad2.hpp"
int mainArray[WIDTH][HEIGHT] {0};
bool canGo = true;
ofVec2f wedrownik = ofVec2f(1,1);

std::vector<ofVec2f> checkOnes()
{
    std::vector<ofVec2f> ones;
    for (auto i=0; i<WIDTH; i++)
    {
        for (auto j=0; j<HEIGHT; j++)
        {
            if (mainArray[i][j] == 1)
                ones.push_back(ofVec2f(i,j));
        }
    }
    return ones;
}

zlepek zadanie2(zlepek zlep)
{
    ofVec2f middle = ofVec2f(WIDTH/2, HEIGHT/2);

    std::mt19937 gen{std::random_device{}()};
    std::vector<ofVec2f> ones = checkOnes();
    //n = sprawdzanie ilości możliwych pozycji
    int max = ones.size();
    std::uniform_real_distribution<double> generateAlfa{0, 2*PI};
    //losowania punktu na okręgu
    double kat = generateAlfa(gen);
    wedrownik = ofVec2f((int)(middle.x + RADIOUS*cos(kat)),
                        (int)(middle.y + RADIOUS*sin(kat)));
    std::vector<ofVec2f> wayOut =
    {ofVec2f(0,1), ofVec2f(0,-1), ofVec2f(1,0), ofVec2f(-1,0)};
    //vector posiadający wszystkie cztery możliwe drogi
    bool isGoing = true;
    do {
        std::uniform_int_distribution<int> generateInt{0, 3};
        int los = generateInt(gen);
        wedrownik += wayOut[los];
        if (mainArray[(int)wedrownik.x][(int)wedrownik.y] == 1)
        {
            zlep.addPos(wedrownik);
            isGoing = false;
        }
    } while (isGoing &&
             wedrownik.x<WIDTH && wedrownik.x>0 &&
             wedrownik.y<HEIGHT && wedrownik.y>0);
    return zlep;
}

void drawWedrownik(ofVec2f wedrownik)
{
    ofSetColor(200, 10, 10);
    ofDrawRectangle(wedrownik, STEP, STEP);
}

void drawZlep(zlepek zlep)
{
    
    for(auto i=0; i<zlep.position.size(); i++)
    {
        ofSetColor(zlep.color);
        zlep.color += (1,0,0);
        ofDrawRectangle(zlep.position[i], STEP, STEP);
    }
    
}

