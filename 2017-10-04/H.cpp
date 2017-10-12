#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int memo1[100500];
int memo2[100500];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int H; cin >> H;
	vector<int> hp;
	for(int i = 0; i < H; i++) {
		int cur; cin >> cur; hp.push_back(cur);
	}

	int B; cin >> B;
	vector<int> bp;
	for(int i = 0; i < B; i++) {
		int cur; cin >> cur; bp.push_back(cur);
	}
	
	memset(memo1, -1, sizeof memo1);
	memo1[0] = 0;
	for(int i : bp) {
		for(int j = 100000; j >= 0; j--) {
			if(memo1[j] != -1) {
				if(memo1[j+i] == -1) {
					memo1[j+i] = memo1[j] + 1;
				} else {
					memo1[j + i] = min(memo1[j+i], memo1[j] + 1);
				}
			}
		}
	}

	memset(memo2, -1, sizeof memo2);
	memo2[0] = 0;
	for(int i : hp) {
		for(int j = 100000; j >= 0; j--) {
			if(memo2[j] != -1) {
				if(memo2[j+i] == -1) {
					memo2[j+i] = memo2[j] + 1;
				} else {
					memo2[j + i] = min(memo2[j+i], memo2[j] + 1);
				}
			}
		}
	}
	int ans = 2e9 + 1;
	for(int i = 1; i <= 100000; i++) {
		if(memo1[i] != -1 && memo2[i] != -1){
			ans = min(ans, memo1[i] + memo2[i]);
		}
	}
	if(ans == 2e9 + 1) {
		cout << "impossible" << endl;
	} else {
		cout << ans << endl;
	}

	return 0;
}