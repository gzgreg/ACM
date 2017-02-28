#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	string s; cin >> s;
	int minLength = s.size();
	for(int i = 0; i < s.size() - 1; i++) {
		string sub; sub.push_back(s[i]);
		for(int j = i + 1; j < s.size(); j++) {
			sub.push_back(s[j]);
			int numMatches = 0;
			for(int k = 0; k < s.size() - sub.size() + 1; k++) {
				int found = true;
				for(int l = k; l < sub.size() + k; l++) {
					if(s[l] != sub[l-k]) {
						found = false;
						break;
					}
				}
				numMatches += found;
				if(found) {
					k += sub.size() - 1;
				} 
			}

			int currLength = s.size();
			currLength += sub.size();
			currLength -= numMatches * (sub.size() - 1);
			minLength = min(currLength, minLength);
		}
	}
	cout << minLength << endl;
	
	return 0;
}