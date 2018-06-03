//
//  zad1.hpp
//  modelowanie_18_POlszowy_lista6
//
//  Created by Jan Śnieg on 02/06/2018.
//

#ifndef zad1_hpp
#define zad1_hpp

#include <stdio.h>
#include <random>
#include <vector>
#include "ofMain.h"


// xn+1=4rxn(1- xn), gdzie 0< r ≤1, 0≤ xn ≤1, n=0,1,2, ...

const double r_const [7] = {0.2, 0.5, 0.8, 0.88, 0.92 , 0.96, 1.};
const int SIDE = 5;

extern double wylosuj();
extern ofVec2f next_value(ofVec2f);
extern ofVec2f next_log(ofVec2f);
extern std::vector<ofVec2f> odwzorowanie(std::vector<ofVec2f> t, double r);
extern std::vector<ofVec2f> odwzorowanie_graniczne(std::vector<ofVec2f> t);
std::vector<ofVec2f> Lyapunov(std::vector<ofVec2f> t);

extern void draw_points(std::vector<ofVec2f> _t);
extern void draw_line(std::vector<ofVec2f> _t);
extern void draw_points2(std::vector<ofVec2f> _t);
extern void draw_line2(std::vector<ofVec2f> _t);
extern void draw_points3(std::vector<ofVec2f> _t);
extern void draw_line4(std::vector<ofVec2f> _t);
extern void draw_points4(std::vector<ofVec2f> _t);


#endif /* zad1_hpp */
