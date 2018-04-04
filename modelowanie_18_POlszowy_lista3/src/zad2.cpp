//
//  zad2.cpp
//  modelowanie_18_POlszowy_lista3
//
//  Created by Jan Śnieg on 28/03/2018.
//

#include "zad2.hpp"

ofPolyline walkway2(ofPolyline line)
{
    int step = 15;
    int count=0;
    Walker2 walker2;
    bool positionArr[1024][768];
    line.begin();
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,3};
    bool canGo = true;
    do
    {
        int los;
        bool canGoArr[4] {true, true, true, true};
        //checking if can go
        if (positionArr[walker2.x+step][walker2.y])
            canGoArr[0] = false;    //right
        if (positionArr[walker2.x-step][walker2.y])
            canGoArr[1] = false;    //left
        if (positionArr[walker2.x][walker2.y+step])
            canGoArr[2] = false;    //up
        if (positionArr[walker2.x][walker2.y-step])
            canGoArr[3] = false;    //down
        if (!canGoArr[0] && !canGoArr[1] && !canGoArr[2] && !canGoArr[3])
            canGo = false;
        if(canGo)
        {
            do
                los = generate(gen);
            while (!canGoArr[los]);
        }
        //sprawdzanie czy gdzie może pójść
        switch (los)
        {
            case 0:
                walker2.x += step;
                break;
            case 1:
                walker2.x -= step;
                break;
            case 2:
                walker2.y += step;
                break;
            case 3:
                walker2.y -= step;
                break;
            default:
                break;
        }
        count ++;
        positionArr[walker2.x][walker2.y] = true;
        line.addVertex(ofVec2f(walker2.x, walker2.y));
    } while (canGo);
    line.end();
    std::cout << count;
    return line;
}
