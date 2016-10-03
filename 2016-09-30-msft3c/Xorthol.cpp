#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define endl '\n'

int main(){
	ios::sync_with_stdio(0);

	vector<string> colors;

	string s;
	while(cin >> s) {
		colors.push_back(s);
	}
	
	vector<string> outColors;
	outColors.push_back(colors[0]);

	for(int i = 1; i < colors.size() - 1; i++) {
		string currColor = colors[i];
		string mixer = outColors[outColors.size() - 1];
		if(mixer == "red") {
			if(currColor == "red") {
				outColors.push_back("blank");
			} else if (currColor == "purple") {
				outColors.push_back("blue");
			} else if (currColor == "orange") {
				outColors.push_back("yellow");
			}
		} else if (mixer == "blue") {
			if(currColor == "blue") {
				outColors.push_back("blank");
			} else if (currColor == "purple") {
				outColors.push_back("red");
			} else if (currColor == "green") {
				outColors.push_back("yellow");
			}
		} else if (mixer == "yellow") {
			if(currColor == "yellow") {
				outColors.push_back("blank");
			} else if (currColor == "green") {
				outColors.push_back("blue");
			} else if (currColor == "orange") {
				outColors.push_back("red");
			}
		} else if (mixer == "blank") {
			if(currColor == "blank") {
				outColors.push_back("blank");
			} else if (currColor == "blue") {
				outColors.push_back("blue");
			} else if (currColor == "red") {
				outColors.push_back("red");
			} else if (currColor == "yellow") {
				outColors.push_back("yellow");
			}
		}
	}

	for(string color : outColors) {
		cout << color << " ";
	}
	cout << endl;
	return 0;
}