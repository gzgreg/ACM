#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	int zz, zo, oz, oo; cin >> zz >> zo >> oz >> oo;
	string s;

	if(zo == 0 && oz == 0) {
		if(zz > 0 && oo > 0) {
			cout << "impossible" << endl;
			return 0;
		} else if (zz > 0) {
			for(int i = 0; i < zz + 1; i++) {
				s.append("0");
			}
			cout << s << endl;
			return 0;
		} else {
			for(int i = 0; i < oo + 1; i++) {
				s.append("1");
			}
			cout << s << endl;
			return 0;
		}
	} 
	if(zo == oz + 1
		|| zo == oz) {
		for(int i = 0; i < zz; i++) {
			s.append("0");
		}

		for(int i = 0; i < zo; i++) {
			s.append("01");
		}

		for(int i = 0; i < oo; i++) {
			s.append("1");
		}
		if(zo == oz) s.append("0");
		cout << s << endl;
		return 0;

	} else if (zo == oz - 1) {
		s.append("1");

		if(zo == 0) {
			for(int i = 0; i < oo; i++) {
				s.append("1");
			}
			for(int i = 0; i < zz+1; i++) {
				s.append("0");
			}
			cout << s << endl;
			return 0;
		} else {
			for(int i = 0; i < zz; i++) {
				s.append("0");
			}

			for(int i = 0; i < zo; i++) {
				s.append("01");
			}

			for(int i = 0; i < oo; i++) {
				s.append("1");
			}
			s.append("0");
			cout << s << endl;
			return 0;
		}
	} else {
		cout << "impossible" << endl;
		return 0;
	}
	
	return 0;
}