#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

long long K;

bool check(int guess, vector<int> prices) {
	if(guess < 0) return false;
	long long totalPairs = 0;
	for(int i = 1; i < prices.size(); i++) {
		int l = 0;
		int r = i;
		while(l - r  > 1) {
			if(prices[i] + prices[(l+r) / 2] > guess) {
				r = r - (r - l) / 2;
			} else {
				l = l + (r - l) / 2;
			}
		}
		if(l != r) {
			if(prices[i] + prices[r] > guess) {
				r--;
			} else {
				l++;
			}
		}
		totalPairs += i - l;
		cout << totalPairs << " ";
	}
	return totalPairs >= K;
}

int main(){
	ios::sync_with_stdio(0);
	
	long long N; cin >> N >> K;

	vector<int> prices;
	for(int i = 0; i < N; i++) {
		int curr; cin >> curr; prices.push_back(curr);
	}

	sort(prices.begin(), prices.end());

	int guess = (prices[N-1] + prices[N-2]);
	int diff = guess / 2 + 1;
	while(diff != 0) {
		if(check(guess, prices)) {
			guess -= diff;
			diff = (diff + 0.5) / 2; 
		} else {
			guess += diff;
			diff = (diff + 0.5) / 2; 
		}
		if(diff == 1) break;
		cout << guess << endl;
	}
	
	if(check(guess-1, prices)) {
		guess = guess - 1;
	} else if(!check(guess, prices)) {
		guess = guess + 1;
	}

	cout << guess << endl;
	return 0;
}