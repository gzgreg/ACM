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

  int n; cin >> n;
  vector<ll> heights;
  for(int i = 0; i < n; i++) {
    int cur; cin >> cur; heights.push_back(cur);
  }

  vector<ll> numLevels(n);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= heights[i]; j++) {
      if(j != 0 && heights[i - j] >= heights[i] - j) break;
      numLevels[i-j] = heights[i] - j + 1;
      cout << i << " " << j << endl;
    }
  }

  ll curLevel = 0;
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    curLevel = max(curLevel, numLevels[i]);
    ans += curLevel - heights[i] - 1;
  }

  cout << ans << endl; 

  return 0;
}