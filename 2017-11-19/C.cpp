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

	int m; cin >> m;
	vector<int> gcds;
	for(int i = 0; i < m; i++) {
		int cur; cin >> cur; gcds.push_back(cur);
	}

	for(int i = 1; i < m; i++) {
		if(gcds[i] % gcds[0] != 0) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> seq;
	seq.push_back(gcds[0]);
	for(int i = 1; i < m; i++) {
		seq.push_back(gcds[i]);
		seq.push_back(gcds[0]);
	}

	cout << seq.size() << endl;
	for(int i = 0; i < seq.size(); i++) {
		cout << seq[i] << " ";
	}
	cout << endl;
	
	return 0;
}