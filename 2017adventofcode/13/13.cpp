#include <bits/stdc++.h>

using namespace std;

int main(){	
	string s;
	int ans = 0;

	map<int, int> vals;
	while(getline(cin, s)) {
		stringstream str(s);

		int tmp; char junk; int tmp2;
		str >> tmp;	str >> junk; str >> tmp2;
		vals[tmp] = tmp2;
	}

	// part 1
	for(auto cur : vals) {
		if(cur.first % (2*cur.second - 2) == 0) {
			ans += cur.first*cur.second;
		}
	}
	cout << ans << endl;

	// part 2
	int t = 0;
	while(true) {
		bool good = true;
		for(auto cur : vals) {
			if((cur.first + t) % (2*cur.second - 2) == 0) {
				good = false;
				break;
			}
		}
		if(good) {
			cout << t << endl;
			return 0;
		}
		t++;
	}
}