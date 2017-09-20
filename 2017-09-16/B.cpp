#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n; cin >> n;

	vector<pair<ll, ll>> poly;
	for(int i = 0; i < n; i++) {
		ll xi, yi; cin >> xi >> yi;
		poly.emplace_back(xi, yi);
	}

	ll area = 0;

	for(int i = 0; i < n; i++) {
		area += poly[i].first * poly[(i+1) % n].second;
		area -= poly[(i+1) % n].first * poly[i].second;
	}

	int l = 0, r = 2;
	int bestL = 0, bestR = 2;
	ll bestArea = 0;
	ll curArea = 0;
	curArea = poly[0].first * poly[1].second
				+ poly[1].first * poly[2].second
				+ poly[2].first * poly[0].second
				- poly[0].second * poly[1].first
				- poly[1].second * poly[2].first 
				- poly[2].second * poly[0].first;
	bestArea = curArea;
	while(l < n) {
		if(curArea < area / 2) {
			r++;
			if(r == n) r = 0;
			curArea += poly[l].first * poly[r-1].second
				+ poly[r-1].first * poly[r].second
				+ poly[r].first * poly[l].second
				- poly[l].second * poly[r-1].first
				- poly[r-1].second * poly[r].first 
				- poly[r].second * poly[l].first;
		} else {
			curArea -= poly[l].first * poly[l+1].second
				+ poly[l+1].first * poly[r].second
				+ poly[r].first * poly[l].second
				- poly[l].second * poly[l+1].first
				- poly[l+1].second * poly[r].first 
				- poly[r].second * poly[l].first;
			l++;
		}
		if(abs(bestArea - area / 2) > abs(curArea - area / 2)) {
			bestArea = curArea;
			bestL = l;
			bestR = r;
			//cout << l << " " << r << endl;
		}
	}

	//cout << bestArea << " " << area << endl;

	cout << bestL + 1 << " " << bestR + 1 << endl;
	
	return 0;
}