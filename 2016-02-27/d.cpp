#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		stack<int> cards;
		for(int i = 0; i < N; i++){
			int curr; cin >> curr;
			cards.push(curr);
		}
		int helper = N+1;
		int goal = 0;
		int ans = 0;
		stack<int> pile;
		while(!cards.empty()){
			int curr = cards.top();
			cards.pop();

			if(curr == goal + 1){
				goal++;
			} else if(curr == helper - 1){
				helper--;
			} else {
				pile.push(curr);
			}

			if(!pile.empty()){
				bool works = true;
				while(works && !pile.empty()){
					int curr2 = pile.top();
					pile.pop();
					if(curr2 == goal + 1){
						goal++;
					} else if(curr2 == helper - 1){
						helper--;
					} else {
						pile.push(curr2);
						works = false;
					}
				}
			}

			if(cards.empty() && !pile.empty()){
				while(!pile.empty()){
					int deck = pile.top();
					pile.pop();
					cards.push(deck);
				}
				ans++;
			}
		}
		cout << ans << endl;

	}

	return 0;
}