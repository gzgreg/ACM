using namespace std;

#include <iostream>
#include <string>

bool isVowel(char);

int main(){
	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		string str;
		long long num = 0;
		cin >> str;
		cout << "String #" << i + 1 << ": ";
		if(!str.find("?")){
			num = 1;
			for(j = 1; j < str.length(); j++){
				bool a = isVowel(str[j]);
				bool b = isVowel(str[j-1]);
				if(a == b){
					num = 0;
					break;
				}
			}
		} else {
			for(j = 1; j < str.length(); j++){

			}
		}

		cout << num << "\n";
	}	
}

bool isVowel(char c){
	return c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}