#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    
}

//--------------------------------------------------------------
void ofApp::update()
{
     if (ofGetFrameNum()%120 == 0)
     {
         if(count == 0)
         {
             ofVec2f start = ofVec2f(ofGetWidth()-100, 150);
             double lenght = ofGetWidth() - 200;
             lines.push_back( new Line( start, lenght, 180.0) );
             lines.push_back( new Line( ofVec2f(100, 150), lenght, 60.0) );
             Line* lineS = new Line( start, lenght, 120.0);
             lineS->position.x += cos(lineS->angle *(M_PI/180.0))*lineS->length;
             lineS->position.y += sin(lineS->angle *(M_PI/180.0))*lineS->length;
             lineS->angle -= 180.0;
             lines.push_back( lineS );
         }
         else
             Koch(lines);
         count ++;
     }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (auto&& i : lines)
    {
        ofDrawBitmapStringHighlight("Count: " + ofToString(count), 20,20);
        i->draw();
    }
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
