#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		int w, h, n; cin >> w >> h >> n;

		int p1 = 0, p2 = 0;
		vector<string> p1Map, p2Map;
		for(int i = 0; i < h; i++) {
			string curr; cin >> curr; p1Map.push_back(curr);
			p1 += count(curr.begin(), curr.end(), '#');
		}
		for(int i = 0; i < h; i++) {
			string curr; cin >> curr; p2Map.push_back(curr);
			p2 += count(curr.begin(), curr.end(), '#');
		}

		vector<pair<int, int>> orders;
		for(int i = 0; i < n; i++) {
			int x, y; cin >> x >> y; orders.push_back({x, y});
		}

		int i = 0;
		while(i < n) {
			//p1's turn
			bool hit = false;
			do {
				pair<int, int> order = orders[i];
				i++;
				if(p2Map[h-1-order.second][order.first] == '#') {
					p2Map[h-1-order.second][order.first] = '_';
					p2--;
					hit = true;
				} else {
					hit = false;
				}
			} while (hit && i < n && p2 > 0);
			if(i >= n) break;
			//p2's turn
			hit = false;
			do {
				pair<int, int> order = orders[i];
				i++;
				if(p1Map[h-1-order.second][order.first] == '#') {
					p1Map[h-1-order.second][order.first] = '_';
					p1--;
					hit = true;
				} else {
					hit = false;
				}
			} while (hit && i < n && p1 > 0);
			if(i >= n) break;
			if(p1 == 0 || p2 == 0) break;
		}

		if(p1 == 0 && p2 == 0) {
			cout << "draw" << endl;
		} else if (p1 == 0) {
			cout << "player two wins" << endl;
		} else if (p2 == 0) {
			cout << "player one wins" << endl;
		} else {
			cout << "draw" << endl;
		}

	}
	
	return 0;
}