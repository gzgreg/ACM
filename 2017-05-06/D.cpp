#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll memo[101];

ll fib(int i) {
	if(memo[i] != -1) {
		return memo[i];
	}
	if(i == 0 || i == 1) return 1;
	if(i < 0) return 0;
	return memo[i] = fib(i-1) + fib(i-2);
}

int main(){
	ios::sync_with_stdio(0);
	
	int n; int id = 0;
	memset(memo, -1, sizeof memo);
	fib(100);
	while(cin >> n) {
		id++;
		string p; cin >> p;
		int numTransforms = 0;
		set<string> s; s.insert(p);
		ll ans = 0;
		while(!s.empty() && numTransforms < n) {
			set<string> newSet;
			cout << "==============================" << endl;
			for(string curr : s) {
				if(curr[curr.size() - 1] == '0'
					&& curr[curr.size() - 2] == '0') {
					continue;
				}
				cout << "================" << endl;
				cout << curr << endl;
				string newP;
				if(curr.size() == 1) {
					if(curr == "0") {
						ans += fib(n - numTransforms - 2);
					} else {
						ans += fib(n - numTransforms - 1);
					}
					cout << ans << " " << n-numTransforms <<  endl;
					continue;
				}

				if(curr[0] == '0') {
					curr = "1" + curr;
				}
				for(int i = 0; i < curr.size(); i++) {
					if(curr[i] == '1') {
						if(i < curr.size() - 1 && curr[i+1] == '0') {
							newP.push_back('1');
							i++;
						} else {
							newP.push_back('0');
						}
					}
				}
				// cout << newP << endl;
				if(curr[curr.size() - 1] == '1') {
					newSet.insert(newP);
					newP[newP.size() - 1] = '1';
					newSet.insert(newP);
				} else {
					newSet.insert(newP);
				}
				
			}
			s = newSet;
			numTransforms++;
			
		}
		
		
		cout << "Case " << id << ": " << ans << endl;
	}

	return 0;
}