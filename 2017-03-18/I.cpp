#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);

	int H, W, N, M; cin >> H >> W >> N >> M;

	vector<vector<int>> img;
	for(int i = 0; i < H; i++) {
		vector<int> curr;
		for(int j = 0; j < W; j++) {
			int tmp; cin >> tmp; curr.push_back(tmp);
		}
		img.push_back(curr);
	}

	vector<vector<int>> kern;
	for(int i = 0; i < N; i++) {
		vector<int> curr;
		for(int j = 0; j < M; j++) {
			int tmp; cin >> tmp; curr.push_back(tmp);
		}
		kern.push_back(curr);
	}

	for(int i = 0; i < H - N + 1; i++) {
		for(int j = 0; j < W - M + 1; j++) {
			int currVal = 0;
			for(int k = 0; k < N; k++) {
				for(int l = 0; l < M; l++) {
					currVal += kern[N-1-k][M-1-l]*img[i+k][j+l];
				}
			}
			cout << currVal << " ";
		}
		cout << endl;
	}
	
	return 0;
}