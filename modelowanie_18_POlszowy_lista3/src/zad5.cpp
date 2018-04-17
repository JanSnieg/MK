//
//  zad5.cpp
//  modelowanie_18_POlszowy_lista3
//
//  Created by Jan Śnieg on 16/04/2018.
//

#include "zad5.hpp"
void statistics5()
{
    int granica[21] = {0};  //granica na prawym boku
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{-2,2};
    std::ofstream txtFile;
    txtFile.open("/Users/jansnieg/Documents/ISSP6/MK/modelowanie_18_POlszowy_lista3/zad5Wezly.txt");
    for (int i=0; i<100000; i++)
    {
        bool canGo = true;
        walkerZad5 walker;
        while(canGo)
        {
            //Sprawdzanie czy nie trafił na węzeł pochłaniający
            if (walker.x == 10)
            {
                granica[walker.y+10]++;
                canGo = false;
            }
            else if (walker.x == -10 || walker.y == 10 || walker.y == -10)
                canGo = false;
            //Losowanie kierunku ruchu
            int los;
            do
                los = generate(gen);
            while (!los);
            //Ruch
            if (los & 1) //-1 albo 1
                //poziomo
                walker.x += los;
            else        //-2 albo 2
                //pionowo
                walker.y += los/2;
        }
    }
    for (int i=0; i<21; i++) {
        txtFile << i-10 << "\t" << granica[i] << std::endl;
    }
}
