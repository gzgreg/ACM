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

	int white = 0, black = 0;
	for(int i = 0; i < N; i++) {
		string a, b; cin >> a >> b;
		if(b == "soft") white++;
		else black++;
	}

	for(int i = 0; i < 20; i++) {
		int numWhites = (i*i+1) / 2;
		int numBlacks = (i*i) / 2;
		if(numWhites >= white && numBlacks >= black) {
			cout << i << endl;
			return 0;
		}
		if(numWhites >= black && numBlacks >= white) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
}