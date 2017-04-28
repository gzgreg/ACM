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
		cout << "Case #" << id << ": ";

		int D, N; cin >> D >> N;

		vector<pii> horses;
		for(int i = 0; i < N; i++) {
			int Ki, Si; cin >> Ki >> Si;
			horses.push_back({Ki, Si});
		}

		double maxArrival = 0;

		for(pii horse : horses) {
			double currArrival = (double) (D - horse.first) / horse.second;

			maxArrival = max(maxArrival, currArrival);
		}

		cout << fixed << setprecision(10) << D / maxArrival << endl;
	}
	
	return 0;
}