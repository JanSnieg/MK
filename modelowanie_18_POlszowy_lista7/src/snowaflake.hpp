//
//  snowaflake.hpp
//  modelowanie_18_POlszowy_lista7
//
//  Created by Jan Śnieg on 03/06/2018.
//

#ifndef snowaflake_hpp
#define snowaflake_hpp

#include <stdio.h>
#include "ofMain.h"
#include <cmath>
#include <list>

class Line
{
public:
    ofVec2f position;
    double length, angle;
    
    Line(ofVec2f _position, double _length, double _angle)
    :position(_position), length(_length), angle(_angle)
    {}
    
    ofVec2f getNewCoords()
    {
        int x = position.x+cos(angle*(M_PI/180.0))*length;
        int y = position.y+sin(angle*(M_PI/180.0))*length;
        return ofVec2f(x, y);
    }
    
    void draw()
    {
        ofSetColor(120, 0, 0);
        ofDrawLine(position, getNewCoords());
    }
};

extern void Koch(std::list<Line*> &lines);


#endif /* snowaflake_hpp */
