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
	
	set<string> ans;
	vector<string> good = {"cool", "not bad", "don't think so", "don't touch me", "great"};
	vector<string> bad = {"don't even", "terrible", "worse", "go die in a hole", "are you serious?", "no way"};
	int goodCount = 0;
	for(int i = 0; i < 10; i++) {
		cout << i << endl;
		string cur; getline(cin, cur);
		if(cur == "no") {
			goodCount++;
			if(goodCount >= 4) {
				cout << "normal" << endl;
				return 0;
			}
		} else {
			for(auto val : good) {
				if(cur == val) {
					cout << "normal" << endl;
					return 0;
				}
			}
			for(auto val : bad) {
				if(cur == val) {
					cout << "grumpy" << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}