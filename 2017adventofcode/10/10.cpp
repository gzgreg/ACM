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

	vector<int> vals;
	string s; getline(cin, s);
	for(int i = 0; i < s.size(); i++) {
		vals.push_back(s[i]);
	}
	vals.push_back(17);
	vals.push_back(31);
	vals.push_back(73);
	vals.push_back(47);
	vals.push_back(23);
	vector<int> out;

	for(int i = 0; i < 256; i++) {
		out.push_back(i);
	}
	int start = 0, skip = 0;

	for(int it = 0; it < 64; it++) {
		for(int i = 0; i < vals.size(); i++) {
			reverse(out.begin(), out.begin() + vals[i]);
			rotate(out.begin(), out.begin() + ((vals[i]+ skip) % out.size()), out.end());
			start += 100*out.size() - vals[i] - skip;
			start %= out.size();
			skip++;
		}
	}

	for(int i = 0; i < 16; i++) {
		int ans = 0;
		for(int j = i*16; j < i*16 + 16; j++) {
			ans ^= out[(j + start) % out.size()];
		}
		cout << hex << ans;
	}
	

	return 0;
}