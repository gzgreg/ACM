#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int start; cin >> start;
	int idx = 1;
	while(start != 0) {
		vector<int> x, y;
		int totalX = 0, totalY = 0;
		for(int i = 0; i < start; i++) {
			int xi, yi; cin >> xi >> yi;
			x.push_back(xi); y.push_back(yi);
		}

		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		cout << "Case " << idx << ": ";
		cout << "(" << x[(start+1)/2 - 1] << "," << y[(start+1)/2 - 1] << ") ";

		for(int i = 0; i < start; i++) {
			totalX += abs(x[(start+1)/2 - 1] - x[i]);
			totalY += abs(y[(start+1)/2 - 1] - y[i]);
		}
		cout << totalX + totalY << endl;

		cin >> start;
		idx++;
	}
	
	return 0;
}