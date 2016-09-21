#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	vector<vector<int>> idToConfig;

	map<vector<int>, int> configToId;

	for(int a = 0; a <= 15; a++) {
		for(int b = 0; b <= 15; b++) {
			for(int c = 0; c <= 15; c++) {
				for(int d = 0; d <= 15; d++) {
					for(int e = 0; e <= 15; e++) {
						for(int f = 0; f <= 15; f++) {
							if(a + b + c + d + e + f == 15) {
								idToConfig.push_back({a, b, c, d, e, f});
								configToId[{a, b, c, d, e, f}] = idToConfig.size() - 1;
							}
						}
					}
				}
			}
		}
	}

	char s; cin >> s;
	int idx = 1;
	while(s != 'e') {
		cout << "Case " << idx << ": ";
		if(s == 'm') {
			vector<int> nums;
			for(int i = 0; i < 6; i++) {
				int a; cin >> a; nums.push_back(a);
			}
			cout << configToId[nums] << endl;
		} else if (s == 'u') {
			int id; cin >> id;

			for(int num : idToConfig[id]) {
				cout << num << " ";
			}
			cout << endl;
		}
		idx++;
		cin >> s;
	}
	
	return 0;
}