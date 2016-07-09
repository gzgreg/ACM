#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> seq;
	vector<pair<int, int> > s;
	bool inS = true;
	int maxSeqLen = 0;
	int currSLen = 0;
	int currSeqLen = 0;
	int startSeq = false;
	int startVal;
	int val;
	for(int i = 0; i < n; i++){
		int curr; cin >> curr;
		if(inS){
			if(i == 0){
				currSLen++;
				val = curr;
				continue;
			} else if(val != curr || i == n-1){
				inS = false;
				if(i == n-1) currSLen++;
				if(i == 1){
					currSLen = 0;
					currSeqLen = 2;
					startSeq = true;
					startVal = val;
				} else {
					s.push_back(make_pair(val, currSLen));
					currSLen = 0;
					currSeqLen++;
				}
				
			} else {
				currSLen++;
			}
			val = curr;
		} else {
			if(val != curr && i != n-1){
				currSeqLen++;
			} else {
				inS = true;
				if(currSeqLen > 1){
					seq.push_back(currSeqLen);
					if(currSeqLen > maxSeqLen){
						maxSeqLen = currSeqLen;
					}
					currSeqLen = 0;
					currSLen++;
				} else {
					seq.push_back(2);
					if(s.size() > 0) s.back() = *s.back() - 1;
					currSLen++;
				}
				if(i == n-1){
					s.push_back(make_pair(curr, currSLen));
				}
			}
		}
		val = curr;
	}
	cout << (maxSeqLen - 1) / 2  << " " << s.size() << " " << seq.size() << endl;
	if(!startSeq){
		for(int i = 0; i < s.size(); i++){
			int val = s[i].first;
			for(int j = 0; j < s[i].second; j++){
				cout << s[i].first << " ";
			}
			cout << "|";
			if(i < seq.size()){
				int currLen = seq[i];
				if(currLen % 2 == 0){
					for(int j = 0; j < currLen / 2; j++){
						cout << val << " ";
					}
					for(int j = 0; j < currLen / 2; j++){
						cout << (val+1)%2 << " ";
					}
				} else {
					for(int j = 0; j < currLen; j++){
						cout << val << " ";
					}
				}
				cout << "|";
			}
			
		}
	} else {
		int val = startVal;
		for(int i = 0; i < s.size(); i++){
			int currLen = seq[i];
			if(currLen % 2 == 0){
				for(int j = 0; j < currLen / 2; j++){
					cout << val << " ";
				}
				for(int j = 0; j < currLen / 2; j++){
					cout << (val+1)%2 << " ";
				}
			} else {
				for(int j = 0; j < currLen; j++){
					cout << val << " ";
				}
			}
			cout << "|";

			val = s[i].first;
			for(int j = 0; j < s[i].second; j++){
				cout << s[i].first << " ";
			}
			cout << "|";
		}
	}
	
	return 0;
}