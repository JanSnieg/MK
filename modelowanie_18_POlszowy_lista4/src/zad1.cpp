//
//  zad1.cpp
//  modelowanie_18_POlszowy_lista4
//
//  Created by Jan Śnieg on 25/04/2018.
//

#include "zad1.hpp"
int mainArray[WIDTH][HEIGHT] {0};
bool canGo = true;

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

zlepek zadanie1(zlepek zlep)
{
    std::mt19937 gen{std::random_device{}()};
    std::vector<ofVec2f> ones = checkOnes();
    //n = sprawdzanie ilości możliwych pozycji
    int max = ones.size();
    std::uniform_int_distribution<int> generate{0, max-1};
    //losowania od 0-n
    int los = generate(gen);
    ofVec2f wylosowane = ones[los];
    zlep.addPos(wylosowane);
        //wpisanie do vectora pozycji
    return zlep;
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

