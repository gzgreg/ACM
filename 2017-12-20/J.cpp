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

	int N; cin >> N;
	vector<pii> feedback;
	for(int i = 0; i < N; i++) {
		int vi, ci; cin >> vi >> ci;
		feedback.push_back({vi, 2-ci});
	}

	sort(feedback.begin(), feedback.end());
	vector<int> numTwos = {0}, numOnes= {0}, numZeros= {0};
	for(int i = 0; i < N; i++) {
		numTwos.push_back(numTwos.back());
		numOnes.push_back(numOnes.back());
		numZeros.push_back(numZeros.back());
		if(feedback[i].second == 2) {
			numZeros.back()++;
		} else if (feedback[i].second == 1) {
			numOnes.back()++;
		} else {
			numTwos.back()++;
		}
	}

	vector<int> error;
	for(int i = 0; i < N+1; i++) {
		int curError = 0;
		curError += numTwos[i];
		curError += numOnes.back() - numOnes[i];
		error.push_back(curError);
	}
	vector<int> bestError(N+1, 1e9);
	vector<int> bestErrorId(N+1);
	bestError[N] = error[N];
	bestErrorId[N] = N;

	for(int i = N-1; i >= 0; i--) {
		if(error[i] <= bestError[i+1]) {
			bestError[i] = error[i];
			bestErrorId[i] = i;
		} else {
			bestError[i] = bestError[i+1];
			bestErrorId[i] = bestErrorId[i+1];
		}
	}

	int bestTotalErrorId;
	int bestTotalError = 1e9;
	for(int i = 0; i <= N; i++) {
		int curError = 0;
		curError += numOnes[i];
		curError += numZeros.back() - numZeros[i];

		curError += bestError[i];
		if(curError < bestTotalError) {
			bestTotalErrorId = i;
			bestTotalError = curError;
		} else if (curError == bestTotalError) {
			int A1, B1, A2, B2;
			if(i == 0) {
				A1 = 0;
			} else {
				A1 = feedback[i-1].first;
			}
			if(bestErrorId[i] == 0) {
				B1 = 0;
			} else {
				B1 = feedback[bestErrorId[i] - 1].first;
			}

			if(bestTotalErrorId == 0) {
				A2 = 0;
			} else {
				A2 = feedback[bestTotalErrorId-1].first;
			}
			if(bestErrorId[bestTotalErrorId] == 0) {
				B2 = 0;
			} else {
				B2 = feedback[bestErrorId[bestTotalErrorId] - 1].first;
			}
			if(A1 + B1 < A2 + B2) {
				bestTotalErrorId = i;
				bestTotalError = curError;
			}
		}
	}

	int A2, B2;
	if(bestTotalErrorId == 0) {
		A2 = 0;
	} else {
		A2 = feedback[bestTotalErrorId-1].first;
	}
	if(bestErrorId[bestTotalErrorId] == 0) {
		B2 = 0;
	} else {
		B2 = feedback[bestErrorId[bestTotalErrorId] - 1].first;
	}

	cout << A2 << " " << B2 << endl;
	
	return 0;
}