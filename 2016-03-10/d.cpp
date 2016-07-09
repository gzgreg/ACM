#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<vector<int>>>> memo;

int n, a, b, T; 
string s; 

int dp(int numPhotos, int start, int end, bool left){
	if(numPhotos == 0) return 0;
	int timeToRight = 1 + a + (s[end] == 'h' ? 0 : b);
	if(left) timeToRight += a*(end - (start > end ? start - n+1 : start) - 1);
	int startIdx = (start - 1 < 0 ? n-1 : start - 1);
	int timeToLeft = 1 + a + (s[startIdx] == 'h' ? 0 : b);
	if(right) timeToLeft += a*(end - (start > end ? start-n+1 : start) - 1);
	if(numPhotos != 1){
		timeToRight += dp(numPhotos - 1, start, end+1, false);
		timeToLeft += dp(numPhotos - 1, startIdx, end, true);
	}
	cout << numPhotos << " " << start << " " << end << " " << left << " " << min(timeToRight, timeToLeft) << endl;
	return min(timeToRight, timeToLeft);
}

int main(){
	ios::sync_with_stdio(0);

	cin >> n >> a >> b >> T;
	cin >> s;

	for(int i = 0; i < 50; i++){
		vector<vector<vector<int> > > empty;
		for(int j = 0; j < 50; j++){
			vector<vector<int> > empty2;
			for(int k = 0; k < 50; k++){
				vector<int> empty3; empty3.push_back(0); empty3.push_back(0);
				empty2.push_back(empty3);
			}
			empty.push_back(empty2);
		}
		memo.push_back(empty);
	}

	int max = n;
	int min = 1;
	int diff = (max - min) / 2;
	while(max != min){
		int avg = (max + min) / 2;
		int val = dp(avg-1, 0, 1, true) + 1 + (s[0] == 'h' ? 0 : b);
		if(val < T){
			min += diff;
			diff /= 2;
		} else if(val > T){
			max -= diff;
			diff /= 2;
		} else {
			cout << avg << endl;
			return 0;
		}
		if(diff == 0){
			diff = 1;
		}

	}

	if(dp(max, 0, 1, true) + 1 + (s[0] == 'h' ? 0 : b) > T) max--;
	cout << max << endl;
	return 0;
}