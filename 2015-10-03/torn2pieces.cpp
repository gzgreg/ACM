#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <string.h>
#include <map>
#include <list>

using namespace std;

int main(){
	int N; cin >> N;
	set<int> adj[100];
	for(int i = 0; i < 100; i++){
		set<int> empty;
		adj[i] = empty;
	}
	string curr; getline(cin, curr);
	map<string, int> dict;
	map<int, string> reverseDict;
	int j = 0;
	for(int i = 0; i < N; i++){
		getline(cin, curr);
		bool first = true;
		int idx;
		while(true){
			string token = curr.find(" ") != string::npos ? curr.substr(0, curr.find(" ")) : curr; 
			if(first){
				if(dict.count(token) == 0){
					dict.insert(make_pair(token, j));
					reverseDict.insert(make_pair(j, token));
					idx = j;
					j++;
				} else {
					idx = dict.at(token);
				}
				first = false;
			} else {
				if(dict.count(token) == 0){
					dict.insert(make_pair(token, j));
					reverseDict.insert(make_pair(j, token));
					adj[idx].insert(j);
					adj[j].insert(idx);
					j++;
				} else {
					adj[idx].insert(dict.at(token));
					adj[dict.at(token)].insert(idx);
				}
			}
			if(curr.find(" ") == string::npos) break;
			curr.erase(0, curr.find(" ")+1);
		}
	}
	int to, from;
	cin >> curr; 
	try {
		from = dict.at(curr);
	} catch(...) {
		cout << "no route found";
		return 0;
	} 
	cin >> curr; 
	try {
		to = dict.at(curr);
	} catch(...){
		cout << "no route found";
		return 0;
	}
	map<int, int> parent;
	map<int, int> weights;
	for(int i = 0; i < j; i++){
		if(i == from){
			weights.insert(make_pair(i, 0));
		} else {
			weights.insert(make_pair(i, 10000));
		}
		parent.insert(make_pair(i, -1));
	}
	queue<int> toVisit;
	toVisit.push(from);
	while(!toVisit.empty()){
		int curr = toVisit.front(); toVisit.pop();
		bool found = false;
		for(set<int>::iterator it=adj[curr].begin(); it!=adj[curr].end(); ++it){
			int edge = *it;
			if(weights.at(edge) > weights.at(curr) + 1){
				weights.at(edge) = weights.at(curr) + 1;
				parent.at(edge) = curr;
				toVisit.push(edge);
			}
			if(edge == to){
				found = true;
				break;
			}
		}
		if(found) break;
	}
	if(weights.at(to) == 10000){
		cout << "no route found" << endl;
	} else {
		list<int> route;
		int currVert = to;
		int i = 0;
		while(parent.at(currVert) != -1){
			route.push_front(currVert);
			currVert = parent.at(currVert);
		}
		route.push_front(currVert);

		for (std::list<int>::iterator it=route.begin(); it != route.end(); ++it){
			cout << reverseDict.at(*it) << " ";
		}
	}

	return 0;
}