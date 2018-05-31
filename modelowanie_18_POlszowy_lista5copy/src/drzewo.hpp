//
//  drzewo.hpp
//  modelowanie_18_POlszowy_lista5
//
//  Created by Jan Śnieg on 23/05/2018.
//

#ifndef drzewo_hpp
#define drzewo_hpp

#include <stdio.h>
#include <iostream>
#include <random>
#include <cmath>
#include "ofMain.h"

static const int RADIOUS = 5;

//static const ofVec2f middle = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);

struct tree
{
    ofVec2f position;
//    std::vector<tree> neightbours;
    int state = 0;
    /*3 stany:
     0: alive
     1: burning
     2: burned*/
    ofColor color =  ofColor(120,120,0);
    tree(int _x, int _y)
    {
        position.x = _x;
        position.y = _y;
    }
    tree(ofVec2f pos)
    {
        position = pos;
    }
    void changeColor()
    {
        if(state == 0)
            color = ofColor(120,120,0);
        else if(state == 1)
            color = ofColor(120,0,0);
        else if(state == 2)
            color = ofColor(120,120,120);
    }
};

struct forest
{
    std::vector<tree> forestVector;
    forest(int l = 50, double p = 0.2)
    {
        std::mt19937 gen{std::random_device{}()};
        std::uniform_real_distribution<double> generate{0, 1};
        
        for(auto i=0; i<l; i++)
        {
            for(auto j=0; j<l ; j++)
            {
                if (generate(gen) <= p)
                    forestVector.push_back(tree(i, j));
            }
        }
    }
//    metoda rozpoczynająca palenie sie lasu, poprzez podpalanie pierwszej kolumny
    void start()
    {
        for(auto i=0; i<forestVector.size(); i++)
        {
            if(forestVector[i].position.x == 0)
                forestVector[i].state = 1;
        }
    }
//    metoda paląca las
    void burn()
    {
        //wywołać dla wszystkich palących się
        for(auto i=0; i<forestVector.size(); i++)
        {
            //jeżeli palący sie ma sąsiada żywego to przenieść ogien
            if(forestVector[i].state == 1)
            {
                for(auto j=0; j<forestVector.size(); j++)
                {
                    double distance = forestVector[i].position.distance(forestVector[j].position);
                    if(i!=j && distance <= sqrt(2) && forestVector[j].state == 0)
                    forestVector[j].state = 1;
                }
            }
        }
    }
//    metoda wypalająca las
    void burnout()
    {
        for(auto i=0; i<forestVector.size(); i++)
        {
            if(forestVector[i].state == 1)
                forestVector[i].state = 2;
        }
    }
//    metoda sprawdzająca czy cały las sie wypalił
    bool isBurned()
    {
        for(auto i=0; i<forestVector.size(); i++)
        {
            if(forestVector[i].state < 2)
                return false;
        }
        return true;
    }
    void drawForest()
    {
        for(auto i=0; i<forestVector.size(); i++)
        {
            forestVector[i].changeColor();
            ofSetColor(forestVector[i].color);
            ofDrawCircle(forestVector[i].position * (2*RADIOUS), RADIOUS);
        }
    }
};

#endif /* zad2_hpp */
