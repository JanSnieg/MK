#pragma once

#include "zad1.h"
#include "zad2.hpp"
#include "zad3.hpp"
#include "zad4.hpp"
#include "zad5.hpp"

class ofApp : public ofBaseApp{

	public:
    ofPolyline line1;
    ofPolyline line2;
    ofPolyline line3;
    ofEasyCam cam;
    int walker1b;
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
