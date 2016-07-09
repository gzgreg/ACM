#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	vector<vector<int>> points;
	for(int i = 0; i < 3; i++){
		int x, y; cin >> x >> y;
		points.push_back({ x, y });
	}

	int max = 3;

	for (int i = 0; i < 2; i++)
	{
		if (points[0][i] == points[1][i] && points[1][i] == points[2][i])
		{
			max = min(max, 1);
		}

		for (int j = 0; j < 3; j++)
		{
			int a = (j + 1) % 3;
			int b = (j + 2) % 3;
			if (points[a][(i + 1) % 2] == points[b][(i + 1) % 2])
			{
				if (points[j][i] <= points[a][i] && points[j][i] <= points[b][i])
				{
					max = min(max, 2);
				}
				else if (points[j][i] >= points[a][i] && points[j][i] >= points[b][i])
				{
					max = min(max, 2);
				}
			}
		}
	}

	cout << max << endl;

	return 0;
}