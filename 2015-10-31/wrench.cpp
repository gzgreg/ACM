#include <bits/stdc++.h>
using namespace std;
int powers[] = {2, 4, 8, 16, 32, 64, 128};
int main(){
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		string s; cin >> s;
		double val = atof(s.c_str());
		bool space=false;
		int precision = s.find(".") == string::npos ? 0 : s.size() - s.find(".") - 1;
		if(floor(val) != 0){
			space = true;
			cout << floor(val);
			val -= floor(val);
		}
		int multVal = round(val * pow(10, precision));
		for(int j = 0; j < 7; j++){
			int numer = round(val * powers[j]);
			double approx = (double) numer / powers[j] * pow(10, precision);
			if((int) floor(approx) == multVal || (int) ceil(approx) == multVal){
				if(numer == 0) continue;
				if(space) cout << " ";
				cout << numer << "/" << powers[j];
				break;
			}
		}
		cout << "\"" << endl;
	}
	return 0;
}