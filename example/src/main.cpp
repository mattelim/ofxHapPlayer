#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    /* Default settings
    ofSetupOpenGL(1280,720,OF_WINDOW);            // <-------- setup the GL context
     */
    
    /* Manual settings to use specific GL version
     */
    ofGLWindowSettings settings;
    settings.setGLVersion(3,2);
    settings.windowMode = OF_WINDOW;
    settings.setSize(1280,720);
    ofCreateWindow(settings);
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
