#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (zlep.position.size() <1000)
    {
        if(canExtand)
        {
            zlep = zadanie2(zlep);
            ones = checkOnes();
        }
    }
    else
        canExtand = false;
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofDrawBitmapStringHighlight("ILOSC MOZLIWYCH MIEJSC DO WPISANIA: " + ofToString(ones.size()) +
        "\nILOSC WPISANYCH: " + ofToString(zlep.position.size()), 20,20);
    drawCircle();
    drawZlep(zlep);
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
