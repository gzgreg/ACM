#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	int n; cin >> n;
	vector<pii> exams;
	for(int i = 0; i < n; i++) {
		int si; cin >> si; exams.push_back({si, i+1});
	}
	sort(exams.begin(), exams.end());
	reverse(exams.begin(), exams.end());
	int total = 0;
	for(int i = 1; i < n; i++) {
		total += exams[i].first;
	}
	if(total < exams[0].first) {
		cout << "impossible" << endl;
	} else {
		for(pii curr : exams) {
			cout << curr.second << " ";
		}
		cout << endl;
	}
	return 0;
}