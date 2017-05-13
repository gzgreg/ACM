#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;

	for(int id = 1; id <= T; id++) {
		int N, K; cin >> N >> K;
		double U; cin >> U;

		vector<double> probs;
		for(int i = 0; i < N; i++) {
			double curr; cin >> curr; probs.push_back(curr);
		}
		sort(probs.begin(), probs.end());
		for(int i = 0; i < N-1; i++) {
			if(U < 1e-6) break;
			if(probs[i] < probs[i+1]) {
				double totProb = 0;
				double diff = probs[i+1] - probs[i];
				for(int j = 0; j <= i; j++) {
					probs[j] += min(U/(i+1), diff);
					totProb +=  min(U/(i+1), diff);
				}
				U -= totProb;
			}
		}
		double cumProd = 1;
		for(int i = 0; i < N; i++) {
			probs[i] += U/N;
			cumProd *= probs[i];
		}

		cout << "Case #" << id << ": " << fixed << setprecision(10) << min(cumProd, 1.0) << endl;
	}
	
	return 0;
}