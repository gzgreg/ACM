#include <bits/stdc++.h>

using namespace std;
vector<int> config (1<<26 + 1, 1000);

void generateConfig(){
	queue<pair<long, int> > bfsq;
	bfsq.push(make_pair(8191, 0));
	while(!bfsq.empty()){
		pair<long, int> curr = bfsq.front(); bfsq.pop();
		long val = curr.first;
		//cout << val << " ";
		if(config[val] <= curr.second){
			continue;
		}
		config[val] = curr.second;
		long rotTop1 = ((val & 67092480) >> 1) + ((val & 8192) << 12) + (val & 8191);
		long rotTop2 = ((val & 33546240) << 1) + ((val & 33554432) >> 12) + (val & 8191);
		long rotBot1 = (val & 67100672) + ((val & 4095) << 1) + ((val & 4096) >> 12);
		long rotBot2 = (val & 67100672) + ((val & 8190) >> 1) + ((val & 1) << 12);
		long mid = (val & 67043328) + ((val & 32768) >> 5) + ((val & 16384) >> 3) + ((val & 8192) >> 1) + ((val & 4096) << 1) + ((val & 2048) << 3) + ((val & 1024) << 5) + ((val & 1023));
		//cout << rotTop1 << " " << rotTop2 << " " << rotBot1 << " " << rotBot2 << " " << mid << endl;
		//cout << ((val & 67092480) >> 1) <<  " " <<  ((val & 8192) << 12)  << " " << (val & 8191) << " " << ((val & 67092480) >> 1) + ((val & 8192) << 12) + (val & 8191);
		bfsq.push(make_pair(rotTop1, curr.second));
		bfsq.push(make_pair(rotTop2, curr.second));
		bfsq.push(make_pair(rotBot1, curr.second));
		bfsq.push(make_pair(rotBot2, curr.second));
		bfsq.push(make_pair(mid, curr.second + 1));
	}
}

int main(){
	ios::sync_with_stdio(0);
	generateConfig();
	string s;
	while(cin >> s){
		long val = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[s.size() - i - 1] == 'y'){
				val += 1 << i;
			}
		}
		cout << config[val] << endl;
	}
	return 0;
}