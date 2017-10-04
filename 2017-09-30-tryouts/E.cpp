#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<int> unchecked;
	srand(1);
	for(int i = 0; i < 2601; i++) {
		unchecked.insert(i);
	}
	int t = 0;
	while(true) {
		map<int, set<int>> times;
		for(int i : unchecked) {
			times[(i / 51) + (i % 51) * t].insert(i);
		}

		int bestTime = 0;
		int bestVal = 0;
		int nextBestTime;
		int nextBestVal = 0;
		for(auto cur : times) {
			if((rand() % 2 && cur.second.size() > bestVal)
				|| (!(rand() % 2) && cur.second.size() >= bestVal)) {
				nextBestVal = bestVal;
				nextBestTime = bestTime;
				bestVal = cur.second.size();
				bestTime = cur.first;
			}
		}
		cout << bestTime + 3017 << endl;
		string s; cin >> s;
		if(s[1] == 'a') {
			return 0;
		} else if (s[1] == 'i') {
			t++;
			for(auto cur : times[bestTime]) {
				unchecked.erase(cur);
			}
		} else {
			return 0;
		}
	}
	
	return 0;
}