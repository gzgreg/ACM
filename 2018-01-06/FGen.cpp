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
	
	cout << 1000 << " " << 499500 << endl;

	vector<int> type;
	for(int i = 0; i < 1000; i++) {
		type.push_back(rand() % 3);
	}
	for(int i = 0; i < 1000; i++) {
		for(int j = i+1; j < 1000; j++) {
			cout << i+1;
			if(type[i] < type[j]) {
				cout << "<";
			} else if (type[i] == type[j]) {
				cout << "=";
			} else cout << ">";
			cout << j+1 << endl;
		}
	}

	return 0;
}