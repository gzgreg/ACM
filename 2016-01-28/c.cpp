#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	long long n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	vector<pair<long long, long long> > flowers;
	for(long long i = 0; i < n; i++){
		long long x, y; cin >> x >> y;
		flowers.push_back(make_pair(x, y));
	}

	vector<pair<long long, long long> > ffff;
	long long (*f)(long long, long long, long long, long long) = [](long long a, long long b, long long c, long long d) { return (a - b) * (a - b) + (c - d) * (c - d); };
	for (auto i : flowers)
	{
		ffff.push_back(make_pair(f(i.first, x1, i.second, y1), f(i.first, x2, i.second, y2)));
	}

	long long opt = numeric_limits<long long>::max();
	for (auto i : ffff)
	{
		long long t = i.first;
		long long r = 0;
		for (auto j : ffff)
		{
			if (j == i) continue;
			if (j.first > t && j.second > r) r = j.second;
		}
		if (t + r < opt) opt = t + r;
	}
	for (auto i : ffff)
	{
		long long t = i.second;
		long long r = 0;
		for (auto j : ffff)
		{
			if (j == i) continue;
			if (j.second > t && j.first > r) r = j.first;
		}
		if (t + r < opt) opt = t + r;
	}

	cout << opt << endl;

	return 0;
}