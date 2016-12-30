#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	int N; cin >> N;

	vector<int> maxNum (26, 0);

	for(int i = 0; i < N; i++) {
		string s1, s2; cin >> s1 >> s2;

		vector<int> num1 (26, 0), num2(26, 0);
		for(char curr : s1) {
			num1[curr - 'a']++;
		}
		for(char curr : s2) {
			num2[curr - 'a']++;
		}
		for(int i = 0; i < 26; i++) {
			maxNum[i] += max(num1[i], num2[i]);
		}
	}

	for(int i = 0; i < 26; i++) {
		cout << maxNum[i] << endl;
	}

	return 0;
}