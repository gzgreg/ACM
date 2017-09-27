#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int x;

set<int> curVals;

set<pair<pair<double,double>, vector<int>>> results;

void dfs(int vals, int start) {
	if(vals == 0) {
		vector<int> vals1;
		vector<int> vals2;
		for(int i = 0; i < 2*x; i++) {
			if(!curVals.count(i)) {
				vals2.push_back(i);
			} else {
				vals1.push_back(i);
			}
		}

		int pts = 0;
		int games = 0;
		int totpts = 0;

		do {
			int curAns = 0;
			for(int i = 0; i < x; i++) {
				if(vals1[i] > vals2[i]) {
					curAns += vals2[i]+1;
					//totpts += vals2[i] + 1;
				} else {
					curAns -= vals1[i]+1;
				}
			}
			if(curAns > 0) {
				pts += 2;
			} else if (curAns == 0) {
				pts += 1;
			}
			games++;
			totpts += curAns;
		} while(next_permutation(vals1.begin(),vals1.end()));
		cout << fixed << setprecision(5);
		results.insert({{(double) totpts/games, (double) pts/games/2}, vals1});
		return;
	}
	for(int i = start; i < 2*x - vals + 1; i++) {
		curVals.insert(i);
		dfs(vals-1, i+1);
		curVals.erase(i);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> x;
	dfs(x, 0);

	for(auto ans : results) {
		cout << ans.first.first << " " << ans.first.second << endl;
		int tot = 0;
		for(int i = 0; i < x; i++) {
			cout << ans.second[i]+1 << " ";
			tot += ans.second[i]+1;
		}
		cout << endl;
		cout << tot << endl;
		cout << "==========================" << endl;
	}
	
	return 0;
}