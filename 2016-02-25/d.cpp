#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	long long n; cin >> n;

	vector<long long> ai;
	for(long long i = 0; i < n; i++){
		long long curr; cin >> curr;
		ai.push_back(curr);
	}

	sort(ai.begin(), ai.end());

	vector<long long> prob1 (5000, 0);

	for(long long i = 0; i < n-1; i++){
		for(long long j = i+1; j < n; j++){
			prob1[ai[j] - ai[i]]++;
		}
	}

	vector<long long> prob2(10000, 0);

	for(long long i = 0; i < 5000; i++){
		for(long long j = 0; j < 5000; j++){
			prob2[j + i] += prob1[i]*prob1[j];
		}
	}

	// for(long long i = 0; i < 20; i++){
	// 	cout << prob2[i] << endl;
	// }
	long long total = 0;
	for(long long i = 2; i < 5000; i++){
		if(prob1[i] == 0) continue;
		for(long long j = 1; j < i; j++){
			total += prob1[i]*prob2[j];
		}
	}
	long long divisor = n*(n-1) / 2;
	double probOut = (double) total / (divisor * divisor * divisor);

	cout << fixed << setprecision(10) << probOut << endl;
	return 0;
}