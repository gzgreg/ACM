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

	int n; cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; sum += cur-1;
	}

	cout << (sum % 2 ? "Constantine" : "Mike") << endl;

	
	return 0;
}