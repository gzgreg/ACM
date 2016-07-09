#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> genTetra();
vector<long long> genTri();

vector<long long> tetra = genTetra();
vector<long long> tri = genTri();

int main(){
	int N; cin >> N;
	for(int i = 0; i < N; i++){
		long long num; cin >> num;
		long long n;
		for(int j = floor(cbrt(num * 6)) - 2; j < tetra.size(); j++){
			if(j < 0) continue;
			if(tetra[j] >= num){
				n = j;
				break;
			}
		}
		long long sum=0;
		for(int j = n; j >= 0; j--){
			sum += tri[j];
			if(sum >= num){
				cout << n - j + 1 << endl;
				break;
			}
		}
	}
	return 0;
}

vector<long long> genTetra(){
	vector<long long> cont;
	long long i = 1;
	while(i * (i+1) * (i+2) / 6 < 1e15){
		cont.push_back(i * (i+1) * (i+2) / 6);
		i++;
	}
	cont.push_back(i * (i+1) * (i+2) / 6);
	return cont;
}

vector<long long> genTri(){
	vector<long long> cont;
	long long i = 1;
	while(i * (i+1)/ 2 < 1e15){
		cont.push_back(i * (i+1)/ 2);
		i++;
	}
	cont.push_back(i * (i+1)/ 2);
	return cont;
}

