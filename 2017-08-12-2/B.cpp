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

	int n, m; cin >> n >> m;
	vector<string> flag;
	for(int i = 0; i < n; i++) {
		string s; cin >> s; flag.push_back(s);
	}

	int height = n, width = m;
	for(int i = 0; i < m; i++) {
		if(flag[0][i] != flag[0][0]) {
			width = i;
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		if(flag[i][0] != flag[0][0]) {
			height = i;
			break;
		}
	}
	if((height != n && width != m)
		|| (height == n && width == m)) {
		cout << "NO" << endl;
		return 0;
	} else if (height == n) {
		if(width != m / 3 || m % 3 != 0)  {
			cout << "NO" << endl;
			return 0;
		}
		for(int f = 0; f < 3; f++) {
			for(int i = 0; i < height; i++) {
				for(int j = 0; j < width; j++) {
					if(flag[i][j + f * width] != flag[0][f*width]) {
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}
		if(flag[0][0] == flag[0][width]
			|| flag[0][0] == flag[0][2*width]
			|| flag[0][width] == flag[0][2*width]) {
			cout << "NO" << endl;
			return 0;
		}
	} else {
		if(height != n / 3 || n % 3 != 0)  {
			cout << "NO" << endl;
			return 0;
		}
		for(int f = 0; f < 3; f++) {
			for(int i = 0; i < height; i++) {
				for(int j = 0; j < width; j++) {
					if(flag[i + f * height][j] != flag[f * height][0]) {
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}
		if(flag[0][0] == flag[height][0]
			|| flag[0][0] == flag[2*height][0]
			|| flag[height][0] == flag[2*height][0]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	
	return 0;
}