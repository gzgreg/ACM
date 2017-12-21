#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ld> pt;
ld cp(const pt& a, const pt& b) { return imag(conj(a)*b); }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<complex<ld>> pts;

	for(int i = 0; i < 3; i++) {
		ld x, y; cin >> x >> y;
		pts.push_back({x, y});
 	}

 	vector<vector<int>> dist;

 	for(int i = 0; i < 3; i++) {
 		int n; cin >> n;
 		vector<int> cur;
 		for(int j = 0; j < n; j++) {
 			int val; cin >> val; cur.push_back(val);
 		}
 		dist.push_back(cur);
 	}

 	vector<complex<ld>> corners;
 	for(int i = 0; i < 3; i++) {
 		ld curDist = dist[i][0];
 		complex<ld> side = (pts[(i+1) % 3] - pts[i]) / abs((pts[(i+1) % 3] - pts[i]));

 		corners.push_back(curDist*side + pts[i]);
 		if(dist[i].size() == 1) continue;
 		curDist = dist[i][dist[i].size() - 1];
 		corners.push_back(curDist*side + pts[i]);
 	}
 	ld largest = 0.0;
 	for(int i = 0; i < corners.size(); i++) {
 		for(int j = i+1; j < corners.size(); j++) {
 			for(int k = j+1; k < corners.size(); k++) {
 				ld curArea = 0;
 				curArea += cp(corners[i], corners[j]);
 				curArea += cp(corners[j], corners[k]);
 				curArea += cp(corners[k], corners[i]);
 				curArea = abs(curArea) / 2;
 				largest = max(largest, curArea);
 			}
 		}
 	}

 	cout << fixed << setprecision(10) << largest << endl;

	return 0;
}