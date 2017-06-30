#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int n; cin >> n;

	stack<int> top;
	set<int> nums;
	int numRemoves = 0;
	int ans = 0;
	for(int i = 0; i < 2*n; i++) {
		string cmd; cin >> cmd;
		if(cmd[0] == 'a') {
			int add; cin >> add;
			top.push(add);
		} else {
			if(top.empty()) {
				nums.erase(numRemoves + 1);
			} else {
				if(top.top() == numRemoves + 1) {
					top.pop();
				} else {
					ans++;
					while(!top.empty()) {
						nums.insert(top.top());
						top.pop();
					}
					nums.erase(numRemoves + 1);
				}
			}
			
			numRemoves++;
		}
	}

	cout << ans << endl;
	
	return 0;
}