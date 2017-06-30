#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();

	int a, b, l, r; cin >> a >> b >> l >> r;
	l--; r--;

	int origL = l;
	l %= a+b;
	r -= (origL - l);
	set<char> seen;
	string s;
	for(int i = 0; i < a; i++) {
		s.push_back(i + 'a');
	}
	for(int i = 0; i < b; i++) {
		s.push_back(s[a-1]);
	}
	int iters = 0;
	while(!seen.count(s[a + (a+b)*iters-1])) {
		iters++;
		int offset = (a+b) * iters;
		seen.insert(s[a + offset - 1 - (a+b)]);
		set<char> letters;
		for(int i = offset - a; i < offset; i++) {
			letters.insert(s[i]);
		}

		for(int i = 0, letterIdx = 0; i < a; i++, letterIdx++) {
			while(letters.count(letterIdx + 'a')) {
				letterIdx++;
			}
			s.push_back(letterIdx + 'a');
		}

		for(int i = 0; i < b; i++) {
			s.push_back(s[a + offset-1]);
		}
	}

	set<char> seenLetters;
	for(int i = l; i <= min(r, (int) s.size()-1); i++) {
		seenLetters.insert(s[i]);
	}

	cout << seenLetters.size() << endl;
	
	
	return 0;
}