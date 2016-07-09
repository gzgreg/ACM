#include <bits/stdc++.h>

using namespace std;

string sortAlpha(string);

int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		vector<string> ballots;
		map<char, int> count;
		int num; cin >> num;
		for(int j = 0; j < num; j++){
			string s; cin >> s;
			for(int k = 0; k < s.size(); k++){
				try{
					count.at(s[k]);
				} catch(...){
					count.insert(make_pair(s[k], 0));
				}
			}
			ballots.push_back(s);
			count.at(s[0])++;
		}
		int max = 0;
		int min = 1000000;
		string removed;
		char maxMan;
		for(map<char, int>::iterator it = count.begin(); it != count.end(); it++){
			if(it->second > max){
				max = it->second;
				maxMan = it->first;
			} 
			if(it->second < min){
				min = it->second;
				removed = it->first;
			} else if(it->second == min){
				removed += it->first;
			}
		}
		if(max > num/2){
			cout << maxMan << endl;
			continue;
		} else {
			cout << removed << " -> ";
			bool allZero = false;
			while(!allZero){
				allZero = true;
				max = 0;
				min = 1000000;
				for(map<char, int>::iterator it = count.begin(); it != count.end(); it++){
					it->second = 0;
				}
				for(int j = 0; j < ballots.size(); j++){
					string s = ballots[j];
					while(removed.find(s[0]) != string::npos && s.size() != 0){
						s.replace(0, 1, "");
					}
					if(s.size() != 0){
						count.at(s[0])++;
					} else {
						ballots.erase(ballots.begin() + j);
						j--;
					}
					//cout << s << endl;
				}
				string newRemoved;
				for(map<char, int>::iterator it = count.begin(); it != count.end(); it++){
					//cout << it->first << " " << it->second << endl;
					if(removed.find(it->first) != string::npos) continue;
					if(it->second > max){
						max = it->second;
						maxMan = it->first;
					}
					if(it->second < min){
						min = it->second;
						newRemoved = it->first;
					} else if(it->second == min){
						newRemoved += it->first;
					}
					if(it->second != 0) allZero = false;
				}
				removed += newRemoved;
				if(max > ballots.size()/2){
					cout << maxMan << endl;
					break;
				} else{
					if(allZero) break;
					cout << sortAlpha(newRemoved) << " -> ";
				}
			}
			if(allZero) cout << "no winner" << endl;
		}
	}
	return 0;
}

string sortAlpha(string str){
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ret = "";
	for(int i = 0; i < abc.size(); i++){
		if(str.find(abc[i]) != string::npos){
			ret += abc[i];
		}
	}
	return ret;
}