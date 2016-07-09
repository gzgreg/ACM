#include <iostream>

int main(){
	int n;
	std::cin >> n;
	int medals[n][6];
	bool count[n];
	bool color[n];

	for(int i = 0; i < n; i++){
		count[i] = false;
		color[i] = false;
		for(int j = 0; j < 6; j++){
			std::cin >> medals[i][j];
		}
		if(medals[i][0] + medals[i][1] + medals[i][2] > medals[i][3] + medals[i][4] + medals[i][5]){
			count[i] = true;
		}
		if(medals[i][0] > medals[i][3]){
			color[i] = true;
		} else if(medals[i][0] == medals[i][3]){
			if(medals[i][1] > medals[i][4]){
				color[i] = true;
			} else if(medals[i][1] == medals[i][4]){
				if(medals[i][2] > medals[i][5]){
					color[i] = true;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			std::cout << medals[i][j] << " ";
		}
		std::cout << "\n";
		if(count[i] && color[i]){
			std::cout << "both";
		} else if(count[i]){
			std::cout << "count";
		} else if(color[i]){
			std::cout << "color";
		} else {
			std::cout << "none";
		}
		std::cout << "\n\n";
	}
	
}