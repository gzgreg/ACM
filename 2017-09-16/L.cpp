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

	int n; cin >> n;
	vector<ll> vals;
	for(int i = 0;  i< n; i++) {
		ll cur; cin >> cur; vals.push_back(cur);
	}

	cout << vals[0] << " ";
	for(int i = 0; i < n-1; i++) {
		cout << vals[i+1] - vals[i] << " ";
	}
	cout << endl;
	
	return 0;
}