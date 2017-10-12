#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	while(n--) {
		int l1, a1, l2, a2, lt, at; 
		cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;

		set<pii> ans;
		for(int i = 0; i <= 10000; i++) {
			int num1 = i;
			int num2 = (lt - (num1 * l1)) / l2;

			if(num1*l1 + num2*l2 == lt
				&& num1*a1 + num2*a2 == at
				&& num1 >= 1
				&& num2 >= 1) {
				ans.insert({num1, num2});
			}
		}
		if(ans.size() == 1) {
			cout << (*ans.begin()).first << " " << (*ans.begin()).second << endl;
		} else {
			cout << "?" << endl;
		}
	}
	
	return 0;
}