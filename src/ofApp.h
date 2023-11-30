#pragma once

#include "ofMain.h"
#include "ofxNDISender.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
        void setupNDI();
    
//        ofxNDISender ndiSender;
        ofImage screen;
        ofPixels    pixels;
        ofFbo m_fbo;                   // Fbo used for graphics and sending
    
        ofxNDISender ndiSender;        // NDI sender
        std::string senderName;        // Sender name
        unsigned int senderWidth = 0;  // Width of the sender output
        unsigned int senderHeight = 0; // Height of the sender output
        
        bool bReadback = true;
        bool bAsync = true;
        double framerate = 60.0;
        float opacity = 200;
    const int WIDTH = 512;
        const int HEIGHT = 424;
};
