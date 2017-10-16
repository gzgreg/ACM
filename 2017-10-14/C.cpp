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

	string N, M; cin >> N >> M;

	int div = M.size() - 1;

	reverse(N.begin(), N.end());
	while(N.size() < div) {
		N.push_back('0');
	}

	reverse(N.begin(), N.end());

	N.insert(N.size() - div, ".");

	if(N[0] == '.') {
		N.insert(0, "0");
	}

	for(int i = N.size() - 1; i >= 0; i--) {
		if(N[i] != '0') {
			N.erase(i+1);
			break;
		}
	}

	if(N[N.size() - 1] == '.') {
		N.erase(N.size() - 1);
	}

	cout << N << endl;
	
	return 0;
}