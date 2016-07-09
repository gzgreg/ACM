using namespace std;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

#define INF 100000000

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n; cin >> n;
		int points[n][2];
		double slopes[n][n];
		for(int j = 0; j < n; j++){
			cin >> points[j][1] >> points[j][2];
		}
		cout << "Case #" << i + 1 << ": ";
		for(int j = 0; j < n - 1; j++){
			for(int k = j + 1; k < n; k++){
				double slope;
				if(points[j][1] == points[k][1]){
					slope = INF;
				} else {
					slope = ((double) (points[j][2] - points[k][2])) / (points[j][1] - points[k][1]);
				}
				slopes[j][k] = slope;
			}
		}
		int maxLine = 1;
		for(int j = 0; j < n; j++){
			for(int k = j+1; k < n; k++){
				int currLine = 2;
				double currSlope = slopes[j][k];
				for(int l = k+1; l < n; l++){
					if(fabs(currSlope - slopes[j][l]) < 1e-10){
						currLine++;
					}
				}
				if(currLine > maxLine) maxLine = currLine;
			}
		}

		if(n == 0) maxLine = 0;
		cout << maxLine << endl;
	}

	cin >> t;
}