#include "tipApp.h"

//--------------------------------------------------------------
void tipApp::setup(){
    ofBackground(0,0,0);
    ofSetWindowTitle("Tips and Tricks");
    
}

//--------------------------------------------------------------
void tipApp::update(){
    
}

//--------------------------------------------------------------
void tipApp::draw(){
//    ofBackground(0,0,0);
    //myFont.loadFont("arial.ttf", 32);
    ofDrawBitmapString("Tips and Tricks", 160, 20);
    
    // Line of Tips
    ofDrawBitmapString("1. To rotate an Image, hold CTRL and move mouse.", 20, 60);
    ofDrawBitmapString("2. Multiple selection of images works.", 20, 100);
    ofDrawBitmapString("3. You can use the key 'D' to delete an image(s).", 20, 140);
    ofDrawBitmapString("4. To superimpose an image use 's' and to send an", 20, 180);
    ofDrawBitmapString("   image behind another, use 'b'.", 20, 200);
    ofDrawBitmapString("5. To move the image, please use the arrow keys", 20, 240);
    ofDrawBitmapString("   or drag the image with the mouse.", 20, 260);
    ofDrawBitmapString("6. Please use 'o' to enlarge the picture, while ", 20, 300);
    ofDrawBitmapString("   'i' can be used to shrink the picture..", 20, 320);
    
    // Final Tips
    ofDrawBitmapString("App was built by Sharan Duggirala", 20, 400);
}

//--------------------------------------------------------------
void tipApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void tipApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void tipApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void tipApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void tipApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void tipApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void tipApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void tipApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void tipApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void tipApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void tipApp::dragEvent(ofDragInfo dragInfo){
    
}



