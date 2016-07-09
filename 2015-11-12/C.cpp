#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int n; cin >> n;
	long long product = 1;
	int num = 0;
	vector<bool> flag (n+2, false);
	for(int i = 2; i <= n; i++){
		int temp = i;
		for(int j = i; j >= 2; j--){
			if(flag[j] && temp%j == 0) temp /= j;
		}
		if(temp == 1) continue;
		product *= i;
		flag[i] = true;
		num++;
	}
	cout << num << endl;
	for(int i = 2; i <= n; i++){
		if(flag[i]) cout << i << " ";
	}

	return 0;
}