//
//  main.cpp
//  modelowanie_18_POlszowy_lista2
//
//  Created by Jan Śnieg on 04/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
#include <fstream>

void zad1()
{
    //pojedyńczy walker
    int position =0;
    std::ofstream myExcelFile;
    myExcelFile.open("/Users/jansnieg/Documents/ISSP6/MK/zad1a.csv");
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{-1.0,1.0};
    for (int i=0; i<100; i++)
    {
        if(generate(gen) < 0 )
            position --;
        else
            position++;
        myExcelFile << position << std::endl;
    }
    myExcelFile.close();
    //10000 wedrowniczkow
    myExcelFile.open("/Users/jansnieg/Documents/ISSP6/MK/zad1b.csv");
    //Przygotowanie wektora do wpisywania pozycji
    std::vector<int> lastPosition;
    for (int i=-100; i<=100; i++)
    {
        lastPosition.push_back(0);
    }
    for (int i=0; i<10000; i++)
    {
        position = 0;
        for (int j=0; j<100; j++)
        {
            if(generate(gen) < 0 )
                position --;
            else
                position++;
        }
        lastPosition[position+100] ++;
    }
    for (int i=0; i<lastPosition.size(); i++)
    {
        myExcelFile << lastPosition[i] << std::endl;
    }
    myExcelFile.close();
}

void zad2()
{
    //pojedyńczy walker
    int position =0;
    double p = 0.5;
    std::ofstream myExcelFile;
    myExcelFile.open("/Users/jansnieg/Documents/ISSP6/MK/zad2a.csv");
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{0.,1.0};
    for (int i=0; i<100; i++)
    {
        if(generate(gen) < p)
        {
            p = 0.8;
            position --;
        }
        else
        {
            p = 0.2;
            position++;
        }
        myExcelFile << position << std::endl;
    }
    myExcelFile.close();


    myExcelFile.open("/Users/jansnieg/Documents/ISSP6/MK/zad2b.csv");
    //getting position vector ready
    std::vector<int> lastPosition;
    for (int i=-100; i<=100; i++)
    {
        lastPosition.push_back(0);
    }
    for (int i=0; i<10000; i++)
    {
        position = 0;
        p = 0.5;
        for (int j=0; j<100; j++)
        {
            if(generate(gen) < p )
            {
                p = 0.8;
                position --;
            }
            else
            {
                p = 0.2;
                position++;
            }
        }
        lastPosition[position+100] ++;
    }
    for (int i=0; i<lastPosition.size(); i++)
    {
        myExcelFile << lastPosition[i] << std::endl;
    }
    myExcelFile.close();
}

void zad3(int A)
{
    int position;
    double t = 0;
    double tsrednie;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{0.,1.0};
    for (int i=0; i<10000; i++)
    {
        position = A/2;
        for (int j=0; j<100; j++)
        {
            if (position > 0 || position < A)
            {
                t ++;
                if(generate(gen) < 0.5)
                    position --;
                else
                    position ++;
            }
        }
        std::cout << t/100 << std::endl;
    }
    tsrednie = t/1000000;
    std::cout << tsrednie <<std::endl;
}

int main(int argc, const char * argv[])
{
//    zad1();
//    zad2();
    zad3(5);
    return 0;
}
