#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'
vector<vector<int>> hexes (7, vector<int> (6, 0));

int findNum(vector<int> vec, int num) {
	for(int i = 0; i < vec.size(); i++) {
		if(vec[i] == num) return i;
	}
	return -1;
}

vector<int> dfs(set<int> hexesLeft, int leftEdge, int rightEdge, int middleHex) {
	if(hexesLeft.size() == 0) {
		return vector<int>();
	} else if (hexesLeft.size() == 7) {
		for(int i = 0; i < 7; i++) {
			set<int> newHexesLeft = hexesLeft;
			newHexesLeft.erase(i);
			vector<int> hexes2 = dfs(newHexesLeft, 0, 0, i);
			hexes2.push_back(i);
			if(hexes2.size() == 7) return hexes2;
		}
	} else if (hexesLeft.size() == 6) {
		for(int hex : hexesLeft) {
			set<int> newHexesLeft = hexesLeft;
			newHexesLeft.erase(hex);
			int idx = findNum(hexes[hex], 1);
			vector<int> hexes2 = dfs(newHexesLeft, hexes[hex][(idx + 1) % 6], hexes[hex][(idx + 5) % 6], middleHex);
			hexes2.push_back(hex); 
			if(hexes2.size() == 6) return hexes2;
		}
	} else if(hexesLeft.size() == 1) {
		int hex = *(hexesLeft.begin());
		int idx = findNum(hexes[hex], hexes[middleHex][(findNum(hexes[middleHex], 1) + 5) % 6]);
		if(hexes[hex][(idx + 1) % 6] == rightEdge
			&& hexes[hex][(idx + 5) % 6] == leftEdge) {
			return vector<int> (1, hex);
		} else {
			return vector<int> ();
		}
	} else {
		for(int hex : hexesLeft) {
			set<int> newHexesLeft = hexesLeft;
			newHexesLeft.erase(hex);
			int idx = findNum(hexes[hex], hexes[middleHex][(findNum(hexes[middleHex], 1) - hexesLeft.size() + 6) % 6]);
			if(hexes[hex][(idx + 1) % 6] == rightEdge) {
				vector<int> hexes2 = dfs(newHexesLeft, leftEdge, hexes[hex][(idx + 5) % 6], middleHex);
				hexes2.push_back(hex); 
				if(hexes2.size() == hexesLeft.size()) return hexes2;
			}
		}
	}
	return vector<int> ();
}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	int idx = 1;
	while(T--) {
		for(int i = 0; i < 7; i++) {
			for(int j = 0; j < 6; j++) {
				cin >> hexes[i][j];
			}
		}
		set<int> hexesLeft = {0, 1, 2, 3, 4, 5, 6};
		vector<int> ans = dfs(hexesLeft, 0, 0, 0);

		cout << "Case " << idx << ": ";
		if(ans.size() == 0) {
			cout << "No solution" << endl;
		} else {
			for(int i = 6; i >= 0; i--) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}

		idx++;
	}
	
	return 0;
}