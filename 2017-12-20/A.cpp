#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

vector<int> addMonths(vector<int> start, int m) {
	int y = m / 12;
	m -= 12 * y;
	start[0] += y;
	start[1] += m;
	if(start[1] >= 12) {
		start[1] %= 12;
		start[0]++;
	}
	if(start[2] > days[start[1]] - 1) {
		if(start[1] == 1 && start[2] == 28
			&& (start[0] % 400 == 0 || (start[0] % 100 != 0 && start[0] % 4 == 0))) {

		} else {
			start[2] = 0;
			start[1]++;
			if(start[1] == 12) {
				start[1] = 0;
				start[0]++;
			}
		}
	}
	return start;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int M, N, K; cin >> M >> N >> K;

	int DD, MM, YY; char junk;
	cin >> DD >> junk >> MM >> junk >> YY;
	int retMonths = 60*12;
	vector<vector<int>> changeDates;
	changeDates.push_back({2012, 0, 0});
	for(int i = 0; i < K; i++) {
		changeDates.push_back(addMonths(changeDates.back(), N));
	}
	for(int i = 0; i < 10000; i++) {
		vector<int> curDate = addMonths({YY, MM - 1, DD - 1}, i);
		for(int j = 0; j < changeDates.size(); j++) {
			if(i >= retMonths + (M * j) && curDate < changeDates[j]) {
				cout << setfill('0') << setw(2);
				cout << curDate[2] + 1 << ".";
				cout << setfill('0') << setw(2);
				cout << curDate[1] + 1 << "." << curDate[0] << endl;
				return 0;
			}
		}
		if(i >= retMonths + (M * K)) {
			cout << setfill('0') << setw(2);
			cout << curDate[2] + 1 << ".";
			cout << setfill('0') << setw(2);
			cout << curDate[1] + 1 << "." << curDate[0] << endl;
			return 0;
		}
	}
	
	return 0;
}