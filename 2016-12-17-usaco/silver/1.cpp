#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> locs;

int find(int loc) {
	int l = 0, r = locs.size() - 1;

	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(locs[mid] > loc) {
			r = mid - 1;
		} else if (locs[mid] < loc) {
			l = mid + 1;
		} else {
			return mid;
		}
	}
	return l;
}

int main(){
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int N, Q; cin >> N >> Q;
	for(int i = 0; i < N; i++) {
		int a; cin >> a; locs.push_back(a);
	}

	sort(locs.begin(), locs.end());
	for(int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;

		if(locs[find(r)] == r) {
			cout << find(r) - find(l) + 1 << endl;
		} else {
			cout << find(r) - find(l) << endl;
		}
	}
	return 0;
}