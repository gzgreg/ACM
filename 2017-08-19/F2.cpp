#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5;

int n, m;
struct no
{
	int id;
	int le;
	int ri;
}node1[maxn], node2[maxn];
int val[maxn];
bool cmp1(const no&a, const no &b)
{
	return a.le<b.le;
}
bool cmp2(const no&a, const no &b)
{
	return a.ri<b.ri;
}
int num[maxn];
set<int>s;
void solve()
{
	s.clear();
	memset(num, 0, sizeof(num));
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, in, k;
		cin >> x >> in >> k;
		val[i] = in;
		node1[i].le = x - k;
		node1[i].ri = x + k;
		node1[i].id = i;
		node2[i].le = x - k;
		node2[i].ri = x + k;
		node2[i].id = i;
	}
	sort(node1 + 1, node1 + m + 1, cmp1);
	sort(node2 + 1, node2 + m + 1, cmp2);
	int c1 = 1, c2 = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		while (c1 <= m&&node1[c1].le <= i)
		{
			num[val[node1[c1].id]]++;
			s.insert(node1[c1].id);
			c1++;
		}
		while (c2<=m&&node2[c2].ri<i)
		{
			num[val[node2[c2].id]]--;
			s.erase(node2[c2].id);
			c2++;
		}
		if (s.empty())ans++;
		else
		{
			int k = *s.rbegin();
			if (num[val[k]] > 1)ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while(T--) {
		solve();
	}
	
	return 0;
}