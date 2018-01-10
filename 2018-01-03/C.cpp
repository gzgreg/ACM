#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 1000000007

ll factorial(ll num) {
	ll ans = 1;
	for(int i = 2; i <= num; i++) {
		ans *= i;
		ans %= MOD;
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, m; cin >> n >> m;

	set<set<ll>> gyms;
	unordered_set<int> seen;
	vector<unordered_set<int>> sets;
	for(int i = 0; i < n; i++) {
		int gi; cin >> gi;
		map<ll, ll> vals;
		for(int j = 0; j < gi; j++) {
			int cur; cin >> cur; cur--;
			seen.insert(cur);
			vals[cur]++;
		}
		map<ll, set<ll>> counts;
		for(auto cur : vals) {
			counts[cur.second].insert(cur.first);
		}

		for(auto cur : counts) {
			gyms.insert(cur.second);
		}
	}

	sets.push_back(seen);
	vector<int> refSet(m, 0);

	for(auto cur : gyms) {
		set<int> allRefSetsSet;
		for(auto val : cur) {
			allRefSetsSet.insert(refSet[val]);
		}
		vector<int> allRefSets(allRefSetsSet.begin(), allRefSetsSet.end());
		vector<unordered_set<int>> setInters;
		for(auto val : allRefSets) {
			unordered_set<int> curSet;
			for(auto curVal : cur) {
				if(sets[val].count(curVal)) {
					curSet.insert(curVal);
				}
			}
			setInters.push_back(curSet);
		}

		for(int i = 0; i < allRefSets.size(); i++) {
			if(sets[allRefSets[i]].size() != setInters[i].size()) {
				sets.push_back(setInters[i]);
				for(auto cur : setInters[i]) {
					sets[allRefSets[i]].erase(cur);
					refSet[cur] = sets.size() - 1;
				}
			}
		}
	}
	ll ans = factorial(m - seen.size());
	set<int> allRefSetsSet;
	for(auto cur : refSet) {
		allRefSetsSet.insert(cur);
	}

	for(auto cur : allRefSetsSet) {
		ans *= factorial(sets[cur].size());
		ans %= MOD;
	}

	cout << ans << endl;
	
	return 0;
}