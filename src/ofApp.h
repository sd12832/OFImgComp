#pragma once

#include "ofMain.h"

class Image {
    
public:
    Image();
    ofVec2f trans, scale;
    float   rot;
    bool    bSelected;
    ofImage image;
    void    draw(bool bSelectMode = false, int index = 0);
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
        void doMouseRotation(int x, int y);
        void renderSelection();
        void processSelection(int x, int y);

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
        void addImgFunc();
        void deleteImgFunc();
        void saveImgFunc();
        void processOpenFileSelection(ofFileDialogResult openFileResult);
        void screenshotGrab();
        void moveImg(char c);
        void stackOrder(int j);
        void zoom(char c);
    
    private:
    
        int addpadding = 0;
    
        // The images
        ofImage bckg;
        ofImage addImg;
        ofImage delImg;
        ofImage savImg;
        ofImage curImg;
        ofImage rotImg;
        ofImage zouImg;
        ofImage zinImg;
    
        // ofEasyCam initializations
        ofEasyCam   cam;
        ofVec2f     lastMouse;
        bool        ctrlKeyDown;
        bool        scrshot;
        bool        rotCursor = false;
        bool        dragCursor = false;
    
        int cursorx = 0;
        int cursory = 0;
    
        bool zou_hit;
        bool zin_hit;
    
        vector<Image *> images;
        Image * selectedImage;
		
};
