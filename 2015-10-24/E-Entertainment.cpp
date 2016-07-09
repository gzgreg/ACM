#include <bits/stdc++.h>

using namespace std;

class comp {
public:
	bool operator() (const pair<pair<int, int>, bool>& lhs, pair<pair<int, int>, bool>& rhs) const {
		int lhsComp = lhs.second ? lhs.first.first : lhs.first.second;
		int rhsComp = rhs.second ? rhs.first.first : rhs.first.second;
		if(lhsComp == rhsComp){
			return lhs.second;
		}
		return lhsComp > rhsComp;
	}
};

int main(){
	int n, k; cin >> n >> k;
	vector<pair<int, int> > shows;
	priority_queue<pair<pair<int, int>, bool>, vector<pair<pair<int, int>, bool> >, comp> q;
	for(int i = 0; i < n; i++){
		int in, out; cin >> in >> out;
		shows.push_back(make_pair(in, out));
		//q.push(make_pair(make_pair(in, out), true));
	}
	for(int i = 0; i < n; i++){
		pair<int, int> curr = shows[i];
		bool push = true;
		for(int j = 0; j < n; j++){
			if(j == i) continue;
			if(shows[j].first >= curr.first && shows[j].second <= curr.second && !(shows[j].first == curr.first && shows[j].second == curr.second)){
				for(int k = 0; k < n; k++){
					if(k == i || k == j) continue;
					if((shows[k].first >= curr.first && shows[k].second <= shows[j].first) ||
						(shows[k].first >= shows[j].second && shows[k].second <= curr.second)){
						push = false;
						break;
					}
				}
			}
			if(push) break;
		}
		if(!push) continue;
		q.push(make_pair(shows[i], true));
	}
	int concurrent = 0;
	int numShows = 0;
	while(!q.empty()){
		pair<pair<int, int>, bool> out = q.top();
		q.pop();
		if(out.second){
			if(concurrent < k){
				concurrent++;
				q.push(make_pair(out.first, false));
				numShows++;
			}
		} else {
			concurrent--;
		}
	}
	cout << numShows;
	return 0;
}