#pragma once

#include "ofMain.h"
#include "ofxHapPlayer.h"
#include "ofxPSBlend.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

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
        void recursive_Blend(int layersLeft);
    
    const int FR = 10;
    // ^ number of frames
    
    ofxPSBlend psBlends[9];
    // ^ number is always -1 of FR
    int blendMode;
    
    const int FRAMEWIDTH = 1280;
    const int FRAMEHEIGHT = 720;
    
    int numFrames;
    bool isRecursive;
    
    ofVideoPlayer video0;
    ofxHapPlayer videos[10];
    // ^ always same as FR
        
};

