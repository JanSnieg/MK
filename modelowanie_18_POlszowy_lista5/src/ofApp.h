#pragma once

#include "drzewo.hpp"
#include "ofxSimpleScreenRecorder.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
	public:
        forest las;
        ofxSimpleScreenRecorder mRenderer;
        ofxIntSlider velocity;
        ofxPanel gui;
        int count;
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
