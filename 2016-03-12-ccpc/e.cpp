#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int N, M;
set<pair<int, int>> invalid;
map<pair<int, int>, pair<int, int>> memo;

pair<int, int> dp(int given){
	if(given == 0){
		return make_pair(1, 0);
	}
	if(memo.find({given, received}) != memo.end()){
		return memo[{given, received}];
	}
	int a = 0, b = 0;
	for(int i = 0; i < N; i++){
		if((given & (1 << i)) == 0) continue;
		//cout << given << " " << (1 << i) << endl;
		
		for(int j = 0; j < N; j++) {
			if((received & (1 << j)) == 0) continue;
			if(i == j || invalid.find(make_pair(i+1, j+1)) != invalid.end()){
				//if(invalid.find(make_pair(i+1, j+1)) != invalid.end()) cout << "asdf" << endl;
				 continue; 
			}
			int receivedNew = received - (1 << j);
			int givenNew = given - (1 << i);
			pair<int, int> calc = dp(givenNew, receivedNew);
			if(i == 0 && j == 1){
				calc.second = calc.first;
			}
			a += calc.first;
			b += calc.second;
		}
		
	}
	memo[{given,received}] = make_pair(a, b);
	return make_pair(a, b);

}

int main(){
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while(T--){
		cin >> N >> M;
		memo.clear();
		invalid.clear();
		for(int i = 0; i < M; i++){
			int a, b; cin >> a >> b;
			invalid.insert(make_pair(a, b));
		}

		pair<int, int> ans = dp(pow(2, N) - 1, pow(2, N) - 1);
		cout << fixed << setprecision(7) << (double) ans.second / ans.first << endl;
	}
	
	return 0;
}