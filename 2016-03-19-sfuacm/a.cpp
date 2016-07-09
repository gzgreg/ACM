#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--){
		int N, K; cin >> N >> K;
		vector<int> points;
		for(int i = 0; i < N-1; i++){
			int val; cin >> val; points.push_back(val);
		}
		sort(points.begin(), points.end());
		K += points[points.size() - 1]; points.pop_back();
		int rank = 1;
		while(!points.empty()){
			int currPlayer = points[points.size() - 1];
			points.pop_back();
			bool changed = false;
			for(int i = points.size() - 1; i >= 0; i--){
				if(currPlayer + points[i] < K){
					points.erase(points.begin() + i);
					changed = true;
					break;
				}
			}
			if(!changed){
				points.pop_back();
				rank++;
			}
		}
		cout << rank << endl;
	}
	
	return 0;
}