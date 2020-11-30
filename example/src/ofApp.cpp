#include "ofApp.h"

/*
 COMMENTS:
 HAP texture and shader only works with default GL renderer
 HAP + PSBlend requires OpenGL3.2
 HAP + PSBlend requires HAP Q (better quality video)
 !For some reason, for HAP the draw method has to be called under "draw" not "update"
 */

void ofApp::recursive_Blend(int layersLeft) {
    if (numFrames == 1) {
        return;
    }
    if (layersLeft > 0) {
        recursive_Blend(layersLeft-1);
    } else {
        // when layersLeft == 0,
        psBlends[layersLeft].begin();
        videos[layersLeft].draw(0,0,1280,720);
        psBlends[layersLeft].end();
        return;
    }
    
    psBlends[layersLeft].begin();
    ofTexture *rTexture = videos[layersLeft].getTexture();
    psBlends[layersLeft-1].draw(*rTexture, blendMode);
    psBlends[layersLeft].end();
}

//--------------------------------------------------------------

void ofApp::setup(){
    
    numFrames = 5;
    
    float framePct;
    for (int i=0; i<FR; i++){
        videos[i].load("videos/cat144_HAPQ.MOV");
        // length of video impacts CPU usage
        if (i == 0) {
            video0.load("videos/cat144.MOV");
            // getTotalNumFrames() does not work in HAP
            framePct = 2.0/video0.getTotalNumFrames();
            //cout << "framePct: " << framePct << endl;
            video0.close();
        }
        videos[i].setLoopState(OF_LOOP_NORMAL);
        videos[i].setPosition(i*framePct);
        // ^ setFrame(i*3) does not work with HAP
        videos[i].play();
    }
    
    for (int i=0; i<FR-1; i++){
        psBlends[i].setup(FRAMEWIDTH,FRAMEHEIGHT);
    }
    blendMode = 0;
    
    isRecursive = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<FR; i++){
        videos[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (numFrames == 1) {
         videos[0].draw(0,0,1280,720);
    } else {
        if (isRecursive) {
            /* Multiple layer PSBlend, recursive
             */
            recursive_Blend(numFrames-2);
        } else {
            /* Multiple layer PSBlend, iterative
             */
            for (int i=0; i<FR-1; i++) {
                psBlends[i].begin();
                if (i == 0) {
                    videos[0].draw(0,0,1280,720);
                } else {
                    ofTexture *texture = videos[i].getTexture();
                    psBlends[i-1].draw(*texture, blendMode);
                }
                psBlends[i].end();

                if (i == numFrames) {
                    break;
                }
            }
        }

        ofTexture *dTexture = videos[numFrames-1].getTexture();
        psBlends[numFrames-2].draw(*dTexture, blendMode);
    }

    ofSetWindowTitle("blendMode: " + psBlends[3].getBlendMode(blendMode));
    ofDrawBitmapString("press LEFT/RIGHT key to change Blend Mode", 10, 20);
    ofDrawBitmapString("press UP/DOWN key to change Number of Streams", 10, 40);
    ofDrawBitmapString("Current Number: " + to_string(numFrames), 10, 60);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case OF_KEY_DOWN:
            if (numFrames <= 1) {
                numFrames = 1;
            } else {
                numFrames--;
            }
        break;
        case OF_KEY_UP:
            if (numFrames >= FR) {
                numFrames = FR;
            } else {
                numFrames++;
            }
        break;
        case OF_KEY_LEFT:
            if (blendMode <= 0) {
                blendMode = 24;
            } else {
                blendMode--;
            }
        break;
        case OF_KEY_RIGHT:
            if (blendMode >= 24) {
                blendMode = 0;
            } else {
                blendMode++;
            }
        break;
        case ' ':
            for (int i=0; i<FR; i++){
                if (videos[i].isPaused()) {
                    videos[i].play();
                } else {
                    videos[i].setPaused(true);
                }
            }
        break;
    }
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

