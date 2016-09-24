#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n, m; cin >> n >> m;
	vector<int> weights;

	for(int i = 0; i < n; i++) {
		int n; cin >> n; weights.push_back(n);
	}

	vector<int> days;

	for(int i = 0; i < m; i++) {
		int m; cin >> m; days.push_back(m);
	}

	list<int> bookOrder;
	set<int> seenBooks;

	for(int i : days) {
		if(!seenBooks.count(i)) {
			seenBooks.insert(i);
			bookOrder.push_back(i);
		}
	}

	int totalWeight = 0;

	for(int i : days) {
		auto it = bookOrder.begin();
		while(*it != i) {
			totalWeight += weights[*it - 1];
			it++;
		}

		bookOrder.erase(it);
		bookOrder.push_front(i);
	}

	cout << totalWeight << endl;
	
	return 0;
}