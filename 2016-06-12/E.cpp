#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int res = 1;

	int n; cin >> n;
	map<pii, int> idxMap;
	vector<pii> cards;

	for(int i = 0; i < n; i++) {
		int ci, ri; cin >> ci >> ri;
		cards.push_back({ci, ri});
		idxMap[{ci, ri}] = i;
	}

	int nCost = cards[n-1].first;
	sort(cards.begin(), cards.end());
	vector<int> swaps;
	int i = 0;
	while(true) {
		int maxRes = 0;
		pii card;
		while(res >= cards[i].first && i < n) {
			if(cards[i].second > maxRes && cards[i].second > res) {
				maxRes = cards[i].second;
				card = cards[i];
			}
			i++;
		}
		if(maxRes != 0) {
			res = maxRes;
			swaps.push_back(idxMap[card] + 1);
		} else {
			break;
		}
		if(res >= nCost) {
			break;
		}
	}

	if(res < nCost) {
		cout << "No such luck" << endl;
	} else {
		if(swaps.size() == 0 || swaps[swaps.size() - 1] != n){
			swaps.push_back(n);
		}
		cout << swaps.size() << endl;
		for(int i = 0; i < swaps.size(); i++) {
			cout << swaps[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}