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
	
	int N, M; cin >> N >> M;

	map<int, int> cnt;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cnt[i+j]++;
		}
	}
	int best = 0;
	set<int> vals;
	for(auto cur : cnt) {
		if(cur.second > best) {
			vals.clear();
			best = cur.second;
			vals.insert(cur.first);
		} else if (cur.second == best) {
			vals.insert(cur.first);
		}
	}

	for(auto val : vals) {
		cout << val+2 << endl;
	}

	return 0;
}