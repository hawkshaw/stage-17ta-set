#pragma once

#include "ofMain.h"
#include "ofxLitSphere.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);
    void keyPressed(int key);
    ofxLitSphere litSphere;
    bool b_DrawGui;
    
    ofEasyCam cam;
    
    vector<ofImage> v_kabe;
};
