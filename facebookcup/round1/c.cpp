#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	long long T; cin >> T;
	for(long long i = 1; i <= T; i++){
		long long N, A, B; cin >> N >> A >> B;
		vector<long long> Ci (N, 0);
		vector<long long> cumsum (N, 0);
		Ci.push_back(0); cumsum.push_back(0);
		for(long long j = 1; j <= N; j++){
			long long curr; cin >> curr;
			Ci[j] = curr;
			cumsum[j] = cumsum[j-1] + curr;
		}

		for(long long j = 1; j < N+1; j++){
			cumsum.push_back(cumsum[j]+cumsum[N]);
		}
		long long yCost = cumsum[N];
		
		long long diff = B - A;
		double expY = 0;

		for(long long j = 1; j < Ci.size(); j++){
			expY += Ci[j]/ 2.0 * Ci[j];
		}
		long long numContained = (B - A) / yCost;
		long long shift = A / yCost;
		double expTot = expY * numContained;

		A -= yCost * shift;
		B -= yCost * shift + yCost * numContained;
		long long start = 0;
		while(cumsum[start] < A){
			start++;
		}
		double expPart;
		if(cumsum[start] >= B){
			expPart = ((B + A) / 2.0 - cumsum[start - 1]) * (B - A);
		} else {
			expPart = (cumsum[start] + A) / 2.0*(cumsum[start] - A);
			while(cumsum[start+1] < B){
				start++;
				expPart += (cumsum[start]-cumsum[start-1])/2.0*(cumsum[start]-cumsum[start-1]);
			}
			expPart += (B-cumsum[start]) / 2.0*(B-cumsum[start]);
		}

		cout << "Case #" << i << ": " << fixed << setprecision(15) << (expTot + expPart) / diff << endl;
	}

	return 0;
}