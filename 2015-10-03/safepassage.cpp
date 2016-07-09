#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <cstring>

using namespace std;

int solve(int);
int times[20], dp[20];

int main(){
	int N; cin >> N;
	for(int i = 0; i < N; i++){
		cin >> times[i];
	}
	sort(times, times+N);
	memset(dp, -1, sizeof dp);
	cout << solve(N);	
	// queue<pair<map<int, bool>, long> > bfsq;
	// map<int, bool> initial;
	// for(int i = 0; i < N; i++){
	// 	initial.insert(pair<int, bool>(i, true));
	// }

	// bfsq.push(make_pair(initial, 0));
	// long minTime = 10000000;

	// map<int, int> hashMap;
	// int sum = 0;
	// int maxx = 0;
	// for(int i = 0; i < N; i++){
	// 	if(times[i] > maxx) maxx = times[i];
	// 	sum += times[i];
	// }
	// sum -= maxx;
	// sum = sum*2;
	// while(!bfsq.empty()){
	// 	pair<map<int, bool>, long> curr = bfsq.front();
	// 	bfsq.pop();
	// 	map<int, bool> people; people = curr.first;
	// 	long currTime = curr.second;

	// 	int hash = 0;
	// 	for(int i = 0; i < N; i++){
	// 		if(people.at(i)) hash += pow(2, i);
	// 	}

	// 	if(hashMap.count(hash) == 0){
	// 		hashMap.insert(make_pair(hash, currTime));
	// 	} else {
	// 		if(hashMap.at(hash) >= currTime){
	// 			hashMap.at(hash) = currTime;
	// 		} else {
	// 			continue;
	// 		}
	// 	}

	// 	for(int i = 0; i < N; i++){
	// 		for(int j = i+1; j < N; j++){
	// 			map<int, bool> newPeople (people);
	// 			long newTime = currTime;
	// 			if(people.at(i) && people.at(j)){

	// 				newPeople.at(i) = false; newPeople.at(j) = false;
	// 				newTime += max(times[i], times[j]);

	// 				int returner;
	// 				int returnTime = 1000000;
	// 				bool allArrived = true;
	// 				for(int k = 0; k < N; k++){
	// 					if(!newPeople.at(k) && times[k] < returnTime){
	// 						returnTime = times[k];
	// 						returner = k;
	// 					} else if(newPeople.at(k)){
	// 						allArrived = false;
	// 					}
	// 				}
	// 				if(allArrived){
	// 					if(newTime < minTime) minTime = newTime;
	// 					break;
	// 				} else {
	// 					newPeople.at(returner) = true;
	// 					newTime += returnTime;
	// 				}
	// 				if(newTime > sum) continue;
	// 				// for(int k = 0; k < N; k++){
	// 				// 	if(newPeople.at(k)){
	// 				// 		cout << k << " ";
	// 				// 	}
	// 				// }
	// 				// cout << newTime << endl;

	// 				bfsq.push(make_pair(newPeople, newTime));
	// 			}
	// 		}
	// 	}
	// }
	// cout << minTime;
	// return 0;
}

int solve(int size){
	if(size == 1){
		return times[0];
	} else if(size == 2){
		return times[1];
	} else if(dp[size] != -1){
		return dp[size];
	}
	dp[size] = min(solve(size - 1) + times[0] + times[size - 1], solve(size - 2) + times[0] + 2*times[1] + times[size - 1]);
	return dp[size];
}