#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, P; cin >> N >> M >> P;

	vector<string> names;
	for(int i = 0; i < N; i++) {
		string s; cin >> s; names.push_back(s);
	}

	map<string, pii> score;
	map<string, vector<int>> penalty;

	multiset<pii> scores;

	for(int i = 0; i < N; i++) {
		score[names[i]] = {0, 0};
		scores.insert({0, 0});
		penalty[names[i]] = vector<int>(P, 0);
	}
	int lastLeadTime = 0;
	bool curLeading = true;

	int leadTime = 0;
	for(int i = 0; i < M; i++) {
		string s; char val; int t; string ans;
		cin >> s >> val >> t >> ans;

		if(ans[0] == 'N') {
			penalty[s][val - 'A'] += 20;
			continue;
		}
		pii curScore = score[s];

		scores.erase(scores.find(curScore));
		curScore.first--;
		curScore.second += t;
		curScore.second += penalty[s][val - 'A'];
		scores.insert(curScore);
		score[s] = curScore;

		if(curLeading) {
			if(*scores.begin() != score[names[0]]) {
				leadTime += t - lastLeadTime;
				curLeading = false;
			}
		} else {
			if(*scores.begin() == score[names[0]]) {
				lastLeadTime = t;
				curLeading = true;
			}
		}
	}

	if(curLeading) {
		leadTime += 300 - lastLeadTime;
	}

	cout << leadTime << endl;

	return 0;
}