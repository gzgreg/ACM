#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int N; cin >> N;

	vector<pair<string, string> > names;

	for(int i = 0; i < N; i++){
		string first, last; cin >> first >> last;
		names.push_back(make_pair(last, first));
	}

	sort(names.begin(), names.end());

	map<pair<string, string>, int> rev;

	for(int i = 0; i < N; i++){
		rev.insert(make_pair(names[i], i));
	}

	int Q; cin >> Q;

	for(int i = 0; i < Q; i++){
		string first, last; cin >> first >> last;

		int loc = rev.at(make_pair(last, first));
		pair<string, string> name1, name2;
		if(loc % 3 == 0){
			name1 = names[loc+1];
			name2 = names[loc+2];
		} else if(loc % 3 == 1){
			name1 = names[loc-1];
			name2 = names[loc+1];
		} else {
			name1 = names[loc-2];
			name2 = names[loc-1];
		}

		cout << name1.second << " " << name1.first << endl << name2.second << " " << name2.first << endl;
	}

	return 0;
}