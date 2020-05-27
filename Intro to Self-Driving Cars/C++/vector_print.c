#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<float> myvector (5);
	
	myvector[0] = 5.0;
	myvector[1] = 3.0;
	myvector[2] = 2.7;
	myvector[3] = 8.2;
	myvector[4] = 7.9;

	for (int i = 0; i < myvector.size(); i++) {
		cout << myvector[i] << " ";
	}

	cout << endl;

	return 0;
}
