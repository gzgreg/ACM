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

		int N, R; cin >> N >> R;

		vector<pair<pii, int>> squares;
		vector<pii> zombies;
		set<int> x;
		set<int> y;
		for(int i = 0; i < N; i++) {
			int xi, yi; cin >> xi >> yi; x.insert(xi); y.insert(yi);
			zombies.push_back({xi, yi});
		}

		for(int i : x) {
			for(int j : y) {
				int total = 0;
				for(pii zombie : zombies) {
					if(zombie.first >= i && zombie.first <= i + R
						&& zombie.second >= j && zombie.second <= j + R) {
						total++;
					}
				}
				squares.push_back({{i, j}, total});
			}
		}

		int maxAns = 0;
		
		for(int i = 0; i < squares.size(); i++) {
			maxAns = max(maxAns, squares[i].second);
			for(int j = i + 1; j < squares.size(); j++) {
				int currAns = squares[i].second + squares[j].second;

				int xMin = squares[j].first.first;
				int xMax = squares[i].first.first + R;
				int yMin, yMax;
				if(squares[i].first.second < squares[j].first.second) {
					yMin = squares[j].first.second;
					yMax = squares[i].first.second + R;
				} else {
					yMin = squares[i].first.second;
					yMax = squares[j].first.second + R;
				}
				if(xMax >= xMin && yMax >= yMin) {
					for(pii zombie : zombies) {
						if(zombie.first >= xMin && zombie.first <= xMax
							&& zombie.second >= yMin && zombie.second <= yMax) {
							currAns--;
						}
					}
				}
				maxAns = max(maxAns, currAns);
			}
		}
		cout << maxAns << endl;
	}
	
	return 0;
}