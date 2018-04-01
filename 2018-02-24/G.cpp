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

	int P, K; cin >> P >> K;

	vector<vector<int>> piles;
	for(int i = 0; i < P; i++) {
		int N; cin >> N;
		piles.push_back(vector<int>());
		for(int j = 0; j < N; j++) {
			int cur; cin >> cur; piles.back().push_back(cur);
		}
	}
	vector<int> grundy;
	for(vector<int> cur : piles) {
		vector<int> curGrundy {0};
		for(int i = 0; i < cur.size(); i++) {
			set<int> nums;
			for(int j = max(i-K, 0); j <= i; j++) {
				if(j - cur[j] >= -1) {
					nums.insert(curGrundy[j - cur[j] + 1]);
				}
			}
			int num = 0;
			while(nums.count(num)) num++;
			curGrundy.push_back(num);
		}
		grundy.push_back(curGrundy.back());
	}

	int cur = 0;
	for(auto val : grundy) {
		cur ^= val;
	}
	if(cur != 0) {
		cout << "Alice can win." << endl;
	} else {
		cout << "Bob will win." << endl;
	}
	
	return 0;
}