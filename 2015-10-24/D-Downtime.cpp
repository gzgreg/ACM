#include <bits/stdc++.h>

using namespace std;

class comp {
public:
	bool operator() (const pair<int, bool>& lhs, pair<int, bool>& rhs) const {
		if(lhs.first == rhs.first){
			return lhs.second;
		}
		return lhs.first > rhs.first;
	}
};

int main(){
	int n, k; cin >> n >> k;
	priority_queue<pair<int, bool>, vector<pair<int, bool> >, comp> q;
	for(int i = 0; i < n; i++){
		int in; cin >> in;
		q.push(make_pair(in, true));
	}
	int concurrent = 0;
	int maxCon = 0;
	while(!q.empty()){
		pair<int, bool> out = q.top();
		q.pop();
		if(out.second){
			concurrent++;
			q.push(make_pair(out.first + 1000, false));
		} else {
			concurrent--;
		}
		if(concurrent > maxCon) maxCon = concurrent;
	}

	cout << ceil((double) maxCon / k);
	return 0;
}