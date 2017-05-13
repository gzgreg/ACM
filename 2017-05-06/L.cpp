#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool sim(priority_queue<ll> c1,
		priority_queue<ll> c2) {
	while(!c1.empty() && !c2.empty()) {
		if(c2.top() > c1.top()) {
			c1.pop();
		} else if (c2.size() >= 2) {
			int i = c2.top(); c2.pop();
			int j = c2.top(); c2.pop();
			c2.push(i + j);
		}
		if(c1.empty()) {
			return false;
		}
		if(c1.top() > c2.top()) {
			c2.pop();
		} else if (c1.size() >= 2) {
			int i = c1.top(); c1.pop();
			int j = c1.top(); c1.pop();
			c1.push(i + j);
		}
		if(c2.empty()){
			return true;
		}
	}
	if(c1.empty()) {
		return false;
	} else {
		return true;
	}
}

int main(){
	ios::sync_with_stdio(0);
	
	int n; int id = 0;
	while(cin >> n) {
		id++;

		priority_queue<ll> c1I, c2;
		int M; cin >> M;
		for(int i = 0; i < n; i++) {
			ll curr; cin >> curr; c1I.push(curr);
		}
		for(int i = 0; i < M; i++) {
			ll curr; cin >> curr; c2.push(curr);
		}

		auto c1 = c1I;
		bool possible = false;
		if(n > 1) {
			ll start1, start2;
			start1 = c1.top(); c1.pop(); start2 = c1.top(); c1.pop();
			c1.push(start1 + start2);
			possible = possible || sim(c1, c2);
		}
		c1 = c1I;
		possible = possible || sim(c1I, c2);
		if(c1.top() <= c2.top()) {
		} else {
			c2.pop();
			possible = possible || sim(c1, c2);
		}
		
		
		cout << "Case " << id << ": " << (possible ? "Takeover Incorporated" : "Buyout Limited") << endl;
	}

	return 0;
}