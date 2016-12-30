#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	

	string s;
	int totSector = 0;
	while(cin >> s) {
		map<char, int> count;
		vector<char> checksum;
		bool inChecksum = false;
		string sector = "";
		string letters;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] >= 'a' && s[i] <= 'z') {
				if(inChecksum) {
					checksum.push_back(s[i]);
				} else {
					count[s[i]]++;
					letters.push_back(s[i]);
				}
			} else if(s[i] == '[') {
				inChecksum = true;
			} else if(s[i] >= '0' && s[i] <= '9') {
				sector.push_back(s[i]);
			}
		}

		int sectorInt = atoi(sector.c_str());
		vector<pair<int, char>> a;
		for(pair<char, int> curr : count) {
			a.push_back({-curr.second, curr.first});
		}
		sort(a.begin(), a.end());

		bool valid = true;
		for(int i = 0; i < 5; i++) {
			if(a[i].second != checksum[i]) {
				valid = false;
				break;
			}
		}
		if(valid){
			totSector += sectorInt;
			for(int i = 0; i < letters.size(); i++) {
				int num = letters[i] - 'a';
				num += sectorInt % 26;
				num = num % 26;
				letters[i] = 'a' + num;
			}
			cout << letters <<  " " << sectorInt << endl;
		}
	}
	cout << totSector << endl;
	
	return 0;
}