#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
pii rowNodes[6250000], colNodes[6250000];
pii nodeIds[6250000];

int main(){	
	int n, m; scanf("%d", &n); scanf("%d", &m);

	vector<string> grid;
	for(int i = 0; i < n; i++) {
		char s[m]; scanf("%s ", s); grid.push_back(s);
	}

	int q; scanf("%d", &q);

	int rowI = 0, colI = 0;
	for(int i = 0; i < n; i++) {
		bool inNode = false;
		int nodeStart = 0;
		for(int j = 0; j < m; j++) {
			if(inNode) {
				if(grid[i][j] == '#') {
					rowNodes[rowI] = {nodeStart, j-1};
					rowI++;
					inNode = false;
				} else {
					nodeIds[i*m + j].first = rowI;
				}
			} else if (!inNode) {
				if(grid[i][j] == '.') {
					nodeStart = j;
					inNode = true;
					nodeIds[i*m + j].first = rowI;
				}
			}
		}
		if(inNode) {
			rowNodes[rowI] = {nodeStart, m-1};
			rowI++;
		}
	}

	for(int i = 0; i < m; i++) {
		bool inNode = false;
		int nodeStart = 0;
		for(int j = 0; j < n; j++) {
			if(inNode) {
				if(grid[j][i] == '#') {
					colNodes[colI] = {nodeStart, j-1};
					colI++;
					inNode = false;
				} else {
					nodeIds[j*m + i].second = colI;
				}
			} else if (!inNode) {
				if(grid[j][i] == '.') {
					nodeStart = j;
					inNode = true;
					nodeIds[j*m + i].second = colI;
				}
			}
		}
		if(inNode) {
			colNodes[colI] = {nodeStart, n-1};
			colI++;
		}
	}

	while(q--) {
		int r1, c1, r2, c2;
		scanf("%d", &r1);
		scanf("%d", &c1);
		scanf("%d", &r2);
		scanf("%d", &c2);
		r1--; c1--; r2--; c2--;

		auto node1 = rowNodes[nodeIds[r1*m + c1].first];
		auto node2 = colNodes[nodeIds[r1*m + c1].second];

		auto node3 = rowNodes[nodeIds[r2*m + c2].first];
		auto node4 = colNodes[nodeIds[r2*m + c2].second];

		if(r1 >= node4.first
			&& r1 <= node4.second
			&& c2 >= node1.first
			&& c2 <= node1.second) {
			puts("YES");
		} else if (c1 >= node3.first
			&& c1 <= node3.second
			&& r2 >= node2.first
			&& r2 <= node2.second) {
			puts("YES");
		} else {
			puts("NO");
		}
	}

	return 0;
}