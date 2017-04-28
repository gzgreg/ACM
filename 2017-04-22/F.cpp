#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;

	vector<int> vals (2001, 0);

	for(int i = 0; i < N; i++) {
		int curr; cin >> curr; vals[curr]++;
	}
	vector<int> lengths;
	for(int i = 2; i <= 4000; i++) {
		int length = 0;
		for(int j = 1; j <= i / 2; j++) {
			if(2*j == i) {
				length += vals[j] / 2;
			} else {
				if(i-j <= 2000) length += min(vals[j], vals[i - j]);
			}
		}
		if(length != 0) {
			lengths.push_back(length);
		}

	}

	sort(lengths.begin(), lengths.end());
	reverse(lengths.begin(), lengths.end());
	for(int i = 0; i < lengths.size(); i++) {
		if(lengths[i] != lengths[0]) {
			cout << lengths[0] << " " << i << endl;
			return 0;
		}
	}
	cout << lengths[0] << " " << lengths.size() << endl;
	
	return 0;
}