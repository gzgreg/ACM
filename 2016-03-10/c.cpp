#include <bits/stdc++.h>

using namespace std;

bool mysort(pair<long long, long long> i, pair<long long, long long> j){
	if(i.second != j.second) return (i.second < j.second);
	return (i.first < j.first);
}

int main(){
	ios::sync_with_stdio(0);

	long long n; cin >> n;

	vector<pair<long long, long long> > loc;

	for(long long i = 0; i < n; i++){
		long long xi, yi; cin >> xi >> yi; loc.push_back(make_pair(xi, yi));
	}

	sort(loc.begin(), loc.end());

	long long total = 0;
	long long align = 0;
	for(long long i = 1; i < n; i++){
		if(loc[i].first == loc[i-1].first){
			align++;
		} else {
			total += align*(align+1)/2;
			align = 0;
		}
	}
	total += align*(align+1)/2;
	align = 0;

	sort(loc.begin(), loc.end(), mysort);

	for(long long i = 1; i < n; i++){
		if(loc[i].second == loc[i-1].second){
			align++;
		} else {
			total += align*(align+1)/2;
			align = 0;
		}
	}
	total += align*(align+1)/2;
	align = 0;

	for(long long i = 1; i < n; i++){
		if(loc[i].first == loc[i-1].first && loc[i].second == loc[i-1].second){
			align++;
		} else {
			total -= align*(align+1)/2;
			align = 0;
		}
	}

	total -= align*(align+1)/2;
	align = 0;

	cout << total << endl;

	return 0;
}