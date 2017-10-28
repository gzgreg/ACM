#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<ld> pt;

const ll INF = 0x3f3f3f3f; const ld EPS = 1e-14;

ld cp(const pt& a, const pt& b) { return imag(conj(a)*b);}
ld dp(const pt& a, const pt& b) { return real(conj(a)*b); }

inline pt line_inter(const pt &a, const pt &b, const pt &c, const pt &d) {
	return a + cp(c - a, d - c) / cp(b - a, d - c) * (b - a);
}

inline pt lsp_closest(const pt &a, const pt &b, const pt &p) {
	return line_inter(a, b, p, p+(a-b)*pt(0, 1));
}

pair<ld, pt> calcIntersection(pt p0, pt v, ld r1, ld r2) {
	if(abs(v) < EPS) return {1e11, {0, 0}};

	pt pc = lsp_closest(p0, p0 + v, {0, 0});

	if(abs(pc) - EPS > r1 + r2) return {1e11, {0, 0}};

	pt p = -v / abs(v) * sqrt((r1 + r2)*(r1 + r2) - abs(pc)*abs(pc)) + pc;

	if(dp(v, p-p0) < 0) return {1e11, {0, 0}};

	ld t = abs(p - p0) / abs(v);

	return {t, p};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	vector<pair<pair<pt, pt>, ld>> drops;

	for(int i = 0; i < N; i++) {
		int x, y, vx, vy, r; cin >> x >> y >> vx >> vy >> r;
		drops.push_back({{pt(x, y), pt(vx, vy)}, r});
	}

	ld totTime = 0.0;

	while(drops.size() > 1) {
		ld interTime = 1e11;
		int id1, id2;
		pt interLoc;

		for(int i = 0; i < drops.size(); i++) {
			for(int j = i+1; j < drops.size(); j++) {
				pt p1, p2, v1, v2;
				ld r1, r2;
				forward_as_tuple(tie(p1, v1), r1) = drops[i];
				forward_as_tuple(tie(p2, v2), r2) = drops[j];

				pt p = p2 - p1;
				pt v = v2 - v1;

				ld t; pt inter;

				tie(t, inter) = calcIntersection(p, v, r1, r2);

				if(t > 1e10 || t < 0) continue;
				if(t < interTime) {
					interTime = t;
					interLoc = inter;
					id1 = i;
					id2 = j;
				}
			}
		}

		if(interTime > 1e10) break;
		totTime += interTime;

		pt newLoc, newV;
		pt p1, p2, v1, v2;
		ld r1, r2;
		forward_as_tuple(tie(p1, v1), r1) = drops[id1];
		forward_as_tuple(tie(p2, v2), r2) = drops[id2];

		ld weight = r1*r1 + r2*r2;

		pt loc1 = p1 + v1*interTime;
		pt loc2 = p2 + v2*interTime;

		newLoc = (loc1*(r1*r1) + loc2*(r2*r2)) / weight;
		newV = (v1*(r1*r1) + v2*(r2*r2)) / weight;

		vector<pair<pair<pt, pt>, ld>> newDrops;
		newDrops.push_back({{newLoc, newV}, sqrt(weight)});
		for(int i = 0; i < drops.size(); i++) {
			if(i == id1 || i == id2) continue;
			pt p1, v1;
			ld r1;

			forward_as_tuple(tie(p1, v1), r1) = drops[i];
			newDrops.push_back({{p1 + v1*interTime, v1}, r1});
		}

		drops = newDrops;
	}

	cout << drops.size() << " " << fixed << setprecision(10) << totTime << endl;
	
	return 0;
}