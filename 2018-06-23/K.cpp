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

	string s; cin >> s;

	int n = s.size();
	int numthreesafter = 0;
	int numonesbefore = 0;
	for(auto cur :  s) {
		if(cur == '3') numthreesafter++;
	}

	int bestAns = numthreesafter;

	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			numonesbefore++;
		} else {
			numthreesafter--;
		}

		bestAns = min(bestAns, numonesbefore + numthreesafter);
	}

	cout << bestAns << endl;
	
	return 0;
}