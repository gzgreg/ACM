#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n;
	vector<int> houses;
	int start;
	while(cin >> n){
		houses.clear();
		for(int i = 0; i < n; i++){
			int curr; cin >> curr; houses.push_back(curr);
		}
		cin >> start;
		sort(houses.begin(), houses.end());
		int startIdx = -1;
		bool ifNotInVec = false;
		for(int i = 0; i < n; i++){
			if(houses[i] == start){
				startIdx = i;
				break;
			} else if(houses[i] > start){
				houses.insert(houses.begin() + i, start);
				startIdx = i;
				ifNotInVec = true;
				n++;
				break;
			}
		}

		if(startIdx == -1){
			startIdx = n;
			n++;
			ifNotInVec = true;
			houses.push_back(start);
		}

		// int cumsum1 = 0;
		int tot = 0;
		// for(int i = startIdx - 1; i >= 0; i--){
		// 	if((startIdx - i) % 5 == 1){
		// 		tot += 2 * cumsum1;
		// 	}
		// 	cumsum1 += houses[i+1] - houses[i];
		// 	tot += houses[i+1] - houses[i];
		// }
		// int lTime1 = tot;
		// tot = 0;
		// int cumsum2 = 0;
		// for(int i = startIdx + 1; i < n; i++){
		// 	if((i - startIdx) % 5 == 1){
		// 		tot += 2 * cumsum2;
		// 	}
		// 	cumsum2 += houses[i] - houses[i-1];
		// 	tot += houses[i] - houses[i-1];
		// }
		// int rTime1 = tot;
		// tot = 0;

		for(int i = 0; i <= startIdx; i+=5){
			tot += 2*(houses[startIdx] - houses[i]);
		}
		int lTime2 = tot;
		tot = 0;

		for(int i = n-1; i >= startIdx; i-=5){
			tot += 2*(houses[i] - houses[startIdx]);
		}
		int rTime2 = tot;
		//cout << lTime1 << " " << rTime1 << " " << lTime2 << " " << rTime2 << endl;
		tot = lTime2 + rTime2;
		tot -= max(houses[startIdx] - houses[0], houses[n-1] - houses[startIdx]);
		tot += n;
		if(ifNotInVec) tot--;
		cout << tot << endl;
	}
	
	return 0;
}