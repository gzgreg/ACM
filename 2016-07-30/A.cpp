#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	string a, b; cin >> a >> b;

	string out = "";

	for(int i = 0; i < a.length(); i++) {
		int ai = a[i] - '0';
		int bi = b[i] - '0';
		int outi = abs(ai - bi);
		if(outi != 0 || out.length() != 0) {
			char val = '0' + outi;
			out.append(1, val);
		}
	}

	if(out.length() == 0) out = "0";

	cout << out << endl;
	
	return 0;
}