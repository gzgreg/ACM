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
	
	int T; cin >> T;
	while(T--) {
		int N; cin >> N;
		string s; cin >> s;
		vector<ll> zeros; zeros.push_back(0);
		for(char i : s) {
			if (i == '1') {
				zeros.push_back(0);
			} else {
				zeros[zeros.size() - 1]++;
			}
		}
		int numOnes = zeros.size() - 1;
		vector<ll> cumsum; cumsum.push_back(0);
		vector<ll> evens, odds; 
		evens.push_back(0); 
		odds.push_back(0);
		for(int i = 0; i < zeros.size(); i++) {
			cumsum.push_back(cumsum[cumsum.size() - 1] + zeros[i]);
			if(i % 2) {
				odds.push_back(odds[odds.size() - 1] + zeros[i]);
				evens.push_back(evens[evens.size() - 1]);
			} else {
				odds.push_back(odds[odds.size() - 1]);
				evens.push_back(evens[evens.size() - 1] + zeros[i]);
			}
		}
		ll ans = 0;
		for(int i = 1; i < numOnes - 1; i++) {
			int width = min(i, numOnes - i - 1);

			ans += width;
			ans += cumsum[i + width + 2] - cumsum[i + 2];
			ans += cumsum[i] - cumsum[i - width];
		}

		for(int i = 0; i < zeros.size(); i++) {
			if(i % 2) {
				ans += zeros[i] * (evens[evens.size() - 1] - evens[i]);
			} else {
				ans += zeros[i] * (odds[odds.size() - 1] - odds[i]);
			}
		}
		cout << ans << endl;
	}

	return 0;
}