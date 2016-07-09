#include <iostream>
#include <math.h>

int main(){
	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		int d, x, s;
		std::cin >> d >> x >> s;
		int c[d], pl[d], ps[d];
		for(int j = 0; j < d; j++){
			std::cin >> c[j] >> pl[j] >> ps[j];
			if(j != 0){
				if(pl[j-1] < pl[j]) pl[j] = pl[j-1];
				if(ps[j-1] < ps[j]) ps[j] = ps[j-1];
			}
		}

		long long cost = 0, currS = 0;
		for(int j = 0; j < d; j++){
			int needS = c[j] * s - currS;

			cost += pl[j] * c[j] * x;
			
			if(needS > 0){
				currS += ceil(needS / 80.0) * 80;
				cost += ps[j] * ceil(needS / 80.0);
			}
			currS -= c[j]*s;
		}
		
		std::cout << cost << "\n";
	}	
}