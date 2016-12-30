#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	string start; cin >> start;
	int N = start.size();
	vector<string> grid;
	grid.push_back(start);

	for(int i = 1; i < 400000; i++) {
		string lastRow = grid[i-1];
		string out;
		for(int j = 0; j < N; j++) {
			string prev;
			prev.push_back(j == 0 ? '.' : lastRow[j-1]);
			prev.push_back(lastRow[j]);
			prev.push_back(j == N-1 ? '.' : lastRow[j+1]);

			if(prev == "^^."
				|| prev == ".^^"
				|| prev == "^.."
				|| prev == "..^") {
				out.push_back('^');
			} else {
				out.push_back('.');
			}
		}
		grid.push_back(out);
	}
	int total = 0;
	for(int i = 0; i < 400000; i++) {
		for(int j = 0; j < N; j++) {
			total += grid[i][j] == '.';
		}
	}
	cout << total << endl;
	return 0;
}