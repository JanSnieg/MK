//
//  ball.hpp
//  modelowanie_18_POlszowy_lista8
//
//  Created by Jan Śnieg on 03/06/2018.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include "ofMain.h"

struct forces
{
    double gravity;
    double drag;

//    Constructor
    forces(double _gravity = 9.81, double _drag = 0)
    :gravity(_gravity), drag(_drag){}

};

struct ball
{
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f force;
    double mass;
    
//    Constructor
    ball(ofVec2f _pos = ofVec2f(0,212), ofVec2f _vel = ofVec2f(0,0), ofVec2f _f = ofVec2f(0,0), double _mass = 0.01)
    :position(_pos), velocity(_vel), mass(_mass){}
    
//    Methods
    void newForce()
    {
        
    }
    void newVelocity()
    {
        
    }
    void NewPosition()
    {
        
    }
};

#endif /* ball_hpp */
