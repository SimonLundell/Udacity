#include <iostream>
#include <vector>
#include <string>
#include "sense_and_move.h"

using namespace std;

//Function declarations
vector <float> sense(vector<float> p, string Z); 
vector <float> move(vector<float> p, float U);

//Vector initiations
vector <float> p(5, 0.2);
vector <string> world(5);
vector <string> measurements(2);
vector <float> motions(2, 1);

//Variable initiations
float pHit = 0.6;
float pMiss = 0.2;
float pExact = 0.8;
float pOvershoot = 0.1;
float pUndershoot = 0.1;

int main() {

	world[0] = "green";
	world[1] = "red";
	world[2] = "red";
	world[3] = "green";
	world[4] = "green";

	measurements[0] = "red";
	measurements[1] = "green";
	
	for (int k = 0; k < measurements.size(); k++) {
		p = sense(p, measurements[k]);
		p = move(p, motions[k]);
		}

	for (int j = 0; j < p.size(); j++) {
		cout << p[j] << " ";
		}
	
	return 0;
}


vector <float> sense(vector<float> p, string Z) {
	vector<float> q;
	float s = 0;
	for (int i = 0; i < p.size(); i++) {
		bool hit = (Z == world[i]);
		q.push_back(float(p[i] * (hit * pHit + (1-hit) * pMiss)));
		}

	for (int j = 0; j < p.size(); j++) {
		s = s + q[j]; 
		}

	for (int k = 0; k < q.size(); k++) {
		q[k] = q[k] / s;
		}
	/*
	for (int i = 0; i < q.size(); i++) {
		cout << q[i] << " ";
		}
	*/
	return q;
}



vector <float> move(vector<float> p, float U) {
	vector<float> q;
	float s = 0;
	for (int i = 0; i < p.size(); i++) {
		if (i-U < 0) {
			s = pExact * p[int(i-U) + int(p.size())];
		}
		else {
			s = pExact * p[int(i-U) % int(p.size())];
		}
		if (i-U-1 < 0) {
			s = s + pOvershoot * p[int(i-U-1) + int(p.size())];
		}
		else {
			s = s + pOvershoot * p[int(i-U-1) % int(p.size())];
		}
		if (i-U+1 < 0) {
			s = s + pOvershoot * p[int(i-U+1) + int(p.size())];
		}
		else {
			s = s + pOvershoot * p[int(i-U+1) % int(p.size())];
		}

		q.push_back(s);
	}
	
	return q;	
}
