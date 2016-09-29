#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;
	while(n--) {
		int l1, a1, l2, a2, lt, at; cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
		int i = 1;
		int num1, num2;
		int anum1, anum2;
		bool found = false;
		while(i*l1 < lt) {
			if((lt - i*l1) % l2 == 0) {
				num1 = i;
				num2 = (lt - i*l1) / l2;
				if(num1 == 0 || num2 == 0){
					i++;
					continue;
				}
				if(a1 * num1 + a2*num2 == at) {
					if(!found) {
						found = true;
						anum1 = num1;
						anum2 = num2;
					} else {
						found = false;
						break;
					}
				}
			}
			i++;
		}
		if(found) {
			cout << anum1 << " " << anum2 << endl;
		} else {
			cout << "?" << endl;
		}
	}
	
	return 0;
}