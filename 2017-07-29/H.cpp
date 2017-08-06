#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;

		priority_queue<pii, vector<pii>> buy;
		priority_queue<pii, vector<pii>, greater<pii>> sell;

		int lastSell = -1;
		for(int i = 0; i < n; i++) {
			string t; cin >> t;
			int x; cin >> x;
			string junk; cin >> junk >> junk;
			int y; cin >> y;

			if(t[0] == 'b') {
				buy.push({y, x});
			} else {
				sell.push({y, x});
			}

			while(!buy.empty() && !sell.empty()
					&& buy.top().first >= sell.top().first) {
				lastSell = sell.top().first;
				if(buy.top().second > sell.top().second) {
					auto cur = buy.top(); buy.pop();
					cur.second -= sell.top().second;
					buy.push(cur);
					sell.pop();
				} else if (buy.top().second < sell.top().second) {
					auto cur = sell.top(); sell.pop();
					cur.second -= buy.top().second;
					sell.push(cur);
					buy.pop();
				} else {
					sell.pop();
					buy.pop();
				}
			}

			if(sell.empty()) {
				cout << "- ";
			} else {
				cout << sell.top().first << " ";
			}

			if(buy.empty()) {
				cout << "- ";
			} else {
				cout << buy.top().first << " ";
			}

			if(lastSell == -1) {
				cout << "-" << endl;
			} else {
				cout << lastSell << endl;
			}
		}
	
	}

	return 0;
}