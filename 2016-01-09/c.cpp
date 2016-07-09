#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	double prob[1122];
	int n, m; cin >> n >> m;

	map<int, int> given;

	for(int i = 0; i < n; i++){
		string curr; cin >> curr;
		if(i == n-1) break;
		int val;
		if(curr == "A"){
			val = 11;
		} 
		else if(curr == "J" || curr == "Q" || curr == "K"){
			val = 10;
		} 
		else {
			istringstream( curr ) >> val;
		}
		given.insert(make_pair(m, val));
		m += val;
	}

	memset(prob, 0, sizeof prob);
	for(int i = 1; i <= 10; i++){
		prob[i] = 0.1;
	}

	for(int i = 1; i <= m; i++){
		double curr = prob[i];
		if(given.find(i) != given.end()){
			prob[i+given.find(i)->second] += curr;
		} else {
			for(int j = 2; j <= 9; j++){
				prob[i+j] += 1.0/13*curr;
			}
			prob[i+10] += 4.0/13*curr;
			prob[i+11] += 1.0/13*curr;
		}
	}

	cout << fixed << setprecision(9) << prob[m] << endl;

	return 0;
}