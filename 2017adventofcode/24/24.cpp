#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> vals;
bitset<56> vis;
int maxCount = 0;
int gAns = 0;
int dfs(int node) {
	int bestAns = 0;
	for(int i = 0; i < vals.size(); i++) {
		if(vis[i]) continue;
		if(vals[i].first == node || vals[i].second == node) {
			int next;
			if(vals[i].first == node) {
				next = vals[i].second;
			} else {
				next = vals[i].first;
			}
			vis[i] = true;
			bestAns = max(bestAns, dfs(next) + vals[i].first + vals[i].second);
			if(vis.count() == maxCount) {
				int curAns = 0;
				for(int i = 0; i < 56; i++) {
					if(vis[i]) {
						curAns += vals[i].first;
						curAns += vals[i].second;
					}
				}
				gAns = max(gAns, curAns);
			} else if (vis.count() > maxCount) {
				maxCount = vis.count();
				int curAns = 0;
				for(int i = 0; i < 56; i++) {
					if(vis[i]) {
						curAns += vals[i].first;
						curAns += vals[i].second;
					}
				}
				gAns = curAns;
			}
			vis[i] = false;
		}
	}
	return bestAns;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	while(getline(cin, s)) {
		stringstream str(s);

		int val1, val2; char junk;
		str >> val1 >> junk >> val2;
		vals.push_back({val1, val2});
	}

	cout << dfs(0) << endl;
	cout << maxCount << " " << gAns << endl;
	
	return 0;
}