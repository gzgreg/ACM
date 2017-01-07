#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define INF 1e8

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;

	int maxRat = INF;
	int minRat = -INF;

	while(n--) {
		int ci, di; cin >> ci >> di;
		//cout << maxRat << endl;
		if(minRat > maxRat) {
			cout << "Impossible" << endl;
			return 0;
		}

		if(di == 1) {
			if(maxRat < 1900) {
				cout << "Impossible" << endl;
				return 0;
			}
			if(minRat < 1900) {
				minRat = 1900;
			}
			if(minRat == -INF) {
				minRat = 1900 + ci;
			} else {
				minRat = minRat + ci;
			}
			if(maxRat != INF) {
				maxRat = maxRat + ci;
			}
		} else if (di == 2) {
			if(minRat >= 1900) {
				cout << "Impossible" << endl;
				return 0;
			}
			if(maxRat >= 1900) {
				maxRat = 1899;
			}
			if(maxRat == INF) {
				maxRat = 1899 + ci;
			} else {
				maxRat = maxRat + ci;
			}
			if(minRat != -INF) {
				minRat = minRat + ci;
			}
		}
	}

	if(maxRat == INF) {
		cout << "Infinity" << endl;
	} else {
		cout << maxRat << endl;
	}
	
	return 0;
}