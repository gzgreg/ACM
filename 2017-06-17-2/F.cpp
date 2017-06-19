#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void query(int i, int j) {
	cout << "? " << i << " " << j << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;

	set<int> unknown;
	for(int i = 1; i <= n; i++) {
		unknown.insert(i);
	}
	while(unknown.size() > 2) {
		vector<int> toRemove;
		int toPair;
		bool inPair = false;
		vector<pii> paired;
		for(int i : unknown) {
			if(!inPair) {
				inPair = true;
				toPair = i;
			} else {
				inPair = false;
				query(toPair, i);
				string a, b; cin >> a >> b;
				if(a == "-" || b == "-") {
					toRemove.push_back(i);
					toRemove.push_back(toPair);
				} else {
					paired.push_back({toPair, i});
					toRemove.push_back(toPair);
				}
			}
		}

		if(inPair) {
			int good = 0, bad = 0;
			for(pii curr : paired) {
				query(toPair, curr.first);
				string a, b; cin >> a >> b;
				if(a == "+" && b == "+") {
					good++;
				} else {
					bad++;
				}
			}
			if(good < bad) {
				toRemove.push_back(toPair);
			}
		}
		for(int i : toRemove) {
			unknown.erase(i);
		}
	}

	int good = *(unknown.begin());
	set<int> goodVals;
	for(int i = 1; i <= n; i++) {
		if(good == i) continue;
		query(i, good);
		string a, b; cin >> a >> b;
		if(a == "+" && b == "+") {
			goodVals.insert(i);
		}
	}
	goodVals.insert(good);

	cout << "! " << goodVals.size() << " ";
	for(int i : goodVals) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}