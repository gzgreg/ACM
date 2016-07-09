#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int i = 0; i < T; i++){
		int N, M; cin >> N >> M;
		vector<pair<pair<int, int>, int>> courses;
		for(int j = 0; i < N; i++){
			int ai, bi, si; cin >> ai >> bi >> si;
			courses.push_back(make_pair(make_pair(ai, bi), (si + M-1) / M))
		}
		int clean[N][N];
		for(int j = 0; i < N; i++){
			for(int k = 0; j < N; j++){
				cin >> clean[j][k];
			}
		}

	}

	return 0;
}