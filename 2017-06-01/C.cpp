#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<long long, long long> pii;
typedef vector<long long> vi;

bool tot(long long start, vector<long long> costs, long long S) {
	long long totAns = 0;
	for(long long i = 0; i < costs.size(); i++) {
		costs[i]+= start * (i + 1);
	}
	sort(costs.begin(), costs.end());
	long long num = costs.size();
	for(long long i = 0; i < costs.size(); i++) {
		if(totAns + costs[i] > S) {
			num = i;
			break;
		}
		totAns += costs[i];
	}
	return num >= start;
}

int main(){
	ios::sync_with_stdio(0);

	long long n, S; cin >> n >> S;

	vector<long long> costs; 
	for(long long i = 0; i < n; i++) {
		long long curr; cin >> curr; costs.push_back(curr);
	}
	
	long long l = 0, r = n;

	while(l < r) {
		long long mid = (l + r) / 2;
		if(tot(mid, costs, S)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	long long totAns = 0;
	vector<long long> newCosts(costs);
	for(long long i = 0; i < costs.size(); i++) {
		costs[i] += l * (i + 1);
	}
	sort(costs.begin(), costs.end());
	for(long long i = 0; i < l; i++) {
		totAns += costs[i];
	}
	if(totAns > S) {
		l--;
		totAns = 0;
		costs = newCosts;
		for(long long i = 0; i < costs.size(); i++) {
			costs[i] += l * (i + 1);
		}
		sort(costs.begin(), costs.end());
		for(long long i = 0; i < l; i++) {
			totAns += costs[i];
		}
	}
	cout << l << " " << totAns << endl;
	
	return 0;
}