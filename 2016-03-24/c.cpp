#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n, k; cin >> n >> k;
	vector<bool> rooms;
	vector<int> cumsum;
	cumsum.push_back(0);
	for(int i = 0; i < n; i++){
		char curr; cin >> curr;
		rooms.push_back(curr == '0');
		cumsum.push_back(cumsum[i] + rooms[i]);
	}
	int minDist = 1000000;

	int top = n;
	int bottom = 1;
	int diff = (top - bottom) / 2;
	while(top != bottom){
		int avg = (top + bottom) / 2;
		bool good = false;
		for(int i = 0; i < n; i++){
			if(!rooms[i]) continue;
			//cout << top << " " << bottom << " " << avg << " " << i << " | ";
			int curr = 0;
			//cout << cumsum[min(i+avg, n-1)] - cumsum[max(i-avg, 0)];
			if(cumsum[min(i+avg, n-1)+1] - cumsum[max(i-avg, 0)] - 1 >= k){
				good = true;
				break;
			}
			// for(int j = max(i - avg, 0); j <= min(i+avg, n-1); j++){
			// 	if(rooms[j] && j != i){
			// 		//cout << j << " ";
			// 		curr++;
			// 		if(curr >= k){
			// 			//cout << "a";
			// 			good = true;
			// 			break;
			// 		}
			// 	}
			// }
			//cout << endl;
			if(good) break;
		}
		if(!good){
			bottom += diff;
		} else {
			top -= diff;
		}
		diff /= 2;
		if(diff == 0) diff = 1;
	}

	int avg = top - 1;
	bool good = false;
	for(int i = 0; i < n; i++){
		if(!rooms[i]) continue;
		//cout << top << " " << bottom << " " << avg << " " << i;
		int curr = 0;
		if(cumsum[min(i+avg, n-1)+1] - cumsum[max(i-avg, 0)]-1 >= k){
			good = true;
			break;
		}
		// for(int j = max(i - avg, 0); j <= min(i+avg, n-1); j++){
		// 	if(rooms[j] && j != i){
		// 		curr++;
		// 		if(curr >= k){
		// 			//cout << "a";
		// 			good = true;
		// 			break;
		// 		}
		// 	}
		// }
		//cout << endl;
		if(good) break;
	}
	if(good){
		cout << top - 1 << endl;
	} else {
		cout << top << endl;
	}
	
	return 0;
}