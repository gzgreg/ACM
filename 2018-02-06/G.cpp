#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> p;
  if (false){
    for(int i=0;i<N;i++){
      p.push_back(1e8);
    }
  }
  else {
    for(int i = 0; i < N; i++) {
      int pi; cin >> pi; p.push_back(pi);
    }
  }

  sort(p.begin(), p.end());

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({p[0], 0});
  for(int i = 0; i < K-1; i++) {
  	auto cur = pq.top(); pq.pop();
  	if(cur.second < N-1) {
  		pq.push({cur.first + p[cur.second + 1], cur.second + 1});
  		pq.push({cur.first - p[cur.second] + p[cur.second + 1], cur.second + 1});
  	}

  }
  cout << pq.top().first << endl;
}