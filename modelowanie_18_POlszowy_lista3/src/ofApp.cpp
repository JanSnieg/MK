#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundColor(176, 179, 191);
    ofSetLineWidth(5);
    cam.setDistance(50);
    walker1b = walker10000();
    
//    line1 = walkway(line1);
    
//    line2 = walkway2(line2);
    
    line3 = walkway3(line3);
    
    statistics();
    statistics5();
}

//--------------------------------------------------------------
void ofApp::update()
{
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    cam.begin();
//    ofSetColor(98, 178, 58);
//    line1.draw();
//    ofSetColor(127, 38, 0);
//    line2.draw();
    ofSetColor(254, 125, 70);
    line3.draw();
    cam.end();
    ofDrawBitmapStringHighlight("Count dla 10000 wędrowniczków: " + ofToString(walker1b), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
