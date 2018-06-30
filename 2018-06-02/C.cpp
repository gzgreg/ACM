#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;

	while(T--) {
		ll n, m, k; cin >> n >> m >> k;

		ll x, s; cin >> x >> s;
		vector<pii> talentsI(m);
		for(int i = 0; i < m; i++) {
			cin >> talentsI[i].second;
		}
		for(int i = 0; i < m; i++) {
			cin >> talentsI[i].first;

		}
		vector<pii> heroesI(k);
		for(int i = 0; i < k; i++) {
			cin >> heroesI[i].second;
			heroesI[i].second = -heroesI[i].second;
		}
		for(int i = 0; i < k; i++) {
			cin >> heroesI[i].first;
		}

		sort(talentsI.begin(), talentsI.end());
		sort(heroesI.begin(), heroesI.end());

		vector<pii> talents, heroes;
		for(int i = 0; i < m; i++) {
			if(i == 0) talents.push_back(talentsI[i]);
			else {
				if(talentsI[i].second < talents.back().second) talents.push_back(talentsI[i]);
			}
		}
		heroes.push_back({0, 0});
		for(int i = 0; i < k; i++) {
			if(i == 0) heroes.push_back(heroesI[i]);
			else {
				if(heroesI[i].second < heroes.back().second) heroes.push_back(heroesI[i]);
			}
		}

		k = heroes.size();
		m = talents.size();

		reverse(heroes.begin(), heroes.end());

		ll bestAns = n*x;
		int heroIdx = 0;
		while(heroIdx < k && heroes[heroIdx].first > s) heroIdx++;

		bestAns = min(bestAns, (n + heroes[heroIdx].second) * x);
		for(int i = 0; i < m; i++) {
			while(heroIdx < k && heroes[heroIdx].first > s - talents[i].first) heroIdx++;
			if(s - talents[i].first < 0) break;
			bestAns = min(bestAns, (n + heroes[heroIdx].second) * (talents[i].second));
		}
		cout << bestAns << endl;
	}
	
	return 0;
}