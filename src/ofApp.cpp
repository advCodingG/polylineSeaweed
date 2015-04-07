#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(800, 800);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    for (int i=250; i>=-250; i-=10) {
        polyline.addVertex(ofVec2f(0,i));
    }
    movePolyline1 = polyline;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(224,224,224);
    ofSetColor(178,255,102);   //set polyline color
    
    // ofPushMatrix();
    //     ofTranslate(ofGetWidth()*1.0/4.0, ofGetHeight()/2);
    //     polyline.draw();
    // ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    movePolyline1.draw();
    ofPopMatrix();
    
    float startingAngle = ofGetElapsedTimef() * TWO_PI / 8;
    
    
    
    for (int i=0; i<polyline.size(); i++) {
        
        //add offset to each point on the polyline relative to the starting point and assign them to the new movePolyline1
        ofVec3f normal = polyline.getNormalAtIndexInterpolated(i);
        float angleOffset = (float)i/(float)polyline.size() * PI ;
        float scale = i * 3 * sin(startingAngle + angleOffset) * cos( (startingAngle + angleOffset) / 4);
        movePolyline1[i] = polyline[i] + (scale * normal);
        
        //set the colors for the normals
        ofColor normalColor(0, 150, 0);
        normalColor.setBrightness(i*5);// decrease the brightness as it gets to the top
        ofSetColor(normalColor);
        
        //draw the normals
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofLine(movePolyline1[i]-normal*(polyline.size() -i), movePolyline1[i]+normal*(polyline.size() -i));
        ofPopMatrix();
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
