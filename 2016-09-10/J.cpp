#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
double PI = 3.14159265358979324;

int main(){
	ios::sync_with_stdio(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int r, n; cin >> r >> n;
		vector<pair<int, int> > coords;
		for (int j = 0; j < n; j++) {
			pair<int, int> a;
			cin >> a.first >> a.second;
			coords.push_back(a);
		}
		double length = 0;
		for (int j = 0; j < n-1; j++) {
			length += sqrt(pow(coords[j+1].first - coords[j].first, 2) +
							pow(coords[j+1].second - coords[j].second, 2));
		}
		length += sqrt(pow(coords[n-1].first - coords[0].first, 2) +
						pow(coords[n-1].second - coords[0].second, 2));
		double s = -2 * PI * r / length + 1;
		if (s < 0) cout << "Not possible" << endl;
		else cout << fixed << setprecision(6) << s << endl;
	}
	return 0;
}
