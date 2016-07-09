#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	string s; getline(cin, s);
	vector<int> inv (s.size(), 0);
	vector<int> b;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'B'){
			b.push_back(i);
		}
	}
	for(int i = 1; i < s.size(); i++){
		if(s[i] == 'A'){
			for(int j = 0; j < b.size(); j++){
				if(i < b[j]) break;
				inv[i-b[j]]++;
			}
		}
	}

	for(int i = 1; i < inv.size(); i++){
		printf("%d\n", inv[i]);
	}
	
	return 0;
}