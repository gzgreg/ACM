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

	for(int idx = 1; idx <= T; idx++){
		cout << "Case #" << idx << ": ";
		int N; cin >> N;
		set<pair<int,char>, greater<pair<int, char>>> vals;
		char currChar = 'A';
		int totalSen = 0;
		for(int i = 0; i < N; i++){
			int curr; cin >> curr;
			totalSen += curr;
			vals.insert({curr, currChar});
			currChar++;
		}

		while(!vals.empty()){
			if(totalSen == 3){
				pair<int, char> curr = *vals.begin();
				cout << curr.second << " ";
				vals.erase(vals.begin());
				totalSen--;
			} else {
				pair<int, char> curr1 = *vals.begin();
				vals.erase(vals.begin());
				pair<int, char> curr2 = *vals.begin();
				vals.erase(vals.begin());
				cout << curr1.second;
				curr1.first--;
				if(curr1.first != 0) vals.insert(curr1);
				cout << curr2.second << " ";
				curr2.first--;
				if(curr2.first != 0) vals.insert(curr2);

				totalSen -= 2;
			}
		}
		cout << endl;
	}
	
	return 0;
}