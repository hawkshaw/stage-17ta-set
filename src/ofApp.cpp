#include "ofApp.h"

#define YUKA_W 5230
#define YUKA_D 6700
#define BOX_H 2000
#define HIRADAI_H 300
#define HIRADAI_W 900
#define HIRADAI_D 900
#define MAGUCHI 5390
#define KYAKUSEKI_D 2580
#define HASHIRA_W 800
#define HASHIRA_H 2000
#define BUTAI_D1 3000
#define BUTAI_D2 1000
#define BUTAI_TRI 600

#define KABE_TEX_W 440
#define KABE_TEX_H 1000

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetDataPathRoot("../../../../../data/");
    
    ofDisableArbTex();
    ofEnableDepthTest();
    ofSetVerticalSync(true);
    litSphere.setup();
    ofSetConeResolution(40, 40, 40);
    
    b_DrawGui=false;
    cam.setPosition(0, YUKA_D,BOX_H);
    cam.lookAt(ofVec3f(0,1,0), ofVec3f(0,0,1));
    ofImage kabe1,kabe2,kabe3;
    kabe1.load("5.png");
    kabe2.load("5.png");
    kabe3.load("5.png");
    v_kabe.push_back(kabe1);
    v_kabe.push_back(kabe2);
    v_kabe.push_back(kabe3);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    ofPushMatrix();
    ofBackgroundGradient(ofColor(180), ofColor(70), OF_GRADIENT_CIRCULAR);
    ofPopMatrix();


    cam.begin();
    
    ofScale(0.1, 0.1, 0.1);

    //Rotate mean
    //Turn the coordinate system clockwise
    ofSetColor(255);
    
    //ofDrawGridPlane();
    ofDrawGrid();
    ofSetColor(0);
    //yuka
    ofDrawPlane(0, YUKA_D/2, YUKA_W, YUKA_D);
    
    ofPushMatrix();
    ofRotateX(90);
    
    ofDrawPlane(0, BOX_H/2, YUKA_W, BOX_H);//Draw Back Screen
    ofSetColor(255);
    for(int i = (-1-(int)(YUKA_W/2/KABE_TEX_W));i < (int)(YUKA_W/2/KABE_TEX_W);i++){
        for(int j=0;j < (int)(BOX_H/KABE_TEX_H);j++){
            if(abs(i+j)%2==0){
                v_kabe[(abs((j)*(2)+i+j)/2)%3].draw(i*KABE_TEX_W, j*KABE_TEX_H,-1, KABE_TEX_W, KABE_TEX_H);
            }
        }
    }
    
    ofPushStyle();
    {
        ofSetColor(255);
        ofPushMatrix();
        {
            ofTranslate(-YUKA_W/2, 0);
            ofRotateY(90);
            ofSetColor(0);
            ofDrawPlane((BUTAI_D1-BUTAI_TRI)/2, BOX_H/2, BUTAI_D1-BUTAI_TRI, BOX_H);//Draw Back Screen
            ofSetColor(255);
            for(int i = 0;i <= (int)((BUTAI_D1-BUTAI_TRI)/KABE_TEX_W);i++){
                for(int j=0;j < (int)(BOX_H/KABE_TEX_H);j++){
                    if(abs(i+j)%2==0){
                        v_kabe[(abs((j)*(2)+i+j)/2)%3].draw((BUTAI_D1-BUTAI_TRI)-(i+1)*KABE_TEX_W, j*KABE_TEX_H,1, KABE_TEX_W, KABE_TEX_H);
                    }
                }
            }
        }
        ofPopMatrix();
    
        ofPushMatrix();
        {
            ofTranslate(YUKA_W/2, 0);
            ofRotateY(90);
            ofSetColor(0);
            ofDrawPlane((BUTAI_D1-BUTAI_TRI)/2, BOX_H/2, BUTAI_D1-BUTAI_TRI, BOX_H);//Draw Back Screen
            ofSetColor(255);
            for(int i = 0;i <= -3+(int)((BUTAI_D1-BUTAI_TRI)/KABE_TEX_W);i++){
                for(int j=0;j < (int)(BOX_H/KABE_TEX_H);j++){
                    if(abs(i+j+1)%2==0){
                        v_kabe[(abs((j)*(2)+i+j)/2)%3].draw((BUTAI_D1-BUTAI_TRI)-(i+1)*KABE_TEX_W, j*KABE_TEX_H,-1, KABE_TEX_W, KABE_TEX_H);
                    }
                }
            }
        }
        ofPopMatrix();
    }
    ofPopStyle();
    
    ofPopMatrix();
    
    ofSetColor(255);
    litSphere.loadAt(17);//black
    litSphere.begin();
    //ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    //ofRotateX(ofGetFrameNum());
    
    ofSetColor(60, 60, 60);
    ofBeginShape();
    ofVertex(YUKA_W/2, 0,10);
    ofVertex(-YUKA_W/2, 0,10);
    ofVertex(-YUKA_W/2, BUTAI_D1-BUTAI_TRI,10);
    ofVertex(-YUKA_W/2+BUTAI_TRI, BUTAI_D1,10);
    ofVertex(-YUKA_W/2+BUTAI_TRI, BUTAI_D1+BUTAI_D2,10);
    ofVertex(YUKA_W/2-BUTAI_TRI, BUTAI_D1+BUTAI_D2,10);
    ofVertex(YUKA_W/2-BUTAI_TRI, BUTAI_D1,10);
    ofVertex(YUKA_W/2, BUTAI_D1-BUTAI_TRI,10);
    ofEndShape();
    
    ofDrawCone(100, 140);
    ofDrawSphere(200, 0, 70);
    ofDrawBox(-200, 0, 0, 80);
    litSphere.end();

    litSphere.loadAt(21);//wood
    litSphere.begin();
    
    
    ofPushMatrix();
    ofTranslate(0, YUKA_D);
    for(int i = -2 ; i<3;i++){
        ofDrawBox(i*HIRADAI_W, -HIRADAI_D/2, HIRADAI_H, HIRADAI_W, HIRADAI_D, HIRADAI_H*2);
        ofDrawBox(i*HIRADAI_W, -HIRADAI_D*1.5, HIRADAI_H/2, HIRADAI_W, HIRADAI_D, HIRADAI_H);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(0, YUKA_D - KYAKUSEKI_D);
    ofDrawBox(MAGUCHI/2, 0, HASHIRA_H/2 , HASHIRA_W, HASHIRA_W, HASHIRA_H);
    ofDrawBox(-MAGUCHI/2, 0, HASHIRA_H/2 , HASHIRA_W, HASHIRA_W, HASHIRA_H);
    ofPopMatrix();
    
    ofDrawCone(400, 0, 100, 140);
    //ofDrawCone(100, 140);
    ofDrawSphere(-400, 0, 70);
    //ofDrawSphere(200, 0, 70);
    ofDrawBox(-200,200,0,80);
    //ofDrawBox(-200, 0, 0, 80);
    litSphere.end();
    
    cam.end();
    
    ofDrawBitmapStringHighlight("click to change sourse", ofPoint(0, 0));
    
    if(b_DrawGui){
        for(int i=0;i<25;i++){
            litSphere.loadAt(i);
            litSphere.begin();
            ofDrawSphere((i%10)*50+25,((int)(i/10))*50+25, 25);
            litSphere.end();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'f':
            ofToggleFullscreen();
            break;
        case 'd':
            b_DrawGui = !b_DrawGui;
            break;
    }
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    litSphere.loadNext();
}


