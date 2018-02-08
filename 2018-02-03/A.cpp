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

	int N; cin >> N;
	string bestName;
	int bestVal = numeric_limits<int>::min();
	for(int i = 0; i < N; i++) {
		string name; cin >> name;
		int val; cin >> val;
		if(val > bestVal) {
			bestVal = val;
			bestName = name;
		}
	}

	cout << bestName << endl;
	
	return 0;
}