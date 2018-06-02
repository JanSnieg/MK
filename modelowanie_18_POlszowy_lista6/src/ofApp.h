#pragma once
#include "zad1.hpp"

class ofApp : public ofBaseApp{

	public:
    int R = 0;
    double r = r_const[R];
    const double start = wylosuj();
    bool flag = false;
    int zadanie = 1;
    std::vector<ofVec2f> temp;
    std::vector<ofVec2f> t;
    
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
