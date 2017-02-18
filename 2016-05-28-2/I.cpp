#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int c, n, a; cin >> c >> n >> a;

	vector<int> acc;
	for(int i = 0; i < a; i++) {
		int curr; cin >> curr; acc.push_back(curr);
	}

	map<int, set<int>> accesses;

	for(int i = 0; i < a; i++) {
		accesses[acc[i]].insert(i);
	}

	set<int> cache;
	int ans = 0;
	priority_queue<pii> bestRemove;
	for(int i = 0; i < a; i++) {
		accesses[acc[i]].erase((accesses[acc[i]].begin()));
		if(cache.count(acc[i])) {
			if(accesses[acc[i]].size() == 0) {
				bestRemove.push({10000000, acc[i]});
			} else {
				bestRemove.push({*(accesses[acc[i]].begin()), acc[i]});
			}
			continue;
		}
		if(cache.size() < c) {
			cache.insert(acc[i]);
			if(accesses[acc[i]].size() == 0) {
				bestRemove.push({10000000, acc[i]});
			} else {
				bestRemove.push({*(accesses[acc[i]].begin()), acc[i]});
			}
			ans++;
			continue;
		}

		pii remove = bestRemove.top(); bestRemove.pop();
		cache.erase(remove.second);
		cache.insert(acc[i]);
		if(accesses[acc[i]].size() == 0) {
			bestRemove.push({10000000, acc[i]});
		} else {
			bestRemove.push({*(accesses[acc[i]].begin()), acc[i]});
		}
		
		ans++;
	}
	cout << ans << endl;

	return 0;
}