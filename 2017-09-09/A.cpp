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

	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		bool pizza; cin >> pizza;

		if(pizza) {
			for(int i = 0; i < 20; i++) {
				if(n <= (1 << i)) {
					cout << i << endl;
					for(int j = 0; j < i; j++) {
						vector<int> t1, t2;
						for(int k = 0; k < n; k++) {
							if(k & (1 << j)) {
								t1.push_back(k);
							} else {
								t2.push_back(k);
							}
						}
						cout << t1.size() << " ";
						for(int i : t1) {
							cout << i+1 << " ";
						}
						cout << endl << t2.size() << " ";
						for(int i : t2) {
							cout << i+1 << " ";
						}
						cout << endl;
					}
					break;
				}
			}
		} else {
			queue<pair<vi, vi>> vals;

			vector<int> start1, start2;
			for(int i = 0; i < n/2; i++) {
				start1.push_back(i+1);
			}
			for(int i = n/2; i < n; i++) {
				start2.push_back(i+1);
			}

			vals.push({start1, start2});
			int numDays = 0;
			vector<pair<vi, vi>> ans;
			while(!vals.empty()) {
				pair<vi, vi> cur = vals.front(); vals.pop();
				numDays++;
				ans.push_back(cur);

				if(cur.first.size() > 1) {
					vi v1,v2;
					for(int i = 0; i < cur.first.size() / 2; i++) {
						v1.push_back(cur.first[i]);
					}
					for(int i = cur.first.size() / 2; i < cur.first.size(); i++) {
						v2.push_back(cur.first[i]);
					}
					vals.push({v1, v2});
				}
				if(cur.second.size() > 1) {
					vi v1,v2;
					for(int i = 0; i < cur.second.size() / 2; i++) {
						v1.push_back(cur.second[i]);
					}
					for(int i = cur.second.size() / 2; i < cur.second.size(); i++) {
						v2.push_back(cur.second[i]);
					}
					vals.push({v1, v2});
				}
			}
			cout << numDays << endl;
			for(auto i : ans) {
				cout << i.first.size() << " ";
				for(int j : i.first) {
					cout << j << " ";
				}
				cout << endl << i.second.size() << " ";
				for(int j : i.second) {
					cout << j << " ";
				}
				cout << endl;
			}
		}
	}
	
	return 0;
}