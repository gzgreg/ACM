#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		int N; cin >> N;
		int top = 0, mid = 0, bot = 0;
		for(int j = 0; j < N; j++){
			int xi, yi; cin >> xi >> yi;
			double diff = abs(xi - yi);
			if(diff < 15){
				mid++;
			} else if(yi > xi){
				top++;
			} else bot++;
		}

		cout << "top: " << top << ", mid: " << mid << ", bot: " << bot << endl;
	}

	return 0;
}