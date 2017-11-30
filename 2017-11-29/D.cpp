#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> ans;

int permute(int l, int r, int k) {
	int mid = (l+r) / 2;

	if(l == r-1) {
		return 1;
	}
	int ret = 1;

	if(k == 1) {
		return 1;
	} else {
		swap(ans[mid-1], ans[mid]);
		ret += permute(l, mid, k-2);
		if(ret < k) {
			ret += permute(mid, r, k-ret);
		}
		return ret;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k; cin >> n >> k;
	
	for(int i = 0; i < n; i++) {
		ans.push_back(i);
	}

	if(k % 2 == 0 || k >= 2*n) {
		cout << -1 << endl;
		return 0;
	}

	permute(0, n, k);

	for(auto cur : ans) {
		cout << cur+1 << " ";
	}
	cout << endl;
	return 0;
}