//
//  zad1.cpp
//  modelowanie_18_POlszowy_lista6
//
//  Created by Jan Śnieg on 02/06/2018.
//
#include "zad1.hpp"


double wylosuj()
{
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> generate{0, 1};
    return generate(gen);
}

ofVec2f next_value(ofVec2f v)
{
    return ofVec2f(4 * v.y * v.x * (1-v.x), v.y);
}

std::vector<ofVec2f> odwzorowanie(std::vector<ofVec2f> t, double r)
{
    for(auto i=0; i<100; i++)
    {
        t.push_back(next_value(ofVec2f(t[i].x, r)));
    }
    return t;
}

std::vector<ofVec2f> odwzorowanie_graniczne(std::vector<ofVec2f> t)
{
    for(double _r=0.7; _r<1; _r+=0.0001)
    {
        ofVec2f temp = t[0];
        
        for(auto i=0; i<100000; i++)
        {
            temp = next_value(ofVec2f(temp.x, _r));
        }
        t[0] = temp;
        for(auto i=0; i<100; i++)
        {
            t.push_back(next_value(ofVec2f(t[i].x, _r)));
        }
    }
    return t;
}

void draw_points(std::vector<ofVec2f> _t)
{
    ofSetColor(200, 50, 50);
    for(auto i=0; i<_t.size(); i++)
    {
        ofDrawCircle(SIDE + i*10, _t[i].x*100 + 300, SIDE);
    }
}
void draw_line(std::vector<ofVec2f> _t)
{
    ofPolyline line;
    ofSetColor(200, 50, 50);
    for(auto i=0; i<_t.size(); i++)
    {
        line.addVertex(ofVec2f(SIDE + i*10, _t[i].x*100 + 300));
    }
    line.draw();
}

void draw_line2(std::vector<ofVec2f> _t)
{
    ofPolyline line;
    ofSetColor(200, 50, 50);
    for(auto&& i : _t)
    {
//   normalized = (x-min(x))/(max(x)-min(x))
        double newx = ofGetWidth() * ((i.y - 0.7)/0.3);
        double newy = ofGetHeight() * i.x;
        line.addVertex(ofVec2f(newx, newy));
    }
    line.draw();
}
void draw_points2(std::vector<ofVec2f> _t)
{
    ofSetColor(200, 50, 50);
    for(auto&& i : _t)
    {
        double newx = ofGetWidth() * ((i.y - 0.7)/0.3);
        double newy = ofGetHeight() * i.x;
        ofDrawCircle(ofVec2f(newx,newy), 2);
    }
}
