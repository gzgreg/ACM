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
	
	string s;

	vector<vector<int>> vals;

	while(getline(cin, s)) {
		if(s.size() == 0) continue;
		stringstream ss(s);
		int cur;
		vals.push_back(vector<int>());
		while(ss >> cur) {
			vals.back().push_back(cur);
		}
	}

	for(int i = 0; i < vals[0].size(); i++) {
		for(int j = 0; j < vals.size(); j++) {
			cout << vals[j][i] << " ";
		}
		cout << endl;
	}

	return 0;
}