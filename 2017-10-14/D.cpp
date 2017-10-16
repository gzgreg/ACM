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

	vector<vector<int>> p(2, vector<int>(2*N));

	for(int i = 0; i < 2*N; i++) {
		cin >> p[0][i];
	}
	for(int i = 0; i < 2*N; i++) {
		cin >> p[1][i];
	}

	set<int> seen;
	set<int> knownPairs;

	vector<int> c(2);
	vector<int> idx(2);

	bool curTurn = 0;

	while(idx[0] < 2*N && idx[1] < 2*N) {
		int numCards = 0;
		if(knownPairs.size() != 0) {
			c[curTurn] += knownPairs.size();
			knownPairs.clear();
		}
		vector<int> cards;
		//cout << idx[0] << " " << idx[1] << endl;

		while(numCards < 2 && idx[curTurn] < 2*N) {
			int curCard = p[curTurn][idx[curTurn]];
			if(seen.count(curCard)) {
				idx[curTurn]++;
				continue;
			}
			//cout << curTurn << " " << curCard << endl;
			seen.insert(curCard);
			cards.push_back(curCard);
			numCards++;
			idx[curTurn]++;
			if(curCard % 2) {
				if(seen.count(curCard - 1)) {
					break;
				}
			} else {
				if(seen.count(curCard + 1)) {
					break;
				}
			}
		}
		if(cards.size() == 1) {
			c[curTurn]++;
			continue;
		} else if (cards.size() == 0) {
			curTurn = !curTurn;
			break;
		}
		if(cards[0] / 2 == cards[1] / 2) {
			c[curTurn]++;
		} else {
			for(int i = 0; i < 2; i++) {
				if(cards[i] % 2) {
					if(seen.count(cards[i] - 1)) {
						knownPairs.insert(cards[i] / 2);
					}
				} else {
					if(seen.count(cards[i] + 1)) {
						knownPairs.insert(cards[i] / 2);
					}
				}
			}
			curTurn = !curTurn;
		}
	}
	//cout << c[0] << " " << c[1] << endl;
	if(c[0] > c[1]) {
		cout << 0 << endl;
	} else if (c[0] < c[1]) {
		cout << 1 << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}