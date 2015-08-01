
#include "testApp.h"
ofVideoPlayer myPlayer;
ofImage myImage;
//--------------------------------------------------------------
void testApp::setup() {
    
#ifndef FARNE_USE_CAMERA
    videoSource.setDesiredFrameRate(30);
    videoSource.initGrabber(640, 480);
#endif
#ifdef FARNE_USE_CAMERA
    
    myPlayer.loadMovie("oneKidSwing_small.mov");
    myPlayer.play();
    
    
    //videoSource.loadMovie("Godard.mov");
    //videoSource.play();
    
#endif
    
    //image.loadImage("henStep2.png");
    //image.loadImage("henStep3.png");
    
    
    flowSolver.setup(myPlayer.getWidth(), myPlayer.getHeight(), 0.35, 5, 10, 1, 3, 2.25, false, false);
    
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(true);
    //ofBackground(140);
    ofBackground(255);
    
    ofSetWindowShape(myPlayer.getWidth()+300, myPlayer.getHeight());
}

//--------------------------------------------------------------

void testApp::update() {
    myPlayer.update();
    if(myPlayer.isFrameNew()) {
        flowSolver.update(myPlayer);
    }
}

//--------------------------------------------------------------
void testApp::draw() {
    
    // Defining point of interest to calculate velocity
    int poi1_x = 300;
    int poi1_y = 270;
    int poi2_x = 430;
    int poi2_y = 210;
    
    ofSetColor(0);
    ofFill();
    ofRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    ofSetColor(255, 255, 255);
    myPlayer.draw(0, 0);
    flowSolver.drawColored(myPlayer.getWidth(), myPlayer.getHeight(), 10, 5);
    
    //ofCircle(poi1_x, poi1_y, 10);
    //ofCircle(poi2_x, poi2_y, 10);
    
    
    ofSetColor(0, 100, 0, 90);
    ofFill();
    ofRect(100, 5, 270, 40);
    
    
    
    
    ofPoint poi1, poi2, poi3, vel1;
    int x1, y1;
    poi1.set(poi1_x, poi1_y);
    poi2.set(poi2_x, poi2_y);
    
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
        
        x1 = ofGetMouseX();
        y1 = ofGetMouseY();
        
        poi3.set(ofGetMouseX(), ofGetMouseY());
        //ofCircle(ofGetMouseX(), ofGetMouseY(), 10);
    }
    
    ofCircle(x1,y1,10);
    
    bool drawshape1, drawshape2;
    drawshape1 = false;
    
    int lastvel;
    ofSetColor(255, 255, 255);
    lastvel = ofGetElapsedTimeMillis();
    
    vel1 = flowSolver.getVelAtPixel(poi1_x, poi1_y);
    
    if (vel1.x > 12) {
        drawshape1 = true;
    }
    
    stringstream m;
    m << "fps " << ofGetFrameRate() << endl
    //<< "pyramid scale: " << flowSolver.getPyramidScale() << " p/P" << endl
    // << "pyramid levels: " << flowSolver.getPyramidLevels() << " l/L" << endl
    // << "averaging window size: " << flowSolver.getWindowSize() << " w/W" << endl
    // << "iterations per level: " << flowSolver.getIterationsPerLevel() << " i/I" << endl
    // << "expansion area: " << flowSolver.getExpansionArea() << " a/A" << endl
    //<< "expansion sigma: " << flowSolver.getExpansionSigma() << " s/S" << endl
    // << "flow feedback: " << flowSolver.getFlowFeedback() << " f/F" << endl
    //<< "gaussian filtering: " << flowSolver.getGaussianFiltering() << " g/G"<<endl
    << "Velocity1: "<< flowSolver.getVelAtPixel(poi1_x,poi1_y) <<endl
    << "x1 : " << x1 << endl
    << "y1: " << y1 << endl
    << " time: " << ofGetElapsedTimeMillis() << endl
    << "lastvel: " << vel1.x << endl
    << " velbool : "<< drawshape1 <<endl;
    
    
    
    
    //<<"Velocity2: "<< flowSolver.getVelAtPixel(poi2_x,poi2_y) <<endl;
    //<< "Velocity at normal" << flowSolver.getVelAtNorm(330, 230) << "vel@normal" << endl ;
    
    
    /* if (drawshape1==true) {
     int x,y,d;
     
     x = 840;
     y = 320;
     
     for(x = 840; x <= 300; x-40){
     for (y = 320; y <=10; y-40){
     ofTriangle(x,y,x,y+40,x+40,y+40);
     }
     }
     }
     */
    
    
    
    int x,y,d,r;
    
    x = 800;
    y = 320;
    d = 40;
    r = 15;
    
    
    if (ofGetElapsedTimeMillis() >= 4400){
        
        image.loadImage("henStep1.png");
        image.draw(750, 100, 100, 200);
    }
    if (ofGetElapsedTimeMillis() >= 6500){
        image.loadImage("henStep2.png");
        image.draw(750, 100, 100, 200);
        
    }
    
    if ( ofGetElapsedTimeMillis() >= 9000){
        image.loadImage("henStep3.png");
        image.draw(750, 100, 100, 200);
    }
    
    if ( ofGetElapsedTimeMillis() >= 11300){
        ofTriangle(x-3*d,y-3*d,x-3*d,y-2*d,x-2*d,y-2*d);
    }
    
    
    
    
    
    /*
     
     // Code for Nurture
     
     if (ofGetElapsedTimeMillis() >= 4200){
     ofRect(x-10, y, 15, 30);
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 280;
     d=30;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 240;
     d=15;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 320;
     
     
     }
     if (ofGetElapsedTimeMillis() >= 6500){
     ofRect(x-10, y, 15, 40);
     d= 50;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 270;
     d=40;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 230;
     d=25;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 320;
     }
     
     if ( ofGetElapsedTimeMillis() >= 9000){
     ofRect(x-10, y, 15, 50);
     d= 60;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 260;
     d=50;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 220;
     d=35;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 320;
     }
     
     if ( ofGetElapsedTimeMillis() >= 11300){
     ofRect(x-10, y, 15, 50);
     d= 70;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 240;
     d=60;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 200;
     d=35;
     ofTriangle(x-d,y,x+d,y, x,y-1.73*d);
     x = 800;
     y = 320;
     }
     
     */
    
    /*
     // Code for gathering tools to play a gamae later
     if (ofGetElapsedTimeMillis() >= 4200){
     ofSetColor(50, 180, 50);
     ofRect(x, y, 50, 10);
     
     }
     if (ofGetElapsedTimeMillis() >= 6500){
     ofRect(x-d, y-d, 50, 10);
     ofSetColor(255, 255, 255);
     ofCircle(x-d+r, y-d-r, r);
     }
     
     if ( ofGetElapsedTimeMillis() >= 9000){
     ofSetColor(50, 180, 50);
     ofRect(x, y-2*d, 50, 10);
     
     
     }
     
     if ( ofGetElapsedTimeMillis() >= 11300){
     ofRect(x-d, y-3*d, 50, 10);
     
     }
     
     if ( ofGetElapsedTimeMillis() >= 13600){
     ofRect(x, y-4*d, 50, 10);
     
     }
     
     */
    
    /*
     // code for bulding blocks
     
     if (ofGetElapsedTimeMillis() >= 4200){
     ofTriangle(x,y,x,y+d,x+d,y+d);
     }
     if (ofGetElapsedTimeMillis() >= 6500){
     ofTriangle(x-d,y-d,x-d,y,x,y);
     }
     
     if ( ofGetElapsedTimeMillis() >= 9000){
     ofTriangle(x-2*d,y-2*d,x-2*d,y-d,x-d,y-d);
     }
     
     if ( ofGetElapsedTimeMillis() >= 11300){
     ofTriangle(x-3*d,y-3*d,x-3*d,y-2*d,x-2*d,y-2*d);
     }
     */
    
    
    ofDrawBitmapString(m.str(), 120, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    if(key == 'p') { flowSolver.setPyramidScale(ofClamp(flowSolver.getPyramidScale() - 0.01,0.0,1.0)); }
    else if(key == 'P') { flowSolver.setPyramidScale(ofClamp(flowSolver.getPyramidScale() + 0.01,0.0,1.0)); }
    else if(key == 'l') { flowSolver.setPyramidLevels(MAX(flowSolver.getPyramidLevels() - 1,1)); }
    else if(key == 'L') { flowSolver.setPyramidLevels(flowSolver.getPyramidLevels() + 1); }
    else if(key == 'w') { flowSolver.setWindowSize(MAX(flowSolver.getWindowSize() - 1,1)); }
    else if(key == 'W') { flowSolver.setWindowSize(flowSolver.getWindowSize() + 1); }
    else if(key == 'i') { flowSolver.setIterationsPerLevel(MAX(flowSolver.getIterationsPerLevel() - 1,1)); }
    else if(key == 'I') { flowSolver.setIterationsPerLevel(flowSolver.getIterationsPerLevel() + 1); }
    else if(key == 'a') { flowSolver.setExpansionArea(MAX(flowSolver.getExpansionArea() - 2,1)); }
    else if(key == 'A') { flowSolver.setExpansionArea(flowSolver.getExpansionArea() + 2); }
    else if(key == 's') { flowSolver.setExpansionSigma(ofClamp(flowSolver.getExpansionSigma() - 0.01,0.0,10.0)); }
    else if(key == 'S') { flowSolver.setExpansionSigma(ofClamp(flowSolver.getExpansionSigma() + 0.01,0.0,10.0)); }
    else if(key == 'f') { flowSolver.setFlowFeedback(false); }
    else if(key == 'F') { flowSolver.setFlowFeedback(true); }
    else if(key == 'g') { flowSolver.setGaussianFiltering(false); }
    else if(key == 'G') { flowSolver.setGaussianFiltering(true); }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {
    
}
