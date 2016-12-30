#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	set<pair<ll, ll>> nums;

	string s;
	while(cin >> s) {
		ll num1, num2;
		string s2;
		int i = 0;
		while(s[i] != '-') {
			s2.push_back(s[i]);
			i++;
		}
		num1 = atoll(s2.c_str());
		s2 = "";
		i++;
		while(i < s.size()) {
			s2.push_back(s[i]);
			i++;
		}
		num2 = atoll(s2.c_str());

		nums.insert({num1, num2});
	}
	ll numValid = 0;
	ll valid = 0;
	for(pair<ll, ll> curr : nums) {
		if(curr.first <= valid + 1) {
			valid = max(valid, curr.second);
		} else {
			numValid += curr.first - valid - 1;
			valid = max(valid, curr.second);
		}
	}

	cout << numValid << endl;
	
	return 0;
}