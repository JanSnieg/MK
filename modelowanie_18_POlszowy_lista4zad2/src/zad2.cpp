//
//  zad2.cpp
//  modelowanie_18_POlszowy_lista4
//
//  Created by Jan Śnieg on 25/04/2018.
//

#include "zad2.hpp"
int mainArray[WIDTH][HEIGHT] {0};
bool canExtand = true;
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
    //Początkowe koordunaty wedrownika
    std::vector<ofVec2f> wayOut =
    {ofVec2f(0,1), ofVec2f(0,-1), ofVec2f(1,0), ofVec2f(-1,0)};
    //vector posiadający wszystkie cztery możliwe drogi
    bool isGoing = true;
    do {
        std::uniform_int_distribution<int> generateInt{0, 3};
        int los = generateInt(gen);
        wedrownik += wayOut[los];
        //przesunięcie wędrowniczka
        if (mainArray[(int)wedrownik.x][(int)wedrownik.y] == 1)
        {
            zlep.addPos(wedrownik);
            isGoing = false;
        }
    } while (isGoing && middle.distance(wedrownik) < RADIOUS + 10);
    return zlep;
}

void drawZlep(zlepek zlep)
{
    ofColor color = (100, 50, 0);
    short c=0;
    for(auto i=0; i<zlep.position.size(); i++, c++)
    {
        if (c==10)
        {
            color += (0,2,1);
            c=0;
        }
        ofSetColor(color);
        ofDrawRectangle(zlep.position[i], STEP, STEP);
    }
    
}
void drawCircle()
{
    ofSetColor(255,255,255);
    ofDrawCircle(WIDTH/2, HEIGHT/2, RADIOUS);
    ofSetColor(0, 0, 100, 100);
    ofDrawCircle(WIDTH/2, HEIGHT/2, RADIOUS+10);
}

