#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n;
	while(cin >> n){
		int m; cin >> m;
		vector<pair<pair<int, int>, int>> groups;
		set<int> crit;
		for(int i = 0; i < n; i++){
			int q, x, y; cin >> q >> x >> y;
			groups.push_back({{x, y}, q});
			crit.insert(y);
		}
		int optPrice;
		long long maxProfit = 0;
		for(auto it = crit.begin(); it != crit.end(); it++){
			int currPrice = *it;
			long long currProfit = 0;
			for(int i = 0; i < n; i++){
				if(currPrice >= groups[i].first.first && currPrice <= groups[i].first.second){
					currProfit += (long long) groups[i].second * (currPrice - m);
				}
			}
			if(currProfit > maxProfit){
				maxProfit = currProfit;
				optPrice = currPrice;
			}
		}
		cout << optPrice << endl;
	}
	
	return 0;
}