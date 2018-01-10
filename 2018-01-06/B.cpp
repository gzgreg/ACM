#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> cnt(3);
int steps = 0;
bool found = false;
vector<int> vals;
void Hanoi(int x, int y, int z, int n) {
	if(n > 0) {
		Hanoi(x, z, y, n-1);
		//cout << n << " " << x << " " << y << endl;
		cnt[x]--;
		cnt[y]++;
		steps++;
		if(cnt[0] == cnt[1]
			&& cnt[0] == cnt[2]
			&& !found) {
			vals.push_back(steps);
			found = true;
			return;
		}
		Hanoi(z, y, x, n-1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N; cin >> N;
	cnt[0] = N;
	for(int i = 1; i < 10; i++) {
		cnt[0] = 3*i;
		cnt[1] = 0;
		cnt[2] = 0;
		found = false;
		steps = 0;
		Hanoi(0, 1, 2, 3*i);
	}
	vector<int> newVals;
	for(int iter = 0; iter < 1; iter++) {
		newVals.clear();
		for(int i = 0; i < vals.size(); i++) {
			cout << vals[i] << " " << bitset<18>(vals[i]) << endl;
			if(i < vals.size()-1) {
				newVals.push_back(vals[i+1] - vals[i]);
			}
		}
		vals = newVals;
		cout << endl;
	}
	cout << endl;
	
	return 0;
}