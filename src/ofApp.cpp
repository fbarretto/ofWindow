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
    ofDirectory dir(path);
    ofImage img;
    
    dir.listDir();
    dir.sort();
    
    int iteratorLimit = 24;
    
    if(dir.size() < lastIndex + 24 ) {
        iteratorLimit = dir.size() - lastIndex;
    }
    
    for(int i = 0; i < iteratorLimit; i++){
        ofLogNotice(dir.getPath(lastIndex));
        dirList.push_back(dir.getPath(lastIndex));
        
        img.load(dir.getPath(lastIndex));
        
        images.push_back(img);
        
        lastIndex++;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    vector<ofImage> tempImages;
    ofDirectory dir(path);
    
    dir.listDir();
    dir.sort();
    std::cout<<ofGetFrameNum()<<std::endl;
    
    if(300 == ofGetFrameNum()) {
        
        int iteratorLimit = 24;
        
        if(dir.size() < lastIndex + 24 ) {
            iteratorLimit = dir.size() - lastIndex;
        }
        
        for(int i = 0; i < iteratorLimit; i++){
            ofLogNotice(dir.getPath(lastIndex));
            ofImage img;
            
            img.load(dir.getPath(lastIndex));
            
            images.push_back(img);
            
            lastIndex++;
        }
        
        images.clear();
        images = tempImages;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(images.size() > 0) {
        for(ofImage image : images) {
            image.draw(0, 0, 42);
        }
    }
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
