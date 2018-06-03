#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    t.push_back(ofVec2f(start,0));
    graniczne = odwzorowanie_graniczne(t);
    lypanov = Lyapunov(t);
    std::cout << graniczne.size();
    
}

//--------------------------------------------------------------
void ofApp::update()
{
    switch(zadanie)
    {
        case 1:
            t.clear();
            r = r_const[R];
            t.push_back(ofVec2f(start,r));
            t = odwzorowanie(t,r);
            break;
        case 2:
            t = graniczne;
            break;
        case 3:
            t = graniczne;
            break;
        case 4:
            t = lypanov;
            break;
        default:
            t = odwzorowanie(t,r);
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapStringHighlight("ZADANIE: " + ofToString(zadanie), 20, 40);
    if(zadanie == 4)
    {
        if(flag)
            draw_line4(t);
        else
            draw_points4(t);
    }
    if(zadanie == 3)
    {
        draw_points3(t);
    }
    if(zadanie == 2)
    {
        if(flag)
            draw_line2(t);
        else
            draw_points2(t);
    }
    if(zadanie == 1)
    {
        ofDrawBitmapStringHighlight("R: " + ofToString(r), 20, 20);
        if(flag)
            draw_points(t);
        else
            draw_line(t);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == '1')
        zadanie = 1;
    if(key == '2')
        zadanie = 2;
    if(key == '3')
        zadanie = 3;
    if(key == '4')
        zadanie = 4;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if(key == ' ')
        flag = !flag;
    if(key == OF_KEY_UP || key == OF_KEY_RIGHT)
    {
        R = R < 6 ? R+1 : 0;
    }
    if(key == OF_KEY_DOWN || key == OF_KEY_LEFT)
    {
        R = R > 0 ? R-1 : 6;
    }
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
