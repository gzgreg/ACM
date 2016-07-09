#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;
	while(N--){
		long long a, b, c, s, t; cin >> a >> b >> c >> s >> t;
		if(b*b - 4*a*c < 0){
			cout << "No" << endl;
			continue;
		}

		long long det = b*b - 4*a*c;
		long double xmax = (-b + sqrt(det)) / 2 / a;
		long double xmin = (-b - sqrt(det)) / 2 / a;

		if((xmax >= s && xmax <= t) || (xmin >= s && xmin <= t)){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}