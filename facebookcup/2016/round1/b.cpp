#include <bits/stdc++.h>

using namespace std;

class comp{
public:
	bool operator() (pair<long long, long long> lhs, pair<long long, long long> rhs){
		return lhs.first > rhs.first;
	}
};

int main(){
	ios::sync_with_stdio(0);

	long long T; cin >> T;
	for(long long i = 1; i <= T; i++){
		long long L, N, M, D; cin >> L >> N >> M >> D;
		vector<long long> Wi;
		priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, comp > times;
		for(long long j = 0; j < N; j++){
			long long curr; cin >> curr;
			Wi.push_back(curr);
			
		}	
		sort(Wi.begin(), Wi.end());
		for(long long j = 0; j < N; j++){
			times.push(make_pair(Wi[j], j));
		}
		long long freeD = M;
		vector<long long> dTimes;
		for(long long j = 0; j < L; j++){
			pair<long long, long long> curr = times.top();
			times.pop();
			dTimes.push_back(curr.first);
			times.push(make_pair(curr.first + Wi[curr.second], curr.second));
		}

		priority_queue<long long, vector<long long>, greater<long long> > dEnds;
		long long max = 0;
		for(long long j = 0; j < L; j++){
			if(freeD > 0){
				freeD--;
				dEnds.push(dTimes[j] + D);
			} else {
				long long curr = dEnds.top();
				dEnds.pop();
				max = curr;
				dEnds.push(curr + D);
			}
		}
		while(!dEnds.empty()){
			max = dEnds.top(); dEnds.pop();
		}

		cout << "Case #" << i << ": " << max << endl;
	}

	return 0;
}