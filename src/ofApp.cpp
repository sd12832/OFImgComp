#include "ofApp.h"
#include "ofEasyCam.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //bckg.load("images/bckg_img.png");
    addImg.load("images/add_img.png");
    savImg.load("images/sav_img.png");
    curImg.load("images/cur_img.png");
    rotImg.load("images/rot_img.png");
    //zouImg.load("images/zin_img.png");
    //zinImg.load("images/zou_img.png");
    curImg.resize(100,100);
    rotImg.resize(100,100);
    ofBackground(211,211,211);
    ofSetWindowTitle("Sharan's Image Compositor");
    
    ofDisableDepthTest();
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    /*
    // this sets the camera's distance from the object
    cam.setDistance(1000);
    cam.disableMouseInput();
    cam.disableRotation();
    cam.setFarClip(-100);
    */
    
    //
    // set when <control> key is held down
    //
    ctrlKeyDown = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Normal Background
    ofBackground(211,211,211);
    
    // Background Grid Draw for Debugging
//    for(int i = 0; i < ofGetScreenHeight(); i += bckg.getHeight()){
//        for(int j = 0; j < ofGetScreenWidth(); j += bckg.getWidth()){
//            bckg.draw(j, i);
//        }
//    }
    
    // The Images Adding Feature
    for (int i = 0; i < images.size(); i++)
        images[i]->draw();
    
    if (scrshot) {
        screenshotGrab();
        scrshot = false;
    } else {
        // Button Draw
        addImg.draw(20,10);
        savImg.draw(20,60);
        //zouImg.draw(250,15);
        //zinImg.draw(200,15);
    }
    
    if (dragCursor) {
        ofHideCursor();
        curImg.draw(cursorx-50,cursory-50);
    }
    
    if(rotCursor) {
        ofHideCursor();
        rotImg.draw(cursorx-50,cursory-50);
    }
   
}

