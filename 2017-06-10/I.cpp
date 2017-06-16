#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool cmp(double num1, double num2) {
	return abs(num1 - num2) < 1e-10;
}

double stddev(vector<double> nums, int m) {
	double tot = 0;
	for(int i = 0; i < nums.size(); i++) {
		tot += (nums[i] - m)*(nums[i] - m);
	}
	tot /= nums.size();
	return sqrt(tot);
}

double avg(vector<double> nums) {
	double tot = 0;
	for(int i = 0; i < nums.size(); i++) {
		tot += nums[i];
	}
	tot /= nums.size();
	return tot;
}

int main(){
	ios::sync_with_stdio(0);
	// freopen("stats.in", "r", stdin);
	// freopen("stats.out", "w", stdout);

	int t; cin >> t;
	cout << fixed << setprecision(8);
	while(t--) {
		int m, s, h; cin >> m >> s >> h;

		vector<double> nums; nums.push_back(h);
		for(int i = 0; i < 9; i++) {
			if(cmp(avg(nums), m) && cmp(stddev(nums, m), s)) {
				break;
			}
			double curr = avg(nums);
			double left = (m * (nums.size() + 2)) - (curr * nums.size());
			if(m > h) {
				nums.push_back(h);
				nums.push_back(min(100.0, left-h));
			} else {
				nums.push_back(max(0.0, left-h));
				nums.push_back(h);
			}

			if(cmp(avg(nums), m)) {
				double l = 0, r = min(nums[2*i + 1], 100 - nums[2*i + 2]);
				double origVal = nums[2*i + 1], origVal2 = nums[2*i + 2];
				while(r-l > 1e-10) {
					double mid = (l + r) / 2;
					double diff = (r - l) / 2;
					nums[2*i + 1] = origVal - mid;
					nums[2*i + 2] = origVal2 + mid;
					if(stddev(nums, m) > s) {
						r -= diff;
					} else {
						l += diff;
					}
				}
				if(cmp(stddev(nums, m), s)) break;
			}
		}
		if(cmp(avg(nums), m) && !cmp(stddev(nums, m), s)
			&& stddev(nums, m) < s) {
			sort(nums.begin(), nums.end());
			// split in upper half
			for(int i = 0, j = 8; i < j;) {
				double l = 0, r = min(nums[i + 10] - h, 100 - nums[18 - i]);
				double origVal = nums[i + 10], origVal2 = nums[18 - i];
				while(r-l > 1e-10) {
					double mid = (l + r) / 2;
					double diff = (r - l) / 2;
					nums[i + 10] = origVal - mid;
					nums[18 - i] = origVal2 + mid;
					if(stddev(nums, m) > s) {
						r -= diff;
					} else {
						l += diff;
					}
				}
				if(cmp(stddev(nums, m), s)) break;
				if(cmp(origVal2, 100)) {
					j--;
				} else {
					i++;
				}
			}
			// split in lower half
			for(int i = 0, j = 8; i < j;) {
				double l = 0, r = min(nums[i], h - nums[8 - i]);
				double origVal = nums[i], origVal2 = nums[8 - i];
				while(r-l > 1e-10) {
					double mid = (l + r) / 2;
					double diff = (r - l) / 2;
					nums[i] = origVal - mid;
					nums[8 - i] = origVal2 + mid;
					if(stddev(nums, m) > s) {
						r -= diff;
					} else {
						l += diff;
					}
				}
				if(cmp(stddev(nums, m), s)) break;
				if(cmp(origVal, 0)) {
					i++;
				} else {
					j--;
				}
			}
		}
		if(cmp(avg(nums), m) && cmp(stddev(nums, m), s)) {
			sort(nums.begin(), nums.end());
			cout << nums.size() << " ";
			for(int i = 0; i < nums.size(); i++) {
				cout << nums[i] << " ";
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}