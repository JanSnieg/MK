#include "zad1.h"

ofPolyline walkway(ofPolyline line)
{
    WalkerPosition walker;
    line.begin();
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{-2,2};
    for (int i=0; i<1000; i++)
    {
        int los;
        do
            los = generate(gen);
        while (!los);
        if (los & 1) //-1 albo 1
                     //poziomo
            walker.x += (los * 10);
        else        //-2 albo 2
                    //pionowo
            walker.y += (los * 5);
        line.addVertex(ofVec2f(walker.x, walker.y));
    }
    line.end();
    return line;
}

int walker10000()
{
    WalkerPosition walker;
    walker.x=0;
    walker.y=0;
    int count =0;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{-2,2};
    for (int i=0; i<1000; i++)
    {
        for (int j=0; j<100; j++)
        {
            int los;
            do
                los = generate(gen);
            while (!los);
            if (los & 1) //-1 albo 1
                //            poziomo
                walker.x += los;
            else            //-2 albo 2
                //            pionowo
                walker.y += los/2;
            if (walker.x == 0 && walker.y == 0)
                count++;
        }
    }
    return count;
}
