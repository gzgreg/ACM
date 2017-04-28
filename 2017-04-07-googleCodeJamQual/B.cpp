#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		ll N; cin >> N;
		string s = to_string(N);

		int tenpow = 10;
		for(int i = 1; i < s.size(); i++) {
			if(s[i] < s[i-1]) {
				s[i-1]--;
				for(int j = i; j < s.size(); j++) {
					s[j] = '9';
				}
				i = 0;
			}
		}
		cout << "Case #" << id << ": " << stoll(s) << endl;
	}

	return 0;
}