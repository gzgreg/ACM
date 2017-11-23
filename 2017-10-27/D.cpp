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

	ll n, k, m; cin >> n >> k >> m;

	vector<int> bus;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; bus.push_back(cur);
	}

	ll cursz = 1;
	set<int> keep;
	vector<int> next;
	vector<int> prev;
	for(int i = 0; i < n; i++) {
		keep.insert(i);
		next.push_back(i+1);
		prev.push_back(i-1);
	}

	for(int i = 1; i < n; i = next[i]) {
		if(bus[i] == bus[prev[i]]) {
			cursz++;
		} else {
			cursz = 1;
		}
		if(cursz == k) {
			int j = i;
			for(int cnt = 0; cnt < k; j = prev[j], cnt++) {
				keep.erase(j);
			}
			cursz = 1;
			next[j] = next[i];
			if(j != -1) {
				i = j;
				prev[next[i]] = j;
				while(prev[i] != -1 && bus[i] == bus[prev[i]]) {
					i = prev[i];
				}
			}
		}
	}
	vector<int> newBus;
	for(int i : keep) {
		newBus.push_back(bus[i]);
	}

	if(newBus.size() == 0) {
		cout << 0 << endl;
		return 0;
	}

	bus = newBus;
	int i = bus.size() - 1;
	int j = 0;
	cursz = 0;
	ll totSz = bus.size() * m;
	if(bus[0] == 8 && k == 42) cout << totSz << endl;
	while(true) {
		if(bus[i] == bus[j]) {
			cursz = 2;
			if(i == j) cursz = 1;
		} else {
			break;
		}
		while(bus[i] == bus[i-1] && i > j) {
			i--;
			cursz++;
		}

		while(bus[j] == bus[j+1] && j < i) {
			j++;
			cursz++;
		}
		if(i == j) {
			totSz -= (m*cursz / k) * k;
			if((m*cursz % k) == 0) {
				totSz = 0;
			}
		}
		totSz -= (m-1) * (cursz / k) * k;
		if(bus[0] == 8 && k == 42) cout << totSz << endl;

		if(cursz % k != 0) break;
		i--;
		j++;
		if(i < 0 || j == bus.size() - 1) break;
	}

	cout << totSz << endl;
	
	return 0;
}