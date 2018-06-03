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

ofVec2f next_log(ofVec2f v)
{
    return ofVec2f(log(abs(4 * v.y * (1- (2*v.x)))), v.y);
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
        
        for(auto i=0; i<10000; i++)
        {
            temp = next_value(ofVec2f(temp.x, _r));
        }
        temp;
        for(auto i=0; i<100; i++)
        {
            temp = next_value((ofVec2f(temp.x, _r)));
            t.push_back(temp);
        }
    }
    return t;
}
std::vector<ofVec2f> Lyapunov(std::vector<ofVec2f> t)
{
    t.clear();
    for(double _r=0.7; _r<1; _r+=0.0001)
    {
        std::vector<double> result;
        double x = 0.1;
        for(auto i=0; i<100; i++)
        {
            x = next_value(ofVec2f(x, _r)).x;
            result.push_back(next_log(ofVec2f(x, _r)).x);
        }
        double average = std::accumulate(result.begin(), result.end(), 0.0) / result.size();
        t.push_back(ofVec2f(average, _r));
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
    ofSetColor(63, 120, 0);
    for(auto&& i : _t)
    {
        double newx = ofGetWidth() * ((i.y - 0.7)/0.3);
        double newy = ofGetHeight() * i.x;
        line.addVertex(ofVec2f(newx, newy));
    }
    line.draw();
}
void draw_points2(std::vector<ofVec2f> _t)
{
    ofSetColor(63, 120, 0);
    for(auto&& i : _t)
    {
        double newx = ofGetWidth() * ((i.y - 0.7)/0.3);
        double newy = ofGetHeight() * i.x;
        ofDrawCircle(ofVec2f(newx,newy), 2);
    }
}
void draw_points3(std::vector<ofVec2f> _t)
{
    ofSetColor(63, 120, 0);
    for(auto&& i : _t)
    {
        double newx = ofGetWidth() * ((i.y - 0.92)/0.03);
        double newy = ofGetHeight() * i.x;
        ofDrawCircle(ofVec2f(newx,newy), 2);
    }
}
void draw_points4(std::vector<ofVec2f> _t)
{
    ofSetColor(63, 120, 0);
    for(auto&& i : _t)
    {
        double newx = ofGetWidth() * ((i.y - 0.7)/0.3);
        double newy = ofGetHeight() * ((i.x + 4)/5);
        ofDrawCircle(ofVec2f(newx,newy), 2);
    }
}
void draw_line4(std::vector<ofVec2f> _t)
{
    ofPolyline line;
    ofSetColor(63, 120, 0);
    for(auto&& i : _t)
    {
        double newx = ofGetWidth() * ((i.y - 0.7)/0.3);
        double newy = ofGetHeight() * ((i.x + 4)/5);
        line.addVertex(ofVec2f(newx, newy));
    }
    line.draw();
}
