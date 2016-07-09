#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		cout << "Case " << i+1 << ":" << "\n";
		map<int, pair<int, int> > loc;
		map<int, list<int> > covered;
		int n; cin >> n;
		for(int j = 0; j < n; j++){
			int li, ri; cin >> li >> ri;
			list<int> currCovered;
			for (int k=1; k <= j; k++){
				pair<int, int> curr = loc[k];
				if((curr.first < ri && curr.second > ri) || (curr.first < li && curr.second > li) || (curr.second <= ri && curr.first >= li)){
					currCovered.push_back(k);
					if(curr.second <= ri && curr.first >= li){
						loc[k].first = -1;
						loc[k].second = -1;
					} else if(curr.first < ri && curr.second > ri){
						loc[k].first = ri;
					} else {
						loc[k].second = li;
					}
				}
			}
			loc.insert(make_pair(j + 1, make_pair(li, ri)));
			covered.insert(make_pair(j + 1, currCovered));
		}

		for(std::map<int, list<int> >::iterator it=covered.begin(); it != covered.end(); it++){
			cout << it->second.size() << " ";
			for(std::list<int>::iterator it2=it->second.begin(); it2 != it->second.end(); it2++){
				cout << *it2 << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}