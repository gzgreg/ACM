#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

long long x;
long long y;

long long extended_gcd(long long a, long long b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
 
    long long gcd = extended_gcd(b, a % b);
 
    long long x1 = y;
    long long y1 = x - (a/b)*y;
    x = x1;
    y = y1;
 
    return gcd;
}

int main(){
    ios::sync_with_stdio(0);
    long long t; cin >> t;
    for (long long i = 0; i < t; i++) {
        long long K, C; cin >> K >> C;
        if (extended_gcd(K, C) != 1) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        while (x > 0 || y < 0) {
            x -= C;
            y += K;
        }
        if (y > 1e9) cout << "IMPOSSIBLE" << endl;
        else cout << y << endl;
    }
    return 0;
}
