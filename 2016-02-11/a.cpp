#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	long long T; cin >> T;

	while(T--){
		long long N, K; cin >> N >> K;
		vector<long long> row;
		long long idx = 0;
		for(long long i = 0; i < N; i++){
			char curr; cin >> curr;
			if(curr == '1') row.push_back(idx);
			idx++;
		}
		if(row.size() < K){
			cout << 0 << endl;
			continue;
		}
		if(K == 0){
			long long total = 0;
			if(row.size() == 0){
				cout << idx * (idx + 1) / 2 << endl;
				continue;
			}
			for(int i = 0; i <= row.size(); i++){
				long long gap = i == 0 ? row[i] : i == row.size() ? idx - row[i-1]  - 1 : row[i] - row[i - 1] - 1;
				total += gap * (gap + 1) / 2;
			}
			cout << total << endl;
			continue;
		}
		long long total = 0;
		for(long long i = K-1; i < row.size(); i++){
			long long first = row[i - K + 1], last = row[i];
			long long prefix = i == K-1 ? first : first - row[i - K] - 1;
			long long suffix = i == row.size() - 1 ? idx - last - 1 : row[i + 1] - last - 1;
			total += (prefix + 1) * (suffix + 1);
		}
		cout << total << endl;
	}

	return 0;
}