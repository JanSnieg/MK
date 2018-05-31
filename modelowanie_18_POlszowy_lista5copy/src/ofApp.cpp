#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    las = forest();
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (ofGetFrameNum()%60 == 0)
    {
        if(!las.isBurned())
        {
            if(count < 1)
                las.start();
            count++;
            las.burn();
            las.burnout();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    las.drawForest();
    ofDrawBitmapStringHighlight("Zliczanie kroków: " + ofToString(count), 20,20);
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
