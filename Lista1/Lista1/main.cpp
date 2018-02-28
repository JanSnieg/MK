
#include <iostream>
#include <random>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <ctime>

int sukces = 0;

void Kula3D (int pointsInSquare)
{
        std::mt19937 gen{std::random_device{}()};
        std::uniform_real_distribution<double> generate{-1.0,1.0};
        int pointsInCircle = 0;
    
        double x, y, z;
        for (int i=0; i<pointsInSquare; ++i)
        {
            x = generate(gen);
            y = generate(gen);
            z = generate(gen);
    
            if (x*x + y*y + z*z <= 1)
                ++pointsInCircle;
        }
        double Objetosc = ((double)pointsInCircle/pointsInSquare) * 8.0 ;
        double LiczbaPi = Objetosc * 3.0/4.0;
        double Prawdopodobienstwo;
        if (pointsInCircle != 0)
            Prawdopodobienstwo = (double)pointsInCircle/pointsInSquare*100;
        else
            Prawdopodobienstwo = 0;
        std::cout << "Liczba losowanych punktow:\t\t" << pointsInSquare;
        std::cout << "\nLiczba punktow w kuli:\t\t\t" << pointsInCircle;
        std::cout << "\nObjetosc Kuli 3D:\t\t\t\t" << Objetosc;
        std::cout << "\nWyliczona liczba PI:\t\t\t" << LiczbaPi;
        std::cout << "\nPrawdopodobienstwo trafienia:\t" << Prawdopodobienstwo << "%\n\n";
}

void Kula15D (int pointsInCube)
{
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{-1., 1.};
    int pointsInBall = 0;

    for (int i=0; i<pointsInCube; ++i)
    {
        //inicialization of 15 dimensions
        double distance = 0;
        for (int i =0; i<15; i++)
        {
            double randomPoint = generate(gen);
            distance += (double)randomPoint*randomPoint;
            
        }
        if (distance <= 1)
            ++pointsInBall;
    }
    double Objetosc = pow(2, 15) * pointsInBall/pointsInCube;
    double Prawdopodobienstwo;
    if (pointsInBall != 0)
        Prawdopodobienstwo = (double)pointsInBall/(pointsInCube*100);
    else
        Prawdopodobienstwo = 0;
    std::cout << "Liczba losowanych punktow:\t\t" << pointsInCube;
    std::cout << "\nLiczba punktow w kuli:\t\t\t" << pointsInBall;
    std::cout << "\nObjetosc Kuli 15D:\t\t\t\t" << Objetosc;
    std::cout << "\nPrawdopodobienstwo trafienia:\t" << Prawdopodobienstwo << "%\n\n";
}

double Calka(int N)
{
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{-2.,2.};
    double result = 0;
    for (int i=0; i<N; i++)
    {
        double punkt = generate(gen);
        result += 1/sqrt(2 * M_PI) * std::exp((-punkt*punkt)/2);
    }
    return (result/N) * 4;
}

void Tasowanie(int N)
{
    unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();
    std::vector<int> talia;
    //Generate card deck
    for (int i=0; i<N; i++)
    {
        talia.push_back(i);
    }
    //Shuffle deck
    shuffle (talia.begin(), talia.end(), std::default_random_engine(seed));
    //Pull card
    for (int i=0; i<talia.size(); i++)
    {
        if (i == talia[i])
        {
            sukces++;
        }
//        talia.erase(talia.begin());
    }
    
}

int main(int argc, const char * argv[])
{
    std::cout << "\t------ KULA 3D -----\n\n";
    Kula3D(100);
    Kula3D(10000);
    Kula3D(1000000);
    std::cout << "\t------ KULA 15D -----\n\n";
    Kula15D(100);
    Kula15D(10000);
    Kula15D(1000000);
    int N = 100000;
    std::cout << "\t----- CALKA -----\n\n";
    std::cout << "N:\t" << N << "\tSrednia:\t" << Calka(N) << std::endl;
    std::cout << "\t----- TALIA -----\n\n";
    int liczbaLosowan = 10000;
    std::cout << "Liczba losowań w tali ze 100 kartami:\t" << liczbaLosowan << std::endl;
    for (int i =0; i<liczbaLosowan; i++)
    {
        Tasowanie(100);
    }
    std::cout << "liczba suksecow:\t\t\t\t\t\t" << sukces << "\nPrawdopodobienstwo:\t\t\t\t\t\t" << (double)sukces/liczbaLosowan << "%\n";
    return 0;
}
