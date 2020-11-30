ofxHapPlayer (OpenGL Version 3.2)
============

Fork of bangnoise ofxHapPlayer: https://github.com/bangnoise/ofxHapPlayer

Changed to OpenGL Version 3.2 / #version 150 to be compatible with other add-ons.

Example uses a combination of this ofxHapPlayer and ofxPSBlend by Akira-Hayasaka: https://github.com/Akira-Hayasaka/ofxPSBlend

![sample image](HAPxBlend_sample.jpg?raw=true "Combining ofxHapBlend and ofxPSBlend")

Usage
-----

Use the OF Project Generator to generate build files for your project, selecting ofxHapPlayer as an addon.

    #import "ofxHapPlayer.h"
    
Project main.cpp file needs to be changed from:

    ofSetupOpenGL(1280,720,OF_WINDOW);

to:

    ofGLWindowSettings settings;
    settings.setGLVersion(3,2);
    settings.windowMode = OF_WINDOW;
    settings.setSize(1280,720);
    ofCreateWindow(settings);

Example included requires ofxPSBlend
    
Credits and License
-------------------

ofxHapPlayer was written by [Tom Butterworth](http://kriss.cx/tom), initially in April 2013, supported by [Igloo Vision](http://www.igloovision.com/) and James Sheridan. Since then it has been supported by [Vidvox](http://vidvox.net/). It is released under a [FreeBSD License](http://github.com/bangnoise/ofxHapPlayer/blob/master/LICENSE).
