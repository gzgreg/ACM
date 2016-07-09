#include <bits/stdc++.h>

using namespace std;

struct comp {
	bool operator() (pair<int, int> i, pair<int, int> j) {return i.first < j.first;}
} comp;

int main(){
	ios::sync_with_stdio(0);
	int n; cin >> n;
	pair<int, int> seg[1000];
	while(n--){
		int m; cin >> m;
		int li, ri;
		int i = 0;
		while(true){
			cin >> li >> ri;
			if(li == 0 && ri == 0) break;
			seg[i] = make_pair(li, ri);
			i++;
		}
		sort(seg, seg + i, comp);
		int minL = 0;
		int maxR = 0;
		int idx;
		vector<int> ids;
		for(int j = 0; j < i; j++){
			pair<int, int> curr = seg[j];
			int l = curr.first;
			int r = curr.second;
			if(r < minL) continue;
			if(l > maxR){
				cout << 0 << endl;
				break;
			}
			if(l < minL && r > maxR){
				idx = j;
				maxR = r;
			} else if(l > minL){
				ids.push_back(idx);
				minL = maxR;
				maxR = maxR + 1;
			}
		}
	}

	return 0;
}