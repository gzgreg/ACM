#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	string a, b; cin >> a >> b;

	string end; cin >> end;

	for(int i = 0; i < end.size(); i++) {
		for(int j = 0; j < a.size(); j++) {
			if(end[i] == a[j]) {
				end[i] = b[j];
				break;
			} else if (end[i] - 'A' == a[j] - 'a') {
				end[i] = 'A' + b[j] - 'a';
				break;
			}
		}
	}

	cout << end << endl;
	
	return 0;
}