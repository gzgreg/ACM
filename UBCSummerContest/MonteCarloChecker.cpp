#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

    std::mt19937 rng;
    rng.seed(std::random_device()());

    int k; cin >> k;
    while(k--){
        int len; cin >> len;
        double p; cin >> p; p /= 1e6;
        std::discrete_distribution<std::mt19937::result_type> dist{ 0, 0, p, 0, 1 - p };

        ll total = 0;
        const int iters = 10000;
        for (int i = 0; i < iters; i++) {
            //cout << i << endl;
            vector<ll> vals(len, -1);
            int firstUnoccupied = 0;
            while (firstUnoccupied < len) {
                int next = dist(rng);
                total += next;
                vals[firstUnoccupied] = next;
                while (firstUnoccupied > 0 && vals[firstUnoccupied] == vals[firstUnoccupied - 1]) {
                    vals[firstUnoccupied] = 0;
                    vals[firstUnoccupied - 1] *= 2;
                    firstUnoccupied--;
                }
                firstUnoccupied++;
                // for(int i = 0; i < firstUnoccupied; i++) {
                //     cout << vals[i] << " ";
                // }
                // cout << endl;
            }
        }

        cout << (ld)total / iters << endl;
    }
}