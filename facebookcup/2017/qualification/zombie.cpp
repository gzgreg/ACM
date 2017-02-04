#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<vector<double>>> memo (21, vector<vector<double>> (21, vector<double> (400, 0)));

void pre() {
	for(int i = 2; i <= 20; i++) {
		vector<double> prob (400, 0);
		prob[0] = 1;
		memo[i][0] = prob;
		for(int j = 0; j < 20; j++) {
			vector<double> newProb (400, 0);
			for(int k = 0; k < prob.size(); k++) {
				if(prob[k] < 1e-8) continue;
				for(int l = 0; l < i; l++) {
					newProb[k + l] += prob[k] / i;
				}
			}
			prob = newProb;
			memo[i][j+1] = prob;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	pre();

	int T; cin >> T;

	for(int id = 1; id <= T; id++) {
		cout << "Case #" << id << ": ";

		int H, S; cin >> H >> S;

		double best = 0;
		while(S--) {
			string s; cin >> s;
			int times, sides, offset = 0;
			string timeStr, sideStr, offsetStr;

			int i = 0;
			while(s[i] >= '0' && s[i] <= '9') {
				timeStr.push_back(s[i]);
				i++;
			}
			i++;
			while(s[i] >= '0' && s[i] <= '9') {
				sideStr.push_back(s[i]);
				i++;
			}
			while(i < s.size()) {
				offsetStr.push_back(s[i]);
				i++;
			}

			times = atoi(timeStr.c_str());
			sides = atoi(sideStr.c_str());
			offset = offsetStr == "" ? 0 : atoi(offsetStr.c_str());

			int targetNum = H - offset - times;
			double odds = 0;
			if(targetNum <= 0) {
				best = 1;
				continue;
			}
			for(int i = targetNum; i < 400; i++) {
				if(memo[sides][times][i] < 1e-8) continue;
				odds += memo[sides][times][i];
			}
			best = max(odds, best);
		}

		cout << fixed << setprecision(6) << best << endl;
	}

	return 0;
}