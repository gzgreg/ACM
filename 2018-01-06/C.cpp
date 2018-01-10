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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int h, w; cin >> h >> w;

	vector<pii> output;

	if(h%2 == 1 && h >= 2) {
		for(int i = 0; i < w/2-1; i++) {
			output.push_back({h-2, 2*i});
		}
	}

	for(int i = 0; i < h/2; i++) {
		for(int j = 0; j < w-2; j++) {
			output.push_back({2*i, j});
		}
	}
	if(w >= 2) {
		for(int i = 0; i < h-1; i++) {
			output.push_back({i, w-2});
		}
	}

	cout << output.size() << endl;
	for(auto cur : output) {
		cout << cur.first+1 << " " << cur.second+1 << endl;
	}
	
	return 0;
}