void ofApp::exit() {
    for (int i = 0; i < images.size(); i++) {
        delete images[i];
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
//        case 'C':
//        case 'c':
//            if (cam.getMouseInputEnabled()) cam.disableMouseInput();
//            else cam.enableMouseInput();
//            break;
        case 'F':
        case 'f':
            ofToggleFullscreen();
            break;
        case 'H':
        case 'h':
            break;
        case 'r':
            cam.reset();
            break;
        case OF_KEY_ALT:
            cam.enableMouseInput();
            break;
        case OF_KEY_CONTROL:
            ctrlKeyDown = true;
            break;
        case 'D' :
            deleteImgFunc();
            break;
        case OF_KEY_UP:
            moveImg('u');
            break;
        case OF_KEY_DOWN:
            moveImg('d');
            break;
        case OF_KEY_LEFT:
            moveImg('l');
            break;
        case OF_KEY_RIGHT:
            moveImg('r');
            break;
        case 's':
            stackOrder(0);
            break;
        case 'b':
            stackOrder(1);
            break;
        case 'i':
            zoom('i');
            break;
        case 'o':
            zoom('o');
            break;
            
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
//        case OF_KEY_ALT:
//            cam.disableMouseInput();
//            break;
        case OF_KEY_CONTROL:
            ctrlKeyDown = false;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (!selectedImage) return;
    if (ctrlKeyDown) {
        rotCursor = true;
        cursorx = x;
        cursory = y;
        doMouseRotation(x, y);
    }
    else {
        dragCursor = true;
        cursorx = x;
        cursory = y;
        selectedImage->trans.x = x;
        selectedImage->trans.y = y;
    }
    
}

//---------------------------------------------------------------

//                  Button and Key Functions                    //

//----------------------------------------------------------------

void ofApp::moveImg (char c) {
    
    switch (c) {
        case 'u':
            if(!selectedImage) break;
            selectedImage->trans.y -= 5;
            break;
        case 'd':
            if(!selectedImage) break;
            selectedImage->trans.y += 5;
            break;
        case 'l':
            if(!selectedImage) break;
            selectedImage->trans.x -= 5;
            break;
        case 'r':
            if(!selectedImage) break;
            selectedImage->trans.x += 5;
            break;
    }
    
}

void ofApp::stackOrder(int j) {
    
    if(!selectedImage) return;
    
    int i;
    Image *tmpImg;
    
    switch(j) {
        case(1):
            for (i = 0; i < images.size(); i++) {
                if (images[i]->bSelected == true) {
                    if (i == 0) {return;}
                    else {
                        tmpImg = images[i-1];
                        images[i-1] = images[i];
                        images[i] = tmpImg;
                    }
                }
            }
            break;
            
        case(0):
            for (i = 0; i < images.size(); i++) {
                if (images[i]->bSelected == true) {
                    if (i == images.size()-1) {return;}
                    else {
                        tmpImg = images[i+1];
                        images[i+1] = images[i];
                        images[i] = tmpImg;
                    }
                }
            }
            break;
    }
}

void ofApp::addImgFunc() {

    ofFileDialogResult openFileResult= ofSystemLoadDialog("Select a jpg or png");
    //Check if the user opened a file
    if (openFileResult.bSuccess){
        processOpenFileSelection(openFileResult);
    } else {
        return;
    }
}


void ofApp::processOpenFileSelection(ofFileDialogResult openFileResult){
    
    ofFile file (openFileResult.getPath());
    
    ofImage currImage;
    
    if (file.exists())
        currImage.load(file);
        Image *imageObj = new Image();
        imageObj->image = currImage;
        imageObj->trans.x = 500 + addpadding;
        imageObj->trans.y = 400+ addpadding;
        images.push_back(imageObj);
    
    addpadding += 20;
}

void ofApp::deleteImgFunc() {
    
    if (images.size() == 0) return;

    for (int j = 0; j < images.size(); j++)
        if (images[j]->bSelected == true)
            images.erase(images.begin() + j);
    selectedImage = NULL;
}

void ofApp::saveImgFunc() {
    scrshot = true; 
}

void ofApp::screenshotGrab() {
    ofFileDialogResult saveFileResult = ofSystemSaveDialog("", "Save Your File");
    (0,0,ofGetWindowWidth(),ofGetWindowHeight());
    ofImage scr;
    scr.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    scr.save(saveFileResult.getPath());
}

void ofApp::doMouseRotation(int x, int y) {
    
    // if there are no images stored in the list, just return
    //
    if (images.size() == 0) return;
    
    float rotation;
    ofVec2f mouse = ofVec2f(x, y);
    ofVec2f delta = mouse - lastMouse;
    float dist = delta.length();
    
    // if mouse is moving from left to right, apply positive rotation
    // otherwise apply negative rotation.
    //
    if (mouse.x < lastMouse.x)
        rotation = -dist;
    else
        rotation = dist;
    
    // store value of where the mouse was last for next entry
    //
    lastMouse = mouse;
    
    // apply rotation to image (will be rotated to this value on next redraw)
    //
    images[images.size() - 1]->rot += rotation;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    lastMouse = ofVec2f(x, y);
    renderSelection();
    processSelection(x, y);
    
    bool pre_aHit = ((x < (20 + addImg.getWidth())) && (x > 20)) &&
                            ((y < (10 + addImg.getHeight())) && (y > 10));
    
    if (pre_aHit) {
        addImgFunc();
    }
    
    // Cheeky Variable Names
    bool pre_sHit = ((x < (20 + savImg.getWidth())) && (x > 20)) &&
                ((y < (60 + savImg.getHeight())) && (y > 60));
    
    if (pre_sHit) {
        saveImgFunc();
    }
}

void ofApp::zoom(char c) {
    
    if (!selectedImage) return;
    if (c == 'o') {
        selectedImage->scale += 0.1;
    } else {
        selectedImage->scale -= 0.1;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (rotCursor) rotCursor = !rotCursor;
    if (dragCursor) dragCursor = !dragCursor;
//    if (scaleBoth) scaleBoth = !scaleBoth;
//    if (scalex) scalex = !scalex;
//    if (scaley) scaley = !scaley;
    ofShowCursor();
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
    
    Image *imageObj = new Image();
    imageObj->trans.x = dragInfo.position.x;
    imageObj->trans.y = dragInfo.position.y;
    if (imageObj->image.load(dragInfo.files[0]) == true)
        images.push_back(imageObj);
    else {
        cout << "Can't load image: " << dragInfo.files[0] << endl;
        delete imageObj;
    }
    
}

//
// Render for the purposes of selection hit testing.  In this case
// we use the color method. We render echo object as a different
// value of r,g,b.  We then compare the pixel under the mouse. The
// value is the index into the image list;
//
void ofApp::renderSelection() {
    ofBackground(0);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    for (int i = 0; i < images.size(); i++) {
        images[i]->draw(true, i);
    }
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void ofApp::processSelection(int x, int y) {
    unsigned char res[4];
    GLint viewport[4];
    
    // read pixel under mouse x y
    //
    glGetIntegerv(GL_VIEWPORT, viewport);
    glReadPixels(x, viewport[3] - y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &res);
    
    if (selectedImage) {
        selectedImage->bSelected = false;
        selectedImage = NULL;
    }
    
    if (res[0] > 0 && res[0] <= images.size()) {
            Image *image = images[res[0] - 1];
            image->bSelected = true;
            selectedImage = image;
            //images.erase(images.begin() + (res[0] - 1) );
            //images.push_back(image);
    }
}

Image::Image()
{
    trans.x = 0;
    trans.y = 0;
    scale.x = 1.0;
    scale.y = 1.0;
    rot = 0;
}

void Image::draw(bool bSelectMode, int index) {
    ofPushMatrix();
    ofTranslate(trans);
    ofScale(scale);
    ofRotate(rot);
    
    //
    // if drawing image normally
    //
    if (!bSelectMode) {
        
        //
        // if selected, draw a light yellowo box around image
        //
        if (bSelected) {
            ofNoFill();
            ofSetColor(255, 0, 0);
            ofSetLineWidth(5);
            ofDrawRectangle(-image.getWidth() / 2.0, -image.getHeight() / 2.0,
                            image.getWidth(), image.getHeight());
            
            int hwdth = image.getWidth()/2.0;
            int hhght = image.getHeight()/2.0;
            
            ofFill();
            // "The Selection Circles"
            ofDrawCircle(hwdth, hhght, 5);
            ofDrawCircle(hwdth, 0, 5);
            ofDrawCircle(0, hhght, 5);
            ofDrawCircle(hwdth, -hhght, 5);
            ofDrawCircle(-hwdth, hhght, 5);
            ofDrawCircle(-hwdth, 0, 5);
            ofDrawCircle(0, -hhght, 5);
            ofDrawCircle(-hwdth, -hhght, 5);
            
        }
        ofSetColor(255, 255, 255, 255);
        image.draw(-image.getWidth() / 2.0, -image.getHeight() / 2.0);
        
    } else {
        ofFill();
        ofSetColor(index + 1, 0, 0);
        ofDrawRectangle(-image.getWidth() / 2.0, -image.getHeight() / 2.0,
                        image.getWidth(), image.getHeight());
    }
    ofPopMatrix();
}
