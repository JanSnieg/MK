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

struct tree
{
    ofVec2f position;
    int state = 0;
//    int timer = 0;
    /*3 stany:
     0: alive
     1: burning
     2: burned*/
    ofColor treeColor =  ofColor(70,130,0);
    bool justAdded = false;
    tree(int _x, int _y)
    {
        position.x = _x;
        position.y = _y;
    }
    tree(ofVec2f pos)
    {
        position = pos;
    }
    void setColor()
    {
        switch(state)
        {
            case 0:
                treeColor.set(70,130,0);
                break;
            case 1:
                treeColor.set(250,50,0);
                break;
            case 2:
                treeColor.set(120,120,120);
                break;
            default:
                treeColor.set(70,130,0);
                break;
        }
    }
    void burnOut()
    {
        switch(state)
        {
            case 0:
                state = 1;
                break;
            case 1:
                state = 2;
                break;
            default:
                state = 0;
                break;
        }
    }
};

struct forest
{
    std::vector<tree> forestVector;
    int lenght;
    bool canBurn = true;
    int wszystkie;
    int spalone;
    int RADIOUS;
    int WIDTH = ofGetWidth() * 0.9;
    int HEIGHT = ofGetHeight() * 0.9;
    forest(int l = 10, double p = 0.5)
    {
        lenght = l;
        RADIOUS = ofGetHeight() / (2 * lenght);
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
        wszystkie = forestVector.size();
    }
//    metoda rozpoczynająca palenie sie lasu, poprzez podpalanie pierwszej kolumny
    void start()
    {
        for(auto&& drzewo : forestVector)
        {
            if(drzewo.position.x == 0)
                drzewo.state = 1;
        }
    }
//    metoda paląca las
    void burnAll()
    {
        for(auto&& drzewo : forestVector)
        {
            if(drzewo.state == 1 && !drzewo.justAdded)
            {
                for(auto&& drzewo2 : forestVector)
                {
                    double distance = drzewo.position.distance(drzewo2.position);
                    if(distance < 2 && distance > 0 && drzewo2.state == 0 && !drzewo.justAdded)
                    {
                        drzewo2.state = 1;
                        drzewo2.justAdded = true;
                    }
                }
                drzewo.burnOut();
            }
        }
    }
    void changeJustAdded()
    {
        for(auto&& drzewo : forestVector)
            drzewo.justAdded = false;
    }
    void checkIfBurning()
    {
        for(auto&& drzewo : forestVector)
            if(drzewo.state == 1)
                return;
        canBurn = false;
    }
    void countBurned()
    {
        int count=0;
        for (auto drzewo : forestVector)
        {
            if(drzewo.state > 1)
                count ++;
        }
        spalone = count;
    }
    
    void drawForest()
    {
        for(auto&& drzewo : forestVector)
        {
            drzewo.setColor();
            ofSetColor(drzewo.treeColor);
            double scaledx = WIDTH * ((drzewo.position.x) / lenght) + ofGetWidth() * 0.05;
            double scaledy = HEIGHT * ((drzewo.position.y) / lenght) + ofGetHeight() * 0.05;
            ofDrawCircle(ofVec2f(scaledx, scaledy), RADIOUS);
        }
    }
    
    void burnOneAtTheTime()
    {
        for(auto&& drzewo : forestVector)
        {
            std::vector<int> neightbours;
            if(drzewo.state == 1 && !drzewo.justAdded)
            {
                int k = 0;
                for(auto drzewo2 : forestVector)
                {
                    double distance = drzewo.position.distance(drzewo2.position);
                    if(distance < 2 && distance > 0 && drzewo2.state == 0 && !drzewo2.justAdded)
                        neightbours.push_back(k);
                    k++;
                }
                std::mt19937 gen{std::random_device{}()};
                
                if(neightbours.size() > 0)
                {
                    int max = (int)neightbours.size()-1;
                    std::uniform_int_distribution<int> generate{0, max};
                    int los = generate(gen);
                    forestVector[neightbours[los]].state = 1;
                    forestVector[neightbours[los]].justAdded = true;
                }
                //                spalić tego co zaczął
                drzewo.burnOut();
            }
        }
    }
};

#endif /* zad2_hpp */
