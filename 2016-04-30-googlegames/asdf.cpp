#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

#define MOD 1000000007

int main(){
	ios::sync_with_stdio(0);


	int g, w; cin >> g >> w;

	vector<int> gVal;
	map<string, int> gName;

	vector<set<int>> conn;

	for(int i = 0; i < g; i++){
		int val; string name; cin >> val >> name;

		gVal.push_back(val);
		gName.insert(make_pair(name, i));
		conn.push_back(set<int> ());
	}

	set<int> starts;
	for(int i = 0; i < w; i++){
		string name1, name2; cin >> name1 >> name2;

		int val1, val2; val1 = gName.at(name1); val2 = gName.at(name2);
		if(val1 == 0 || val2 == 0){
			if(val1 == 0){
				starts.insert(val2);
			} else {
				starts.insert(val1);
			}
		} else {
			conn[val1].insert(val2);
			conn[val2].insert(val1);
		}
	}

	vector<int> components;
	set<int> visited;

	while(!starts.empty()){
		int currVal = 0;
		queue<int> bfsq; bfsq.push(*starts.begin()); starts.erase(starts.begin());
		while(!bfsq.empty()){
			int curr = bfsq.front();
			currVal += gVal[curr];
			bfsq.pop();
			visited.insert(curr);
			for(auto j = conn[curr].begin(); j != conn[curr].end(); j++){
				if(visited.find(*j) != visited.end()) continue;
				visited.insert(*j);
				auto it = starts.find(*j);
				starts.erase(it);
				bfsq.push(*j);
			}
		}

		components.push_back(currVal);
	}

	sort(components.begin(), components.end());
	reverse(components.begin(), components.end());
	int ans = 0;
	for(int i = 0; i < 5; i++){
		if(components.size() <= i) break;
		ans += components[i];
	}
	cout << ans;
}