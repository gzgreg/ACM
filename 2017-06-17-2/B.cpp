#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	vector<int> starts;
	for(int i = 0; i < s.size() - 8; i++) {
		string curr = s.substr(i, 9);
		if(s.size() <= 8) break;
		if(curr == "happiness") {
			starts.push_back(i + 1);
		}
	}

	if(starts.size() > 2) {
		cout << "NO" << endl;
	} else if (starts.size() == 2) {
		cout << "YES" << endl;
		cout << starts[0] << " " << starts[1] + 1 << endl;
	} else if (starts.size() == 1) {
		cout << "YES" << endl;
		cout << starts[0] << " " << starts[0] + 1 << endl;
	} else {
		int i = 1;
		bool good = true;
		do {
			good = true;
			char tmp = s[i];
			s[i] = s[0];
			s[0] = tmp;
			for(int i = 0; i < s.size() - 8; i++) {
				string curr = s.substr(i, 9);
				if(s.size() <= 8) break;
				if(curr == "happiness") {
					good = false;
				}
			}
			if(!good) {
				char tmp = s[i];
				s[i] = s[0];
				s[0] = tmp;
				i++;
			}
		} while(!good);

		cout << "YES" << endl << "1 " << i + 1 << endl;
	}
	
	return 0;
}