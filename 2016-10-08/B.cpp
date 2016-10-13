#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<vd> vvd;

#define endl '\n'

#define ISZERO(x) (x == 0)
#define ISPOS(x) ((x) > EPS)
const ld EPS = 1e-9;
void pivot(vvd& A, int r, int c) { // A is A|b
  int m = A.size(), n = A[0].size(); ld tmp = A[r][c];
  for (int i = 0; i < n; ++i) A[r][i]/=tmp;
  for (int i = 0; i < m; ++i) if (i != r) { ld k = A[i][c];
    for(int j = 0; j < n; ++j) A[i][j] -= A[r][j]*k; } }
bool gaussian(vvd& A) { int m=A.size(), n=A[0].size()-1; vector<bool> used(m,0);
  for (int c = 0; c < n; ++c) for (int r = 0; r < m; ++r)
    if (!used[r] && !ISZERO(A[r][c]) ) { pivot(A, r, c); used[r] = true; }
  for (int r = 0; r < m; ++r) if(!used[r] && !ISZERO(A[r].back())) return false;
  return true; }

int main(){
	ios::sync_with_stdio(0);
	int p, q;
	cin >> p >> q;
	do {
		
		int R=0, C=0, S=0;
		bool inIndent = true;
		ld currR = 0, currC = 0, currS = 0;
		vvd sys;
		for(int i = 0; i < p; i++) {
			string s; cin >> s;
			int indentSize = 0;
			inIndent = true;
			for(char curr : s) {
				if(curr == '.' && inIndent) {
					indentSize++;
				} else if (inIndent) {
					inIndent = false;
					vd nums;
					nums.push_back(currR);
					nums.push_back(currC);
					nums.push_back(currS);
					nums.push_back(indentSize);
					sys.push_back(nums);
				}
				if(curr == '(') {
					currR = currR + 1;
				} else if (curr == '[') {
					currS++;
				} else if (curr == '{') {
					currC++;
				} else if (curr == ')') {
					currR--;
				} else if (curr == ']') {
					currS--;
				} else if (curr == '}') {
					currC--;
				}
			}
		}

		vector<vector<int>> good;

		for(int i = 1; i <= 20; i++) {
			for(int j = 1; j <= 20; j++) {
				for(int k = 1; k <= 20; k++) {
					bool found = true;
					for(vd row : sys) {
						if(row[0]*i + row[1]*j + row[2]*k != row[3]) {
							found = false;
							continue;
						}
					}
					if(!found) continue;
					good.push_back({i, j, k});
				}
			}
		}
		currR = 0; currC = 0; currS = 0;
		int indentSize = 0;
		for(int i = 0; i < q; i++) {
			cout << indentSize << " ";
			string s; cin >> s;
			for(char curr : s) {
				if(curr == '(') {
					currR = currR + 1;
				} else if (curr == '[') {
					currS++;
				} else if (curr == '{') {
					currC++;
				} else if (curr == ')') {
					currR--;
				} else if (curr == ']') {
					currS--;
				} else if (curr == '}') {
					currC--;
				}
			}
			set<int> ans;
			for(vector<int> vals : good) {
				ans.insert(currR*vals[0] + currC*vals[1] + currS*vals[2]);
			}
			if(ans.size() == 1) {
				indentSize = *(ans.begin());
			} else {
				indentSize = -1;
			}
		}
		cout << endl;
		cin >> p >> q;
	} while(p || q);
	
	return 0;
}