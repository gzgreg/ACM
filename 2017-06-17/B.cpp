#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, q; cin >> n >> k >> q;

	vector<pii> temps;
	for(int i = 0; i < n; i++) {
		int li, ri; cin >> li >> ri; temps.push_back({li, ri});
	}
	map<int, int> count;
	map<int, int> count2;
	for(pii curr : temps) {
		count[curr.second]++;
		count2[curr.first]++;
	}

	vector<pii> queries;
	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; queries.push_back({a, b});
	}

	vector<int> cumsum; cumsum.push_back(0);

	int currTemps = 0;
	int l = 0;
	for(int i = 1; i <= 200001; i++) {
		currTemps += count2[i];
		currTemps -= count[i - 1];
		if(currTemps >= k) {
			cumsum.push_back(cumsum[cumsum.size() - 1] + 1);
		} else {
			cumsum.push_back(cumsum[cumsum.size() - 1]);
		}
	}

	for(pii curr : queries) {
		cout << cumsum[curr.second] - cumsum[curr.first - 1] << endl;
	}

	return 0;
}