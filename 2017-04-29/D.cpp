#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool adjmat[10000][10000], seen[10000]; int matchL[10000], matchR[10000], m, n;
bool bpm(int u) { // Can we find augmenting path starting from u
  for(int v = 0; v < n; v++) if(adjmat[u][v] && !seen[v]) { seen[v] = true;
    if(matchR[v] == -1 || bpm(matchR[v]) ) { matchL[u] = v, matchR[v] = u;
      return true; } }
  return false; }
void main3() { memset(matchL,-1,sizeof matchL); memset(matchR,-1,sizeof matchR);
  // Read input, set m (left part), n (right part), and populate adjmat here
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    memset(seen, 0, sizeof seen);
    if( bpm(i) ) cnt++; // matchL[i] is the match
  } }

int main(){
	ios::sync_with_stdio(0);
	int N, M; cin >> N >> M;
	m = N; n = N;
	memset(adjmat, false, sizeof adjmat);
	for(int i = 0; i < M; i++) {
		int A, B; cin >> A >> B;

		adjmat[B][A] =true;
	}

	main3();

	for(int i = 0; i < N; i++) {
		if(matchL[i] == -1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}