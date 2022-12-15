#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup();

	//ARDUINO ZEUGS -- WIP
		//ofAddListener(arduino.EInitialized, this, &ofApp.setupArduino);
		arduino.connect("/dev/cu.usbserial-01F96E35", 115200);
    
    //3d Modelle laden
	for (int i = 0; i < cupNr; i++) cup[i].loadModel("Cup.3ds", 200);
	ball.loadModel("ball.stl");
	table.loadModel("table.stl");



    //gui cup position
	//Habe die Schieber der Becher rausgenommen, da die Becher an festen Positionen stehen und nicht mehr verändert werden
		//gui.add(ofxVec2Slider_position.setup("Cup Position", ofVec2f(0,0), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));	
		gui.add(ofxVec3Slider_position_sphere.setup("Sphere Position", ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), ofVec3f(ofGetWidth(), ofGetHeight(),100)));
		gui.add(ofxFloatSlider_table.setup("Tables Scale",6,3,8));
		//gui.add(ofxVec3Slider_position_table.setup("Table Position", ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), ofVec3f(-100, -100, 200)));


	//CAMERA SETUPs
		//camera.enableOrtho();
		//camera.setupPerspective(true, 60.0, 0.0, 1000.0, ofVec2f(0, 6));
    
    //light setup
    gui.add(vec3Slider_light.setup("Light Position", ofVec3f(0, 0, 0), ofVec3f(0,0, 0), ofVec3f(ofGetWidth(), ofGetHeight(), 100)));
    

}


void ofApp::setupArduino(const int & version) {
	//ofRemoveListener(arduino.EInitialized, this, &ofApp.setupArduino);
}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
	
    gui.draw();
    
    ofEnableDepthTest();
    light.enable();

	camera.begin();
	ofNoFill();
    
    // DRAW OBJECTS
	for (int i = 0; i < cupNr; i++) cup[i].drawFaces();
	ball.drawFaces();
	table.drawFaces();

    
	//
	//DRAW CUPS  START
	//


	//Hab die Schieber entfernt, da die Becher immer an der selben Position stehen

	int buildCount = 0;

	//4er Reihe
	for (int i = 0; i < 4; i++) {
		cup[buildCount].setPosition((i*cupRad), 0, 100);
		buildCount++;
	}
	//3er Reihe
	for (int i = 0; i < 3; i++) {
		cup[buildCount].setPosition((0.5*cupRad) + (i*cupRad), (0.85*cupRad), 100);
		buildCount++;
	}
	//2er Reihe
	for (int i = 0; i < 2; i++) {
		cup[buildCount].setPosition((i*cupRad) + cupRad, (2 * (0.85*cupRad)), 100);
		buildCount++;
	}
	//letzter
	cup[buildCount].setPosition((0.5*cupRad) + cupRad, (3 * (0.85*cupRad)), 100);


	//
	//DRAW CUPS  END
	//

	//ball Position - dynamisch durch Schieber
	ball.setPosition(ofxVec3Slider_position_sphere->x, ofxVec3Slider_position_sphere->y, ofxVec3Slider_position_sphere->z * 10);

	//table position - Werte sind durch try and error entstanden und müssen eig nicht mehr verändert werden
	table.setPosition(325, 2475, -1450); // X: +nach rechts, -nach links; Y: +zu dir, -zum Gegner; Z: -nach unten, +nach oben
	table.setRotation(1, 90, 0, 0, 90);
	
    
    //draw cup color from gui values
    ofSetColor(ofxVec4Slider_color->x, ofxVec4Slider_color->y, ofxVec4Slider_color->z, ofxVec4Slider_color->w);
    
    //
    // DRAW SCENE
    //    
    
    //draw light position
    light.setPosition(vec3Slider_light->x, vec3Slider_light->y, vec3Slider_light->z);


    //draw resized cup
    for(int i = 0; i < cupNr; i++) cup[i].setScale(0.4, 0.4, 0.4);
	ball.setScale(0.2, 0.2, 0.2);
	//Table slider zum resizing
	table.setScale(ofxFloatSlider_table, ofxFloatSlider_table, ofxFloatSlider_table);



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
