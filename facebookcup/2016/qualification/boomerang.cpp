#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int l = 0; l < T; l++){
		int N; cin >> N;
		vector<pair<int, int> > stars;
		for(int i = 0; i < N; i++){
			int first, second; cin >> first >> second;
			stars.push_back(make_pair(first, second));
		}
		int total = 0;
		for(int i = 0; i < stars.size(); i++){
			map<int, int> dist;
			for(int j = 0; j < stars.size(); j++){
				if(j == i) continue;
				int x = (stars[i].first - stars[j].first);
				int y = (stars[i].second - stars[j].second);
				int curr = x*x + y*y;
				dist[curr] = dist[curr] + 1;
			}
			for(auto it = dist.begin(); it != dist.end(); it++){
				total += it->second*(it->second - 1) / 2;
			}
		}
		cout << "Case #" << (l + 1) << ": " << total << endl;
	}

	return 0;
}