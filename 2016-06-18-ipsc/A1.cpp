#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		string s = "";
		vector<string> strings;
		for(int i = 0; i < 10; i++) {
			string curr; cin >> curr;
			strings.push_back(curr);
		}
		int found1, found2;
		string foundstr;
		vector<int> len = {1, 2, 3, 4, 3, 2, 1};
		for(int i = 0; i < 10; i++) {
			for(int j = i+1; j < 10; j++) {
				string s1 = strings[i];
				string s2 = strings[j];
				for(int k = 0; k < 7; k++) {
					int s1i1 = max(3 - k, 0);
					int s2i1 = max(k - 3, 0);
					int lenX = len[k];
					if(s1.substr(s1i1, lenX) == s2.substr(s2i1, lenX)) {
						found1 = i;
						found2 = j;
						foundstr = (k >= 3) ? s2 + s1.substr(s1i1+lenX, 100) : s1 + s2.substr(s2i1+lenX, 100);
						break;
					}
				}
			}
		}
		s = s + foundstr;
		for(int i = 0; i < 10; i++) {
			if(i != found1 && i != found2) {
				s += strings[i];
			}
		}
		while(s.size() < 39) s += "A";
		cout << s << endl;
	}
	
	
	return 0;
}