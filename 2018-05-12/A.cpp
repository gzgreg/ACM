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

		map<int, int> freqs;
		string s; int freq;
		for(int i = 0; i < N; i++) {
			cin >> s >> freq;
			freqs[freq]++;
		}

		int maxFreq = 0;
		int maxId = 0;
		for(auto cur : freqs) {
			if(cur.second > maxFreq) {
				maxFreq = cur.second;
				maxId = cur.first;
			}
		}
		cout << maxId << endl;
	}
	
	return 0;
}