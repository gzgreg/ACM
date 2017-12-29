#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string s; cin >> s;
	string ans = "abcdefghijklmnop";

	char cmd;
	map<string, int> prev;
	for(int i = 1; i <= 1000000000; i++) {
		stringstream str(s);
		while(str >> cmd) {
			if(cmd == 's') {
				int s; str >> s;
				rotate(ans.begin(), ans.begin() + (ans.size() - s), ans.end());
			} else if (cmd == 'x') {
				int a, b; str >> a >> cmd >> b;
				swap(ans[a],ans[b]);
			} else if (cmd == 'p') {
				char a, b; str >> a >> cmd >> b;
				int ai, bi;
				for(int i = 0; i < ans.size(); i++) {
					if(ans[i] == a) {
						ai = i;
					}
					if (ans[i] == b) {
						bi = i;
					}
				}
				swap(ans[ai], ans[bi]);
			}
			str >> cmd;
		}
		if(prev.count(ans)) {
			if((1000000000 - i) % (i - prev[ans]) == 0) {
				cout << ans << endl;
				break;
			}
		}
		prev[ans] = i;
	}

	cout << ans << endl;

	return 0;
}