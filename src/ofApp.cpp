#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup();

	arduino.connect("/dev/cu.usbserial-01F96E35", 9600);

    //
    // CUP SETUP
	//
    
    //cup Modell laden
	for (int i = 0; i < cupNr; i++) cup[i].loadModel("Cup.3ds", 200);

    

    //gui cup position
	gui.add(ofxVec2Slider_position.setup("Cup Position", ofVec2f(0,0), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));	


    //gui cup color
		//gui.add(ofxVec4Slider_color.setup("Cup Color", ofVec4f(0, 0, 0, 0), ofVec4f(0,0,0,0), ofVec4f(255,255,255, 255))); //alle 4 werte von 0.0 bis 255.0 in float schritten

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


void ofApp::setupArduino(const int & version) {
	// Arduino setup tasks will go here
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
	for (int i = 0; i < cupNr; i++) cup[i].drawFaces();

    
    //draw cup position from gui values
	
	int buildCount = 0;

	for (int i = 0; i < 4; i++) {
		//if (buildCount > cupNr) break;
		cup[buildCount].setPosition(ofxVec2Slider_position->x + (i*cupRad), ofxVec2Slider_position->y, 100);
		buildCount++;
	}
	for (int i = 0; i < 3; i++) {
		//if (buildCount > cupNr) break;
		cup[buildCount].setPosition(ofxVec2Slider_position->x + (0.5*cupRad) + (i*cupRad), ofxVec2Slider_position->y + (0.85*cupRad), 100);
		buildCount++;
	}
	for (int i = 0; i < 2; i++) {
		//if (buildCount > cupNr) break;
		cup[buildCount].setPosition(ofxVec2Slider_position->x + (i*cupRad) + cupRad, ofxVec2Slider_position->y + (2*(0.85*cupRad)), 100);
		buildCount++;
	}

	cup[buildCount].setPosition(ofxVec2Slider_position->x + (0.5*cupRad) + cupRad, ofxVec2Slider_position->y + (3*(0.85*cupRad)), 100);
	
    
    //draw cup color from gui values
    ofSetColor(ofxVec4Slider_color->x, ofxVec4Slider_color->y, ofxVec4Slider_color->z, ofxVec4Slider_color->w);
    
    //
    // DRAW SCENE
    //
    
    
    //draw light position
    light.setPosition(vec3Slider_light->x, vec3Slider_light->y, vec3Slider_light->z);
    


    //draw resized cup
    for(int i = 0; i < cupNr; i++) cup[i].setScale(0.5, 0.5, 0.5);
    
    
    
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
