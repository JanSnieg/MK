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

std::vector<int> TIMEVECTOR;

void zad1()
{
    //pojedyńczy walker
    int position =0;
    std::ofstream myExcelFile;
    myExcelFile.open("/Users/jansnieg/Documents/ISSP6/MK/zad1a.csv");
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{0.,1.0};
    for (int i=0; i<100; i++)
    {
        if(generate(gen) < 0.5 )
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
    int range = 10000;
    for (int i=0; i<=200; i++)
    {
        lastPosition.push_back(0);
    }
    for (int i=0; i<range; i++)
    {
        position = 0;
        for (int j=0; j<100; j++)
        {
            if(generate(gen) < 0.5 )
                position --;
            else
                position++;
        }

        lastPosition[position+100] ++;
    }
    for (int i=0; i<lastPosition.size(); i++)
        myExcelFile << lastPosition[i] << std::endl;
    myExcelFile.close();
}

void zad2(double szansa)
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
            p = szansa;
            position --;
        }
        else
        {
            p = 1 - szansa;
            position++;
        }
        myExcelFile << position << std::endl;
    }
    myExcelFile.close();
    std::ofstream avDev;
    avDev.open("/Users/jansnieg/Documents/ISSP6/MK/modelowanie_18_POlszowy_lista2/zad2Dev.csv");
    myExcelFile.open("/Users/jansnieg/Documents/ISSP6/MK/modelowanie_18_POlszowy_lista2/zad2b.csv");
    //getting position vector ready
    std::vector<int> lastPosition;
    std::vector<int> deviationVector;
    for (int i=-100; i<=100; i++)
        lastPosition.push_back(0);
    for (int i=0; i<100; i++)
        deviationVector.push_back(0);
    for (int i=0; i<10000; i++)
    {
        int range = 100;
        std::vector<int> positionVector;
        position = 0;
        p = 0.5;
        for (int j=0; j<range; j++)
        {
            if(generate(gen) < p)
            {
                p = szansa;
                position --;
            }
            else
            {
                p = 1 - szansa;
                position++;
            }
            positionVector.push_back(position);
            deviationVector[j] += position*position;
        }
        lastPosition[position+100] ++;
    }
    for (auto i=0; i<deviationVector.size(); i++)
        avDev << (deviationVector[i] /= 10000) << std::endl;
    for (int i=0; i<lastPosition.size(); i++)
    {
        myExcelFile << lastPosition[i] << std::endl;
    }
    myExcelFile.close();
    avDev.close();
}

int zad3(int A, int startposition)
{
    int position;
    int t = 0;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{0.,1.0};
    for (int i=0; i<10000; i++)
    {
        position = startposition;
        int tempt = 0;
        do
        {
            tempt ++;
            if(generate(gen) < 0.5)
                position --;
            else
                position ++;
        } while (position >= 0 && position < 2*A);
        t += tempt;
    }
    return t;
}

void zad2Odchylenie(int range, int szansa)
{
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{0.,1.0};
    std::vector<int> positionVector;
    int position =0;
    double p = 0.5;
    double avDeviation = 0.0;
    for (auto i=0; i<range; i++)
    {
        if(generate(gen) < p)
        {
            p = szansa;
            position --;
        }
        else
        {
            p = 1 - szansa;
            position++;
        }
        positionVector.push_back(position);
    }
    std::cout << "Położenie końcowe: " << position << std::endl;
    double avPosition = (double)position/range;
    std::cout << "Średnie położenie: " << avPosition << std::endl;
    //obliczanie średniego odchylenia kwadratowego
    for (auto i=0; i<positionVector.size(); i++)
        avDeviation += pow((positionVector[i] - avPosition),2);
    avDeviation = sqrt(avDeviation/range);
    std::cout << "Średnie odchylenie kwadratowe: " << avDeviation << std::endl;
    
}

int main(int argc, const char * argv[])
{
//    zad1();
    zad2(0.2);
//    std::ofstream myExcelFile;
//    int A = 5;
//    myExcelFile.open("/Users/jansnieg/Documents/ISSP6/MK/zad3.csv");
//    for(int i=0; i<2*A; i++)
//    {
//        myExcelFile << i << "\t" << zad3(A, i) << std::endl;
//    }
    return 0;
}
