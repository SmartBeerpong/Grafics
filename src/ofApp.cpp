#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//standard
    gui.setup();
	ofDisableAlphaBlending();
	ofEnableDepthTest();
	ofDisableArbTex();	
    
    //3d Modelle laden
	for (int i = 0; i < cupNr; i++) cup[i].loadModel("Cup.3ds", 200);
	ball.loadModel("ball.stl");
	table.loadModel("table.stl");

	//textur
	ofLoadImage(tex, "tableTex.png");

    //gui slider for position
	//Habe ein paar Schieber rausgenommen, da die Objekte nicht mehr verändert werden
	gui.add(vec3Slider_light.setup("Light Position", ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), ofVec3f(ofGetWidth(), ofGetHeight(), 100)));
	gui.add(ofxVec3Slider_position_sphere.setup("Sphere Position", ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), ofVec3f(ofGetWidth(), ofGetHeight(),100)));
	//gui.add(ofxFloatSlider_table.setup("Tables Scale",6,3,8));
		//gui.add(ofxVec3Slider_position_table.setup("Table Position", ofVec3f(0, 0, 0), ofVec3f(0, 0, 0), ofVec3f(0,0,0)));
		//gui.add(ofxVec2Slider_position.setup("Cup Position", ofVec2f(0,0), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
		//gui.add(ofxVec3Slider_cam.setup("Cam Pos", ofVec3f(0,0, 0), ofVec3f(0,0, 0), ofVec3f(0,0, 0)));

	//CAMERA SETUPs
		//camera.enableOrtho();
		//camera.setupPerspective(true, 60.0, 0.0, 1000.0, ofVec2f(0, 6));
		//camera.cameraToWorld(ofxVec3Slider_cam);
		//camera.setTarget(ofVec3f(cup[5].getPosition())); //x: Schwenk links, rechts  y: Schenken hoch, runter  z: kp
	camera.setDistance(2000);

	//ARDUINO ZEUGS -- WIP
	arduino.connect("/dev/cu.usbserial-01F96E35", 115200);
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {

	//TESTING
	serial.setup("COM3", 115200);
	serial.isInitialized();
	//serial.readBytes;

	//listener for arduino removed
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

}

//--------------------------------------------------------------
void ofApp::update(){

	//WIP - aulesen des SerialPorts
	arduino.update();
	arduino.serialRead(port, byteRead);
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	//standard
    gui.draw();
    light.enable();
	camera.begin();
	ofNoFill();
    
    // INITIALIZE OBJECTS
	for (int i = 0; i < cupNr; i++) cup[i].drawFaces();
	table.drawFaces();
	ball.drawFaces();

	//texture
	tex.bind();
	sphere.draw();
	tex.unbind();

    
	//
	//POSITION OBJECTS - START
	//
			
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

		//ball Position - dynamisch durch Schieber
		ball.setPosition(ofxVec3Slider_position_sphere->x, ofxVec3Slider_position_sphere->y, ofxVec3Slider_position_sphere->z * 10);
		table.setPosition(325, 2475, -1450); // X: +nach rechts, -nach links; Y: +zu dir, -zum Gegner; Z: -nach unten, +nach oben
		table.setRotation(1, 90, 0, 0, 90);

	//
	//POSITION OBJECTS - END
	//
	
	//scale objects
	for (int i = 0; i < cupNr; i++) cup[i].setScale(0.4, 0.4, 0.4);
	ball.setScale(0.2, 0.2, 0.2);
	table.setScale(6, 6, 6);

    //Color slider init
    ofSetColor(ofxVec4Slider_color->x, ofxVec4Slider_color->y, ofxVec4Slider_color->z, ofxVec4Slider_color->w);
    
    //draw light position
    light.setPosition(vec3Slider_light->x, vec3Slider_light->y, vec3Slider_light->z);
	
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

	//serialMessage = true;

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
