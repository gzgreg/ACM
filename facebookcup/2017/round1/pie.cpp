#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int>> prices (300, vector<int> ());

vector<vector<int>> memo (305, vector<int>(305, 1e9));

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";
		int N, M; cin >> N >> M;

		prices = vector<vector<int>> (300, vector<int> ());
		memo = vector<vector<int>> (305, vector<int>(305, 1e9));

		for(int i = 0; i < N; i++) {
			vector<int> tmp;
			for(int j = 0; j < M; j++) {
				int curr; cin >> curr; tmp.push_back(curr);
			}
			sort(tmp.begin(), tmp.end());
			prices[i] = tmp;
		}

		memo[0][0] = 0;
		for(int day = 1; day <= N; day++) {
			for(int bought = 0; bought <= N; bought++) {
				int i = 0;
				int totPrice = 0;
				memo[day][bought] = memo[day-1][bought];
				for(int price : prices[day-1]) {
					i++;
					if(i > bought) break;
					totPrice += price;
					memo[day][bought] = min(memo[day][bought], memo[day-1][bought-i]+totPrice+i*i);
				}
			}
		}

		cout << memo[N][N] << endl;
	}
	
	return 0;
}