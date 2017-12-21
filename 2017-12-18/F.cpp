#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int Y, N, S; cin >> Y >> N >> S;

	int H, M; cin >> H >> M;
	vector<vector<int>> stays;
	for(int i = 0; i < M; i++) {
		vector<int> curStay(4);
		cin >> curStay[0] >> curStay[1] >> curStay[2] >> curStay[3];
		stays.push_back(curStay);
	}

	map<int, set<int>> adj;
	for(int i = 0; i < M; i++) {
		adj[M].insert(i);
		adj[i].insert(M+1);
	}

	for(int i = 0; i < M; i++) {
		for(int j = 0; j < M; j++) {
			if(i == j) continue;
			if(sta)
		}
	}

	return 0;
}