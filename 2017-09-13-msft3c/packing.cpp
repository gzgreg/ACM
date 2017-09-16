#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;



std::string & ltrim(std::string & str)
{
  auto it2 =  std::find_if( str.begin() , str.end() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( str.begin() , it2);
  return str;   
}

std::string & rtrim(std::string & str)
{
  auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
  str.erase( it1.base() , str.end() );
  return str;   
}

std::string & trim(std::string & str)
{
   return ltrim(rtrim(str));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s; cin >> s;
	string num = "";
	int m;
	bool flag;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			num.push_back(s[i]);
		} else if (s[i] == ':') {
			m = stoi(num);
		} else {
			if(s[i] == 'T') {
				flag = true;
			} else {
				flag = false;
			}
			break;
		}
	}
	int totInitialNodes = 0;
	int totEmpties = 0;
	vector<string> strings;
	getline(cin, s);
	while(getline(cin, s)) {
		s = trim(s);
		if(s == "]") {
			totInitialNodes++;
		} else if (s == "[") {

		} else {
			if(s == "") {
				totEmpties++;
				if(!flag) {
					strings.push_back(s);
				}
			} else {
				strings.push_back(trim(s));
			}
		}
	}
	totInitialNodes--;
	cout << (strings.size()+m-1) / m << endl;
	cout << -totInitialNodes + ((int)strings.size()+m-1) / m << endl;
	if(flag) {
		cout << -totEmpties + (m - strings.size() % m)<< endl;
		cout << (m - strings.size() % m) << endl;
	} else {
		cout << (m - strings.size() % m) << endl;
		cout << totEmpties + (m - strings.size() % m)<< endl;
	}
	cout << "[" << endl;
	for(int i = 0; i < (strings.size()+m-1) / m; i++) {
		cout << "[" << endl;
		for(int j = 0; j < m; j++) {
			cout << strings[j + i*m] << endl;
		}
		cout << "]" << endl;
	}
	cout << "]";
	cout << endl;
	return 0;
}