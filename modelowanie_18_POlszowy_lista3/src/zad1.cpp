#include "zad1.h"

ofPolyline walkway(ofPolyline line)
{
    WalkerPosition walker;
    line.begin();
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{-2,2};
    for (int i=0; i<1000; i++)
    {
        int los = generate(gen);
        if (los != 0)
        {
            if (los%2 != 0) //-1 albo 1
    //            poziomo
                walker.x += (los*20);
            else            //-2 albo 2
    //            pionowo
                walker.y += (los*10);
        }
        else
            i --;
        line.addVertex(ofVec2f(walker.x, walker.y));
    }
    line.end();
    return line;
}

int walker10000()
{
    WalkerPosition walker;
    int count =0;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{-2,2};
    for (int i=0; i<1000; i++)
    {
        for (int j=0; j<100; j++)
        {
            int los = generate(gen);
            if (los != 0)
            {
                if (los%2 != 0) //-1 albo 1
                    //            poziomo
                    walker.x += los;
                else            //-2 albo 2
                    //            pionowo
                    walker.y += los/2;
            }
            else
                i --;
        }
        if (walker.x == ofGetWidth()/2 && walker.y == ofGetHeight()/2)
            count ++;
    }
    return count;
}
