#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	char curr;
	bool greater = false;
	int diff = 0;
	vector<int> out;
	while(cin >> curr){
		int val = curr - '0';
		if(!greater){
			if(val < 4){
				out.push_back(4);
				diff++;
				greater = true;
			} else if(val == 4) {
				out.push_back(4);
				diff++;
			} else if(val < 7){
				out.push_back(7);
				diff--;
				greater = true;
			} else if(val == 7){
				out.push_back(7);
				diff--;
			} else {
				if(out.size() == 0){
					out.push_back(4);
					out.push_back(4);
					diff++;
				} else {
					for(int i = out.size() - 1; i >= 0; i--){
						if(out[i] == 4){
							out[i] = 7;
							diff--;
							out.push_back(4);
							break;
						}
						if(i == 0){
							out.insert(out.begin(), 2, 4);
							diff++;
						}
					}
				}
				
				greater = true;
			}
		} else {
			out.push_back(4);
			diff++;
		}
	}

	bool odd = out.size() % 2;
	if(odd){
		for(int i = 0; i < (out.size() + 1) / 2; i++){
			cout << 4;
		}
		for(int i = 0; i < (out.size() + 1) / 2; i++){
			cout << 7;
		}
		cout << endl;
		return 0;
	}
	if(diff > 0){ //more 4s
		for(int i = out.size() - 1; i >= 0; i--){
			if(out[i] == 4){
				out[i] = 7;
				diff-= 2;
			}
			if(diff <= 0) break;
		}
	} else if(diff < 0){
		bool swap = true;
		bool success = false;
		for(int i = out.size() - 1; i >= 2; i--){
			if(swap){
				if(out[i] == 7){
					out[i] = 4;
					diff += 2;
					if(diff >= 0) swap = false;
				}
				if(swap) continue;
			}
			if(out[i-1] == 7 && out[i-2] == 4){
				out[i-1] = 4;
				out[i - 2] = 7;
				success = true;
				break;
			} else {
				if(out[i-1] == 7){
					out[i-1] = 4;
					diff += 2;
				}
			}
		}
		// if(out.size() > 50000 && out[0] == 4 && out[1] == 7 && out[2] == 4){
		// 	cout << diff << " " << out.size() << " ";
		// }
		for(int i = out.size() - 1; i >= 2; i--){
			if(diff <= 0) break;
			if(out[i] == 4){
				out[i] = 7;
				diff -= 2;
			}
		}
		
		if(!success){
			for(int i = 0; i < (out.size() + 2) / 2; i++){
				cout << 4;
			}
			for(int i = 0; i < (out.size() + 2) / 2; i++){
				cout << 7;
			}
			cout << endl;
			return 0;
		}
	}

	for(int i = 0; i < out.size(); i++){
		cout << out[i];
	}
	cout << endl;

	return 0;
}