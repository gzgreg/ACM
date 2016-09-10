#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	map<long long, vector<int>> seen;

	int N, M; cin >> N >> M;

	vector<int> list1;
	vector<int> list2;
	for(int i = 0; i < N; i++) {
		int a; cin >> a; list1.push_back(a);
	}
	for(int i = 0; i < M; i++) {
		int b; cin >> b; list2.push_back(b);
	}

	for(int i = 1; i < pow(2, N); i++) {
		double ans = 1;
		bitset<16> curr = bitset<16>(i);
		vector<int> vals;
		for(int j = 0; j < N; j++) {
			if(curr[j]) {
				ans += log10(list1[j]);
				vals.push_back(list1[j]);
			}
		}
		seen[(long long) (ans * 1e13)] = vals;
	}

	for(int i = 1; i < pow(2, M); i++) {
		double ans = 1;
		bitset<16> curr = bitset<16>(i);
		vector<int> vals;
		for(int j = 0; j < M; j++) {
			if(curr[j]) {
				ans += log10(list2[j]);
				vals.push_back(list2[j]);
			}
		}
		if(seen.count((long long) (ans * 1e13))) {
			cout << "Y" << endl;
			cout << seen[(long long) (ans * 1e13)].size() << " ";
			cout << vals.size();
			cout << endl;
			for(int val : seen[(long long) (ans * 1e13)]) {
				cout << val << " ";
			}
			cout << endl;
			for(int val : vals) {
				cout << val << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "N" << endl;
	return 0;
}