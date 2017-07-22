#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> marks;
vector<int> cumsum = {0};
vector<int> inter;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int n, k; cin >> k >> n;

	for(int i = 0; i < k; i++) {
		int curr; cin >> curr; marks.push_back(curr);
		cumsum.push_back(cumsum[cumsum.size() - 1] + curr);
	}

	for(int i = 0; i < n; i++) {
		int curr; cin >> curr; inter.push_back(curr);
	}
	set<int> possible;
	for(int i = 0; i < k; i++) {
		set<int> seen;
		for(int i : inter) {
			seen.insert(i);
		}

		for(int j = 0; j < k; j++) {
			int curScore = cumsum[j+1] - cumsum[i+1] + inter[0];
			seen.erase(curScore);
		}

		if(seen.size() == 0) {
			possible.insert(inter[0] - cumsum[i+1]);
		}
	}

	cout << possible.size() << endl;
	
	return 0;
}