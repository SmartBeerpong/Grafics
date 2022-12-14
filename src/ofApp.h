#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"
#include "ofArduino.h"
#include "ofEventUtils.h"


class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

		void setupArduino(const int & version);
    
    
    //GUI
    ofxPanel gui;

    
    ofxVec2Slider ofxVec2Slider_position; //x y
	ofxVec3Slider ofxVec3Slider_position_sphere; //x y z
    ofxVec3Slider vec3Slider_light; //x y z
    ofxVec4Slider ofxVec4Slider_color; //red green blue transparency

	//ARDUINO
	ofArduino arduino;
	
	
    
    //3d Modell cup laden
	int cupNr = 10;
	int cupRad = 375;
	ofxAssimpModelLoader cup[10];
	ofxAssimpModelLoader test[3][3];
	ofxAssimpModelLoader ball;

    

    //camera und licht
    ofEasyCam camera;
    ofLight light;
    
    //screenshots
    ofImage imgScreenshot;
    int count;
    bool snapped;
    
    
    //unused
    
    ofxIntSlider intSlider;
    ofxFloatSlider floatSlider;

    ofxToggle toggle;
    ofxButton button;
    ofxLabel label;

    ofxIntField intField;
    ofxFloatField floatField;
    ofxTextField textField;

  
    //webcams
    //ofVideoGrabber cam1;
    //ofVideoGrabber cam2;
    
 
        
};
