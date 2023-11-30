#include "ofApp.h"
#include "iostream"
#include "string"
#include "filesystem"
#include "vector"


namespace fs = std::filesystem;

vector<string> dirList;
vector<ofImage> images;
int lastIndex = 0;
std::string path = "assets/predicted";

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofDirectory dir(path);
    ofImage img;
    
    dir.listDir();
    dir.sort();
    
    int iteratorLimit = 24;
    
    if(dir.size() < lastIndex + 24 ) {
        iteratorLimit = dir.size() - lastIndex;
    }
    
    for(int i = 0; i < iteratorLimit; i++){
//        ofLogNotice(dir.getPath(lastIndex));
        dirList.push_back(dir.getPath(lastIndex));
        
        img.load(dir.getPath(lastIndex));
        
        images.push_back(img);
        
        lastIndex++;
    }
    
    setupNDI();
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    std::cout<<ofGetFrameNum()<<std::endl;
    if(ofGetFrameNum() % 60 == 0 ) {
        vector<ofImage> tempImages;
        ofDirectory dir(path);
        
        dir.listDir();
        dir.sort();

        int iteratorLimit = 24;
        
        if(dir.size() < lastIndex + 24 ) {
            iteratorLimit = dir.size() - lastIndex;
        }
        
        for(int i = 0; i < iteratorLimit; i++){

            ofImage img;
            
            img.load(dir.getPath(lastIndex));
            img.resize(200,200);
            
            tempImages.push_back(img);
            
            lastIndex++;
        }
        
        images.clear();
        images = tempImages;
        
        if(lastIndex + 1 > dir.size()){
            lastIndex = 0;
        }
        std::cout << images.size() << std::endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    m_fbo.begin();
    
    int i = 0;
    int x = 0;
    int y = 0;
    if(images.size() > 0) {
        for(ofImage image : images) {
            x = 200 * i;
            
            if(i > 5 && i <= 11) {
                y = 250;
                x = 200 * (i - 6);
            }
            if(i > 11 && i <= 17) {
                y = 500;
                x = 200 * (i - 12);
            }
            if(i > 17 && i < 24) {
                y = 750;
                x = 200 * (i - 18);
            }
            
            image.draw(x, y, 42);
            
            i++;
        }
    }
    
    //ofDisableDepthTest();
        m_fbo.end();

        // Draw the fbo result fitted to the display window
        m_fbo.draw(0, 0, senderWidth, senderHeight);
        m_fbo.readToPixels(pixels);
        ofDrawBitmapString(ofGetFrameRate(), 20, 20);
        ndiSender.send(pixels);
    
    
}

void ofApp::setupNDI() {
    senderName = "thecode - endless";
    ofSetWindowTitle(senderName); // show it on the title bar

#ifdef _WIN64
    cout << "\nofxNDI sender - 64 bit" << endl;
#else // _WIN64
    cout << "\nofxNDI sender - 32 bit" << endl;
#endif // _WIN64

//    cout << ndiSender.GetNDIversion() << " (https://www.ndi.tv/)" << endl;

    // Set the dimensions of the sender output here
    // This is independent of the display window size.
    // 4K is set as the starting resolution to help
    // assess performance with different options.
    // It can be changed using the 'S' key.
    senderWidth = WIDTH;
    senderHeight = HEIGHT;

    // Create an RGBA fbo for collection of data
    m_fbo.allocate(senderWidth, senderHeight, GL_RGB);
    pixels.allocate(senderWidth, senderHeight, OF_IMAGE_COLOR);
    
    ndiSender.setMetaData("ofxNDISender example", "sender example", "ofxNDI", "0.0.0", "", "", "");
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
