#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll findDist(string a, string b, int idx, bool revA, bool revB) {
	char aChar = '0' + (a[idx] == '1');
	if(revA) aChar = '0' + (aChar == '0');

	char bChar = '0' + (b[idx] == '1');
	if(revB) bChar = '0' + (bChar == '0');

	// cout << a << " " << b << " " << idx << " " << ((aChar != bChar) * (1 << (a.size() - idx - 1))*(aChar > bChar ? -1 : 1)) << endl;
	if(idx == a.size() - 1) {
		return (aChar != bChar)*(aChar > bChar ? -1 : 1);
	}
	
	return (aChar != bChar) * (1LL << (a.size() - idx - 1)) * (aChar > bChar ? -1 : 1)
		+ findDist(a, b, idx + 1, a[idx] == '1' ? !revA : revA, b[idx] == '1' ? !revB : revB);
}

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	string a, b; cin >> a >> b;

	cout << findDist(a, b, 0, 0, 0) - 1 << endl;
	
	return 0;
}