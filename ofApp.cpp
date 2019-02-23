#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	vector<glm::vec3> vertices_1;
	vector<glm::vec3> vertices_2;
	for (int i = 0; i < 3600; i += 1) {

		float v = i + 0.1;
		auto noise_point = glm::vec2(cos(v * DEG_TO_RAD), sin(v * DEG_TO_RAD));
		int u_start = ofMap(ofNoise(noise_point.x, noise_point.y, ofGetFrameNum() * 0.01), 0, 1, 0, 720);

		vertices_1.push_back(this->make_point(250, 50, (u_start)* DEG_TO_RAD, v * DEG_TO_RAD));
		vertices_2.push_back(this->make_point(250, 50, (u_start + 180) * DEG_TO_RAD, v * DEG_TO_RAD));
	}

	ofBeginShape();
	ofVertices(vertices_1);
	ofEndShape(true);

	ofBeginShape();
	ofVertices(vertices_2);
	ofEndShape(true);

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	float x = (R + r * cos(u)) * cos(v);
	float y = (R + r * cos(u)) * sin(v);
	float z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}