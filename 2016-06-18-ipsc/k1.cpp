#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long median(long long a, long long b, long long c) {
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);
    return b;
}

long long f1(long long n) {
    return (-n*n*n + 947*n*n + 20647474747LL*n + 47) / 20000000047LL;
}

long long f2(long long n) {
    return (-n*n + 2084747*n + 47) / 2494747;
}

long long f3(long long n) {
    return (-n*n*n + 19647*n*n + 23254474747LL*n - 25384747*(n%97)*n + 47 ) / 25382294747LL;
}
void sort_helper(vector<unsigned> &A, int lo, int hi) {
    long long n = hi - lo;
    if (n <= 2) {
        if (n == 2 && A[lo] > A[lo+1]) swap( A[lo], A[lo+1] );
        return;
    }
    long long a = median( 0, n-1, f1(n) );
    long long b = median( 0, n-1, f2(n) );
    long long c = median( 0, n-1, f3(n) );
    //cout << lo << " " << hi << endl;
    sort_helper( A, lo, lo+a );
    sort_helper( A, hi-b, hi );
    sort_helper( A, lo, lo+c );
}

// this is the main function
void k1_sort(vector<unsigned> &A) {
    sort_helper( A, 0, A.size() );
}

int main() {
    vector<unsigned> ans;
    vector<unsigned> orig;
    // for(int i = 0; i < 9; i++) {
    //     orig.push_back(i);
    // }
    // int i = 0;
    // do {
    //     cout << i++ << " ";
    //     vector<unsigned> a(orig);
        
    //     // int curr; cin >> curr;
    //     // while(curr != -1) {
    //     //     a.push_back(curr);
    //     //     cin >> curr;
    //     // }
        
    //     vector<unsigned> b(a);
    //     k1_sort(a);
    //     bool found = false;
    //     sort(b.begin(), b.end());
    //     for(int i = 0; i < a.size(); i++) {
    //         if(a[i] != b[i]){
    //             found = true;
    //             break;
    //         }
    //     }
    //     if(found){
    //         for(int i = 0; i < ans.size(); i++) {
    //             cout << orig[i] << " ";
    //         }
    //     }
        
    // } while(next_permutation(orig.begin(), orig.end()));

    for(int i = 2; i < 10000000; i++) {
        if(f1(i) + f2(i) + f3(i) < 2*i) {
            cout << i << endl;
            cout << f1(i) << " " << f2(i) << " " << f3(i) << endl;
            cout << f1(i-1) << " " << f2(i-1) << " " << f3(i-1) << endl;
            break;
        }
    }
    // cout << 133859 << endl;
    // for(int i = 0; i < 133859; i++) {
    //     cout << rand() << " ";
    // }

    

    cout << endl;
}
