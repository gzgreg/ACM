#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int crosses(pii orig, pii slope, pii pt) {
	complex<double> o(orig.first, orig.second), 
		s(slope.first, slope.second), p(pt.first, pt.second);
	double fac = (p.imag() - o.imag()) / s.imag();
	if(s.imag() == 0) {
		if(p.imag() - o.imag() != 0) {
			return false;
		} else {
			fac = 0;
		}
	}
	o += fac * s;
	if(abs(o.real() - p.real()) < 1e-9) {
		return 2;
	}
	if(o.real() > p.real() + 1e-9) {
		return true;
	}
	return false;
}

bool crosses2(pii orig, pii slope, pii pt) {
	complex<double> o(orig.first, orig.second), 
		s(slope.first, slope.second), p(pt.first, pt.second);
	double fac = (p.real() - o.real()) / s.real();
	if(s.real() == 0) {
		if(p.real() - o.real() != 0) {
			return false;
		} else {
			fac = 0;
		}
	}
	o += fac * s;
	if(abs(o.imag() - p.imag()) < 1e-9) {
		return 2;
	}
	if(o.imag() > p.imag() + 1e-9) {
		return true;
	}
	return false;
}

bool solve(vector<pii>& outer, vector<pii>& inner) {
	{
		int maxVal = -2e9, maxIdx, minVal = 2e9, minIdx;
		for(int i = 0; i < outer.size(); i++) {
			int yi = outer[i].second;
			if(yi > maxVal) {
				maxVal = yi;
				maxIdx = i;
			}
			if(yi < minVal) {
				minVal = yi;
				minIdx = i;
			}
		}

		vector<pii> left, right;

		if(minIdx > maxIdx) swap(minIdx, maxIdx);

		for(int i = minIdx; i <= maxIdx; i++) {
			left.push_back(outer[i]);
		}

		for(int i = maxIdx; i <= minIdx + outer.size(); i++) {
			right.push_back(outer[i % outer.size()]);
		}

		if(left[0].second > left[left.size() - 1].second) {
			reverse(left.begin(), left.end());
		} else {
			reverse(right.begin(), right.end());
		}

		// for(pii cur : left) {
		// 	cout << "(" << cur.first << " " << cur.second << ") ";
		// }
		// cout << endl;

		// for(pii cur : right) {
		// 	cout << "(" << cur.first << " " << cur.second << ") ";
		// }
		// cout << endl;

		for(int i = 0; i < inner.size(); i++) {
			int xi = inner[i].first, yi = inner[i].second;
			int numOverlaps = 0;
			int l = 0;
			for(int i = 1 << 30; i > 0; i >>= 1) {
				if(l + i <= left.size() && left[l+i - 1].second <= yi) {
					l += i;
				}
			}
			if(l == 0 || l == left.size()) {
				return false;
			}

			pii dir = {left[l].first - left[l-1].first, 
						left[l].second - left[l-1].second};

			if(crosses(left[l-1], dir, {xi, yi})) {
				if(crosses(left[l-1], dir, {xi, yi}) == 2) {
					return false;
				}
				numOverlaps++;
			}

			l = 0;
			for(int i = 1 << 30; i > 0; i >>= 1) {
				if(l + i <= right.size() && right[l+i - 1].second <= yi) {
					l += i;
				}
			}

			if(l == 0 || l == right.size()) {
				return false;
			}

			dir = {right[l].first - right[l-1].first, 
						right[l].second - right[l-1].second};

			if(crosses(right[l-1], dir, {xi, yi})) {
				if(crosses(right[l-1], dir, {xi, yi}) == 2) {
					return false;
				}
				numOverlaps++;
			}

			if(numOverlaps == 2 || numOverlaps == 0) {
				return false;
			}
		}
	}

	{
		int maxVal = -2e9, maxIdx, minVal = 2e9, minIdx;
		for(int i = 0; i < outer.size(); i++) {
			int yi = outer[i].first;
			if(yi > maxVal) {
				maxVal = yi;
				maxIdx = i;
			}
			if(yi < minVal) {
				minVal = yi;
				minIdx = i;
			}
		}

		vector<pii> left, right;

		if(minIdx > maxIdx) swap(minIdx, maxIdx);

		for(int i = minIdx; i <= maxIdx; i++) {
			left.push_back(outer[i]);
		}

		for(int i = maxIdx; i <= minIdx + outer.size(); i++) {
			right.push_back(outer[i % outer.size()]);
		}

		if(left[0].first > left[left.size() - 1].first) {
			reverse(left.begin(), left.end());
		} else {
			reverse(right.begin(), right.end());
		}

		// for(pii cur : left) {
		// 	cout << "(" << cur.first << " " << cur.second << ") ";
		// }
		// cout << endl;

		// for(pii cur : right) {
		// 	cout << "(" << cur.first << " " << cur.second << ") ";
		// }
		// cout << endl;

		for(int i = 0; i < inner.size(); i++) {
			int xi = inner[i].first, yi = inner[i].second;
			int numOverlaps = 0;
			int l = 0;
			for(int i = 1 << 30; i > 0; i >>= 1) {
				if(l + i <= left.size() && left[l+i - 1].first <= xi) {
					l += i;
				}
			}
			//cout << l << " " << xi << endl;
			if(l == 0 || l == left.size()) {
				return false;
			}

			pii dir = {left[l].first - left[l-1].first, 
						left[l].second - left[l-1].second};

			if(crosses2(left[l-1], dir, {xi, yi})) {
				if(crosses2(left[l-1], dir, {xi, yi}) == 2) {
					numOverlaps++;
				}
				numOverlaps++;
			}

			l = 0;
			for(int i = 1 << 30; i > 0; i >>= 1) {
				if(l + i <= right.size() && right[l+i - 1].first <= xi) {
					l += i;
				}
			}
			//cout << l << endl;
			if(l == 0 || l == right.size()) {
				return false; 
			}

			dir = {right[l].first - right[l-1].first, 
						right[l].second - right[l-1].second};

			if(crosses2(right[l-1], dir, {xi, yi})) {
				if(crosses2(right[l-1], dir, {xi, yi}) == 2) {
					numOverlaps++;
				}
				numOverlaps++;
			}

			if(numOverlaps == 2 || numOverlaps == 0) {
				return false;
			}
		}
	}
	
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M; cin >> N >> M;

	vector<pii> outer, inner;
	for(int i = 0; i < N; i++) {
		int xi, yi; cin >> xi >> yi; outer.push_back({xi, yi});
	}

	for(int i = 0; i < M; i++) {
		int xi, yi; cin >> xi >> yi; inner.push_back({xi, yi});
	}

	if(solve(outer, inner) || solve(inner, outer)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}