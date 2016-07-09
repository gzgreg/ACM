#include <iostream>

int main(){
	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		int brownie, student, m;
		std::cin >> student >> brownie >> m;
		std::cout << "Practice #" << i + 1 << ": " << student << " " << brownie << "\n";
		for(int j = 0; j < m; j++){
			int numS;
			std::cin >> numS;
			while(brownie <= numS){
				brownie *= 2;
			}
			brownie -= numS;
			std::cout << numS << " " << brownie << "\n";
		}
	}	
}