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
	
	int tot = 0, num = 0;

	int cur; string s = ""; char c;
	while(cin >> c) {
		if(c != ',') {
			s.push_back(c);
		} else {
			cur = stoi(s);
			tot += cur;
			num++;
			s = "";
		}
	}
				cur = stoi(s);
			tot += cur;
			num++;
			s = "";

	cout << (int) ((double) tot / num + 0.5) << endl;
	return 0;
}