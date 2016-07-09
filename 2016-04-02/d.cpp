#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

#define PLACEHOLDER 1000000

int main(){
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);

	int n; cin >> n;

	vector<vector<bool>> comp;

	for(int i = 0; i < n-1; i++){
		comp.push_back(vector<bool>());
		for(int j = 0; j <= i; j++){
			bool curr; cin >> curr; comp[i].push_back(curr);
		}
	}

	reverse(comp.begin(), comp.end());

	vector<double> orig;
	vector<double> sort;

	orig.push_back(200001);
	sort.push_back(200001);

	for(int i = 0; i < n-1; i++){
		bool placed = false;
		// for(int k = 0; k <= i; k++){
		// 	cout << orig[k] << " ";
		// }
		// cout << endl;
		for(int j = 0; j <= i; j++){

			if(j == 0){
				if(comp[i][j] == 0){
					orig.push_back(sort[i]-200000);
					sort.push_back(sort[i]-200000);
					placed = true;
				} else {
					sort.push_back(sort[i]);
					sort[i] = PLACEHOLDER;
				}
			} else {
				if(!placed){
					if(comp[i-j][j] == 0){
						double toPush = (sort[i-j] + sort[i-j+2]) / 2;
						orig.push_back(toPush);
						sort[i-j+1] = toPush;
						placed = true;
					} else {
						sort[i-j+1] = sort[i-j]; 
						sort[i-j] = PLACEHOLDER;
					}
				} else {
					
					if((comp[i-j][j] == 0 && sort[i-j+1] > sort[i-j])
						|| (comp[i-j][j] == 1 && sort[i-j+1] < sort[i-j])){
						cout << "NO" << endl;
						return 0;
					} else if(comp[i-j][j] == 1){
						double temp = sort[i-j+1];
						sort[i-j+1] = sort[i-j];
						sort[i-j] = temp;
					}

				}
				
			}
		}
		if(!placed){
			sort[0] = sort[1] + 200000;
			orig.push_back(sort[1] + 200000);
		}
		// for(int k = 0; k <= i+1; k++){
		// 	cout << orig[k] << " ";
		// }
		// cout << endl;
	}

	reverse(sort.begin(), sort.end());
	reverse(orig.begin(), orig.end());
	vector<int> origInt;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(abs(orig[i] - sort[j]) < 1e-10){
				origInt.push_back(j+1);
				break;
			}
		}
	}
	
	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		cout << origInt[i] << " ";
	}
	cout << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << orig[i] << " ";
	// }
	// cout << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << sort[i] << " ";
	// }
	// cout << endl;

	return 0;
}