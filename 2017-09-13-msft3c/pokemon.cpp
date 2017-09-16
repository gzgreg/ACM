#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, T, K;
int origTimeLeft = 0;

vector<complex<double>> coords;

double memo[100005][505];

double dp(int curStop, int timeLeft) {
	if(curStop*K + origTimeLeft - timeLeft > coords.size()) {
		return 0;
	} else if (memo[curStop][timeLeft] != -1) {
		return memo[curStop][timeLeft];
	}
	double best = 0;
	for(int i = 0; i <= min(timeLeft, K); i++) {
		int timeWaited = timeLeft - origTimeLeft - i;
		best = max(best, dp(curStop + 1, timeLeft - i) 
			+ abs(coords[(curStop)*K + timeLeft - origTimeLeft - i] 
				- coords[max((curStop-1)*K + timeLeft - origTimeLeft, 0)]));
	}
	return memo[curStop][timeLeft] = best;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> T >> K;
	for(int i = 0; i < 100005; i++) {
		for(int j = 0; j < 505; j++) {
			memo[i][j] = -1;
		}
	}
	vector<complex<double>> locs;
	for(int i = 0; i < N; i++) {
		int xi, yi; cin >> xi >> yi;
		locs.emplace_back(xi, yi);
	}

	for(int i = 0; i < locs.size() - 1; i++) {
		complex<double> vec = locs[i+1] - locs[i];
		int dist = abs(vec);
		complex<double> cur = vec / (double) dist;
		for(int j = 0; j < dist - 0.01; j++) {
			coords.emplace_back(((double) j * cur + locs[i]).real(), ((double)j * cur + locs[i]).imag());
		}
	}

	coords.emplace_back(locs[locs.size() - 1]);
	cout << coords.size() << endl;
	origTimeLeft = T - coords.size() + 1;

	cout << setprecision(2) << fixed << dp(1, origTimeLeft) << endl;

	return 0;
}