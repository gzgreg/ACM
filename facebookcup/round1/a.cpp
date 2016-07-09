#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int i = 1; i <= T; i++){
		int N; cin >> N;
		vector<int> diff;
		for(int j = 0; j < N; j++){
			int curr; cin >> curr;
			diff.push_back(curr);
		}

		int numC = 0;
		int prob = 1;
		for(int j = 1; j < N; j++){
			int curr = diff[j], last = diff[j-1];
			if(curr <= last && prob != 0){
				numC++; prob = 0;
			} else if(curr > 10 + last){
				prob += (curr - last - 1) / 10;
			}
			prob++;
			if(prob >= 4){
				numC += min(2, prob / 4);
				prob = min(2, prob / 4) < 2 ? prob % 4 : 0;
			}
		}
		if(prob > 0) numC += prob / 4 + 1;

		cout << "Case #" << i << ": " << numC*4 - diff.size() << endl;
	}

	return 0;
}