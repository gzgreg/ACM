#include <iostream>

int main(){
	int n;
	std::cin >> n;
	int nums[n][10];
	bool zack[n];
	bool mack[n];

	for(int i = 0; i < n; i++){
		zack[i] = false;
		mack[i] = false;
		for(int j = 0; j < 10; j++){
			int temp;
			std::cin >> temp;
			nums[i][j] = temp;
			if(temp == 18){
				mack[i] = true;
			} else if(temp == 17){
				zack[i] = true;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			std::cout << nums[i][j] << " ";
		}
		std::cout << "\n";
		if(zack[i] && mack[i]){
			std::cout << "both";
		} else if(zack[i]){
			std::cout << "zack";
		} else if(mack[i]){
			std::cout << "mack";
		} else {
			std::cout << "none";
		}
		std::cout << "\n\n";
	}

	std::cin.get();
}