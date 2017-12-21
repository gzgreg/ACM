#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main(){
	#define int ll
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	map<int, pii, greater<int>> coords;
	int maxY = 0;
	for(int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		maxY = max(y, maxY);
		if(coords.count(y)) {
			coords[y].first = min(coords[y].first, x);
			coords[y].second = max(coords[y].second, x);
		} else {
			coords[y] = {x, x};
		}
	}

	int curY = maxY;
	int curL = coords[curY].first - 1, curR =  coords[curY].second + 1;
	int size = curR - curL + 1, area = 0;
	for(auto cur : coords) {
		if(cur.first == maxY) continue;
		size += 2*(curY - cur.first);
		area += (curR - curL - 1) * (curY - cur.first);

		if(curR < cur.second.second+1) {
			size += cur.second.second - curR+1;
			curR = cur.second.second + 1;
		}
		if(curL > cur.second.first - 1) {
			size += curL - cur.second.first + 1;
			curL = cur.second.first - 1;
		}
		curY = cur.first;
		//cout << size << " " << area << endl;
	}
	area += (curR - curL - 1) * (curY + 1);
	size += 2*(curY + 1);

	cout << size+2 << " " << size << " " << area << endl;
	
	return 0;
}