#include "zad3.hpp"

ofPolyline walkway3(ofPolyline line)
{
    WalkerPositionZad3 walker;
    line.begin();
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{-3,3};
    for (int i=0; i<1000; i++)
    {
        int los;
        do
            los = generate(gen);
        while (!los);
        int absLos = abs(los);
        if (absLos == 1) //-1 albo 1
            //x
            walker.x += (los);
        else if (absLos == 2)         //-2 albo 2
            //y
            walker.y += (los/2);
        else
            walker.z += (los/3);
        line.addVertex(ofPoint(walker.x, walker.y, walker.z));
    }
    line.end();
    return line;
}
