#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);
	set<int> nums;
	map<int, bool> left, right;
	int n; cin >> n;
	int curr; cin >> curr;
	nums.insert(curr);
	left[curr] = false;
	right[curr] = false;
	for(int i = 0; i < n-1; i++){
		cin >> curr;
		auto it = nums.upper_bound(curr);
		if(it == nums.end() || left[*it]){
			it--;
			cout << *it << " ";
			nums.insert(curr);
			right[*it] = true;

		} else {
			cout << *it << " ";
			nums.insert(curr);
			left[*it] = true;
		}
	}
	cout << endl;
	return 0;
}