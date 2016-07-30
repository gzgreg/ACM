#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int across[6] = {5, 3, 4, 1, 2, 0};
//pairs: 0 5, 1 3, 2 4

int main(){
	ios::sync_with_stdio(0);

	double prob = 1;
	string start; cin >> start;
	string end; cin >> end;
	vector<string> cubes;
	for(int i = 0; i < start.size(); i++) {
		string curr; cin >> curr; cubes.push_back(curr);
	}

	for(int i = 0; i < start.size(); i++) {
		if(start[i] == end[i]) continue;
		string currCube = cubes[i];
		vector<int> currFronts;
		for(int j = 0; j < 6; j++) {
			if(currCube[j] == start[i]) {
				currFronts.push_back(j);
			}
		}
		double currProb = 0;
		for(int currFront : currFronts) {
			if(currCube[across[currFront]] == end[i]) {
				//if across, always possible to rotate twice
				currProb += 1.0; 
				continue;
			}
			
			pii pair1, pair2;
			if(currFront == 0 || currFront == 5) {
				pair1 = {1, 3}; pair2 = {2, 4};
			} else if (currFront == 1 || currFront == 3) {
				pair1 = {0, 5}; pair2 = {2, 4};
			} else {
				pair1 = {0, 5}; pair2 = {1, 3};
			}
			double ways = 0;
			if(currCube[pair1.first] == end[i]
				|| currCube[pair1.second] == end[i]) {
				ways++;
			}
			if(currCube[pair2.first] == end[i]
				|| currCube[pair2.second] == end[i]) {
				ways++;
			}
			currProb += ways / 2.0;
		}
		prob *= currProb;
		prob /= currFronts.size();
	}

	cout << fixed << setprecision(10) << prob << endl;
	
	return 0;
}