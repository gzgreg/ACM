#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	int M, N, K; cin >> M >> N >> K;

	for(int i = 0; i < M; i++) {
		string s; cin >> s;
		string newS;
		for(char curr : s) {
			for(int i = 0; i < K; i++) {
				newS.push_back(curr);
			}
		}
		for(int i = 0; i < K; i++) {
			cout << newS << endl;
		}
	}
	return 0;
}