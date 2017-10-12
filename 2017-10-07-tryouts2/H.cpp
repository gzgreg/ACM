#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; double t; cin >> n >> t;

	vector<pair<complex<double>, int>> vals;
	for(int i = 0; i < n; i++) {
		double xi, yi, ti; cin >> xi >> yi >> ti;
		vals.push_back({{xi, yi}, ti});
	}

	double totDist = 0;
	vector<double> segLen = {0};
	for(int i = 1; i < n; i++) {
		segLen.push_back(abs(vals[i].first - vals[i-1].first));
		totDist += segLen[i];
	}

	double estDist = 0;
	double timeOverflow = 0;
	complex<double> lastPos = vals[0].first;
	for(int i = 1; i < n; i++) {
		double totTime = vals[i].second - vals[i-1].second;
		double curSpeed = segLen[i] / totTime;

		double curTime = timeOverflow;
		if(curTime > totTime) {
			timeOverflow -= totTime;
			continue;
		}
		complex<double> delta = (vals[i].first - vals[i-1].first) / abs(vals[i].first - vals[i-1].first) * curSpeed;
		
		if(abs(vals[i].first - vals[i-1].first) < 1e-5) {
			delta = {0, 0};
		}
		complex<double> curPos = vals[i-1].first + delta * curTime;
		//cout << curPos << endl;
		estDist += abs(curPos - lastPos);
		while(true) {
			lastPos = curPos;

			curTime += t;
			curPos += delta * t;

			if(curTime > totTime) {
				timeOverflow = curTime - totTime;
				break;
			}

			//cout << curPos << endl;
			estDist += abs(curPos - lastPos);
		}
	}
	estDist += abs(vals[n-1].first - lastPos);
	//cout << estDist << endl;

	cout << fixed << setprecision(10) << 100* (totDist - estDist) / totDist << endl;
	
	return 0;
}