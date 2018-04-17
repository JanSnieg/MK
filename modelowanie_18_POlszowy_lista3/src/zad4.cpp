//
//  zad4.cpp
//  modelowanie_18_POlszowy_lista3
//
//  Created by Jan Śnieg on 11/04/2018.
//

#include "zad4.hpp"
rainDrop raining (rainDrop drop)
{
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{0,1};
    int czasSpadku=0;
    /*(0., 0.6) dół     ↓
     (0.6, 0.7) góra    ↑
     (0.7, 0.85) lewo   ←
     (0.85, 1) prawo    →
     */
    do {
        double los = generate(gen);
        if(los < 0.6)
            drop.y--;
        else if (los < 0.7)
            drop.y++;
        else if (los < 0.85)
            drop.x--;
        else
            drop.x++;
        drop.czasSpadku++;
    } while (drop.y > 0);
    return drop;
}

void statistics()
{
    std::ofstream avDev;
    avDev.open("/Users/jansnieg/Documents/ISSP6/MK/modelowanie_18_POlszowy_lista3/zad3Odchylenie.txt");
    std::vector<double> odchylenie;
    double sredniCzasSpadku = 0;
    for (int i=0; i<10; i++)
        odchylenie.push_back(0);
    for(int i=100; i<1000; i+=100)
    {
        rainDrop drop = rainDrop(i);
        drop = raining(drop);
        sredniCzasSpadku += drop.czasSpadku;
        odchylenie[i/100] += (double)(drop.x * drop.x)/drop.czasSpadku;
        int calkowita = (int)odchylenie[i/100];
        unsigned int dziesietna = odchylenie[i/100]*1000;
        avDev << i << "\t" << calkowita << "," << dziesietna << std::endl;
    }
    avDev << "\t\tSREDNI CZAS SPADKU: \t" << sredniCzasSpadku/10 << std::endl;
    avDev.close();
    
}
