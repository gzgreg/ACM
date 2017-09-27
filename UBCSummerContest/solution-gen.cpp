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

	cout << 2 << " " << 500000 << endl;
	cout << 100 << " " << 1 << endl;
	
	mt19937 rng;
    rng.seed(0);
    uniform_int_distribution<> nGen(1, 500);
    uniform_int_distribution<> pGen(1, 999999);

	for(int i = 0; i < 30; i++) {
		cout << nGen(rng) << " " << pGen(rng) << endl;
	}

	cout << 50000 << " " << 999999 << endl;
	cout << 50000 << " " << 1 << endl;
	cout << 50000 << " " << 500000 << endl;
	nGen = uniform_int_distribution<>(1, 50000);

	for(int i = 0; i < 60; i++) {
		cout << nGen(rng) << " " << pGen(rng) << endl;
	}
	
	return 0;
}