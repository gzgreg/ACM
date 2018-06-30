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

	int k; cin >> k;

	string s; cin >> s;

	map<int, int> cnt;

	int maxLen = 0;
	int idx = 0;
	int diffChars = 0;
	pii bestAns;

	for(int i = 0; i < s.size(); i++) {
		if(cnt[s[i]] == 0) diffChars++;
		cnt[s[i]]++;
		while(diffChars > k) {
			cnt[s[idx]]--;
			if(cnt[s[idx]] == 0) diffChars--;
			idx++;
		}

		if(i - idx > maxLen) {
			maxLen = i - idx;
			bestAns = {idx, i};
		}
	}

	cout << bestAns.first + 1 << " " << bestAns.second + 1 << endl;
	
	return 0;
}