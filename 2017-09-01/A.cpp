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

	int k; cin >> k;

	string ans;
	if(k == 0) {
		cout << "a" << endl;
	}
	for(int i = 0; i < 26; i++) {
		int n = 0;
		while(n * (n - 1) / 2 < k) {
			n++;
		}
		if(n * (n-1) / 2 > k) n--;

		for(int j = 0; j < n; j++) {
			ans.push_back('a' + i);
		}

		k -= n * (n - 1) / 2;
		if(k == 0) break;
	}

	cout << ans << endl;
	
	return 0;
}