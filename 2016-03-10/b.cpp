#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;

	vector<int> a;
	for(int i = 0; i < n; i++){
		int curr; cin >> curr; a.push_back(curr);
	}

	sort(a.begin(), a.end());

	int total = 0;
	while(!a.empty()){
		int curr = 0;
		for(auto it = a.begin(); it != a.end(); it++){
			if(*it > curr){
				curr = *it;
				total++;
				a.erase(it);
				it--;
			}
		}
		total--;
	}

	cout << total << endl;

	return 0;
}