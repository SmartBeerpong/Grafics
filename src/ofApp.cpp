#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup();

    //
    // CUP SETUP
    //
	//
    
    //cup Modell laden
    cup.loadModel("Cup.3ds", 200);
	cup2.loadModel("Cup.3ds", 200);

    

    //gui cup position
	gui.add(ofxVec2Slider_position.setup("Cup Position", ofVec2f(0,0), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
    
	//gui test label
	


    //gui cup color
    gui.add(ofxVec4Slider_color.setup("Cup Color", ofVec4f(0, 0, 0, 0), ofVec4f(0,0,0,0), ofVec4f(255,255,255, 255))); //alle 4 werte von 0.0 bis 255.0 in float schritten

    //
    // SCENE SETUP
    //

	//
	//CAMERA SETUP
	//
	//camera.enableOrtho();
	//camera.setupPerspective(true, 60.0, 0.0, 1000.0, ofVec2f(0, 6));
    
    //light setup
    gui.add(vec3Slider_light.setup("Light Position", ofVec3f(0, 0, 0), ofVec3f(0,0, 0), ofVec3f(ofGetWidth(), ofGetHeight(), 100)));
    

}


//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
   
   
    gui.draw();
    
    ofEnableDepthTest();
    light.enable();

    
    //
    // DRAW CUP
    //
    camera.begin();
    ofNoFill();
    cup.drawFaces();
	cup2.drawFaces();

    
    //draw cup position from gui values
    cup.setPosition(ofxVec2Slider_position->x, ofxVec2Slider_position->y, 100);
	cup2.setPosition(ofxVec2Slider_position->x + 380, ofxVec2Slider_position->y, 100);

    
    //draw cup color from gui values
    ofSetColor(ofxVec4Slider_color->x, ofxVec4Slider_color->y, ofxVec4Slider_color->z, ofxVec4Slider_color->w);
    
    //
    // DRAW SCENE
    //
    
    
    //draw light position
    light.setPosition(vec3Slider_light->x, vec3Slider_light->y, vec3Slider_light->z);
    


    //draw resized cup
    cup.setScale(0.5, 0.5, 0.5);
	cup2.setScale(0.5, 0.5, 0.5);
    
    
    
    //was man einschaltet, muss man auch wieder ausschalten, sonst spinnt alles
    camera.end();
    light.disable();
    ofDisableDepthTest();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    //screenshots durch enter
    if (key == ' ') {
        snapped = true;
    }

    if (snapped == true) {
        imgScreenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        string filename = "screenshot_" + ofGetTimestampString() + ".png";
        imgScreenshot.save(filename);
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
