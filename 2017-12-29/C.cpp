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

	int n, r; cin >> n >> r;

	vector<int> x;
	for(int i = 0; i < n; i++) {
		int cur; cin >> cur; x.push_back(cur);
	}

	vector<ld> height;

	for(int i = 0; i < n; i++) {
		ld y = r;
		for(int j = 0; j < i; j++) {
			if(abs(x[i] - x[j]) <= 2*r) {
				ld curHeight = height[j] + sqrt((ld)(2*r*2*r) - (x[i] - x[j])*(x[i] - x[j]));
				y = max(y, curHeight);
			}
		}
		height.push_back(y);
	}

	cout << fixed << setprecision(10);
	for(auto cur : height) {
		cout << cur << " ";
	}
	cout << endl;
	
	return 0;
}