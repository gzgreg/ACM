#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

string makeCentered(int len) {
	string output;
	for(int i = 0; i < 27; i++) {
		output.push_back('.');
	}
	for(int i = 0; i < len; i++) {
		output[13 + i] = 'X';
		output[13 - i] = 'X';
	}
	return output;
}

string blank() {
	string output;
	for(int i = 0; i < 27; i++) {
		output.push_back('.');
	}
	return output;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input; cin >> input;
	vector<int> target;
	for(int i = 0; i < input.size(); i++) {
		target.push_back(int(input[i]));
	}
	vector<string> output;
	int val = 0;
	for(int i = 0; i < target.size(); i++) {
		int curTarget = target[i];
		vector<int> triSizes;
		int distance = curTarget - val;
		//cout << curTarget << " " << val << " " << distance << endl;

		if(i != 0) distance = val - curTarget;
		while(distance < 0) distance += 256;
		while(distance > 0) {
			if(i == 0) {

				for(int j = 12; j >= (i == 0 ? 1 : 2); j--) {
					int next;
					if(i != 0) next = j*j - 1;
					else next = j*j; 
					if(next <= distance) {
						for(int k = 1; k <= j+1; k++) {
							cout << makeCentered(k) << endl;
						}
						distance -= next;
						val += next;
						val %= 256;
						cout << blank() << endl;
						break;
					}
				}
			} else {
				cout << makeCentered(1) << endl;
				cout << blank() << endl;

				distance -= 1;
				val -= 1;
				if(val < 0) val += 256;

			}
		}
		cout << blank() << endl;
		string curString = blank();
		curString[0] = 'X';
		curString[curString.size() - 1] = 'X';
		cout << curString << endl;
		curString[curString.size() - 1] = '.';
		cout << curString << endl;
		cout << blank() << endl;
	}


	return 0;
}