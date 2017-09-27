#include "ofMain.h"
#include "ofApp.h"
#include "tipApp.h"

//========================================================================
int main( ){
    
    ofGLWindowSettings settings;
    settings.width = 1200;
    settings.height = 800;
    settings.setPosition(ofVec2f(450,0));
    auto mainWindow = ofCreateWindow(settings);

    settings.width = 450;
    settings.height = 430;
    settings.setPosition(ofVec2f(0,0));
    auto tipWindow = ofCreateWindow(settings);

    auto mainApp = make_shared<ofApp>();
    auto sideApp = make_shared<tipApp>();

    ofRunApp(tipWindow, sideApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
    

}
