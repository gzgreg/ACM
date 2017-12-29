#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> startPattern = {".#.", "..#", "###"};

vector<string> rotate(vector<string> in) {
	vector<string> out (in.size(), string(in.size(), 'a'));
	for(int i = 0; i < in.size(); i++) {
		for(int j = 0; j < in.size(); j++) {
			out[j][in.size() - i - 1] = in[i][j];
		}
	}
	return out;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<vector<string>, vector<string>> enhance;

	string s;
	while(getline(cin, s)) {
		stringstream str(s);

		string in, junk, out;
		str >> in >> junk >> out;
		vector<string> inVal, outVal;
		if(in.size() == 5) {
			inVal.push_back(in.substr(0, 2));
			inVal.push_back(in.substr(3, 2));
		} else {
			inVal.push_back(in.substr(0, 3));
			inVal.push_back(in.substr(4, 3));
			inVal.push_back(in.substr(8, 3));
		}

		if(out.size() == 11) {
			outVal.push_back(out.substr(0, 3));
			outVal.push_back(out.substr(4, 3));
			outVal.push_back(out.substr(8, 3));
		} else {
			outVal.push_back(out.substr(0, 4));
			outVal.push_back(out.substr(5, 4));
			outVal.push_back(out.substr(10, 4));
			outVal.push_back(out.substr(15, 4));
		}
		enhance[inVal] = outVal;
		for(int i = 0; i < 3; i++) {
			inVal = rotate(inVal);
			enhance[inVal] = outVal;
			reverse(inVal.begin(), inVal.end());
			enhance[inVal] = outVal;
			reverse(inVal.begin(), inVal.end());
		}
		for(int i = 0; i < inVal.size(); i++) {
			reverse(inVal[i].begin(), inVal[i].end());
		}
		for(int i = 0; i < 3; i++) {
			inVal = rotate(inVal);
			enhance[inVal] = outVal;
		}
	}
	// for(auto cur : enhance) {
	// 	for(auto val : cur.first) {
	// 		cout << val << endl;
	// 	}
	// 	cout << endl;
	// }
	auto curPattern = startPattern;
	for(int it = 0; it < 18; it++) {
		// for(auto cur : curPattern) {
		// 	cout << cur << endl;
		// }
		// cout << endl;
		if(curPattern.size() % 2 == 0) {
			vector<string> newPattern(curPattern.size() * 3 / 2, string(curPattern.size() * 3 / 2, 'a'));
			for(int i = 0; i < curPattern.size() / 2; i++) {
				for(int j = 0; j < curPattern.size() / 2; j++) {
					vector<string> cur;
					cur.push_back(curPattern[2*i].substr(2*j, 2));
					cur.push_back(curPattern[2*i + 1].substr(2*j, 2));

					newPattern[3*i].replace(3*j, 3, enhance[cur][0]);
					newPattern[3*i+1].replace(3*j, 3, enhance[cur][1]);
					newPattern[3*i+2].replace(3*j, 3, enhance[cur][2]);
				}
			}

		curPattern = newPattern;
		} else {
			vector<string> newPattern(curPattern.size() * 4 / 3, string(curPattern.size() * 4 / 3, 'a'));
			for(int i = 0; i < curPattern.size() / 3; i++) {
				for(int j = 0; j < curPattern.size() / 3; j++) {
					vector<string> cur;
					cur.push_back(curPattern[3*i].substr(3*j, 3));
					cur.push_back(curPattern[3*i + 1].substr(3*j, 3));
					cur.push_back(curPattern[3*i + 2].substr(3*j, 3));


					// for(auto val : cur) {
					// 	cout << val << endl;
					// }
					// cout << endl;

					// cout << enhance.count(cur) << endl;


					newPattern[4*i].replace(4*j, 4, enhance[cur][0]);
					newPattern[4*i+1].replace(4*j, 4, enhance[cur][1]);
					newPattern[4*i+2].replace(4*j, 4, enhance[cur][2]);
					newPattern[4*i+3].replace(4*j, 4, enhance[cur][3]);
				}
			}

		curPattern = newPattern;
		}
	}
	int ans = 0;
	for(auto cur : curPattern) {
		for(auto val : cur) {
			ans += val == '#';
		}
	}

	cout << ans << endl;
	
	return 0;
}