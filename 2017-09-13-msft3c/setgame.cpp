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
	for(int id = 1; id <= n; id++) {
		string a, b; cin >> a >> b;
		set<char> fill = {'E', 'F', 'S'};
		set<char> color = {'G', 'P', 'R'};
		set<char> shape = {'O', 'D', 'S'};
		set<char> cnt = {'1', '2', '3'};

		string out;
		if(a[0] != b[0]) {
			cnt.erase(a[0]);
			cnt.erase(b[0]);
			out.push_back(*cnt.begin());
		} else {
			out.push_back(a[0]);
		}
		if(a[1] != b[1]) {
		fill.erase(a[1]);
		fill.erase(b[1]);
			out.push_back(*fill.begin());
		} else {
			out.push_back(a[1]);
		}
		if(a[2] != b[2]) {


		color.erase(a[2]);
		color.erase(b[2]);
			out.push_back(*color.begin());
		} else {
			out.push_back(a[2]);
		}
		if(a[3] != b[3]) {

		shape.erase(a[3]);
		shape.erase(b[3]);
			out.push_back(*shape.begin());
		} else {
			out.push_back(a[3]);
		}


		cout << "Group " << id << ": ";
		cout << out << endl;
	}
	
	return 0;
}