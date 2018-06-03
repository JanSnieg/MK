#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    mRenderer.setup(ofGetWidth(), ofGetHeight());
    las = forest(100, 0.42);
    count = 0;
    gui.setup();
    gui.add(velocity.setup("Velocity: ", 60, 0, 120));
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (ofGetFrameNum()%velocity == 0)
    {
        if(las.canBurn)
        {
            if(count == 0)
            {
//                mRenderer.start();
                las.start();
            }
            else
            {
                las.burnAll();
                las.changeJustAdded();
                las.checkIfBurning();
            }
            count++;
//            las.countBurned();
        }
//        else
//            mRenderer.stop();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
//    mRenderer.begin();
    ofSetBackgroundColor(30,30,30);
    las.drawForest();
    ofDrawBitmapStringHighlight("Zliczanie kroków: " + ofToString(count), 800,20);
//    ofDrawBitmapStringHighlight("Spalone: " + ofToString(las.spalone) + "/" + ofToString(las.wszystkie), 800,60);
    ofDrawBitmapStringHighlight("Wielkosc siatki (L): " + ofToString(las.lenght) + "\nPrawdopodobieństwo 42%", 800,40);
    gui.draw();
//    mRendearer.end();
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
