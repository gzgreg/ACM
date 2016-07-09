using namespace std;

#include <iostream>
#include <iomanip>
#include <math.h>

double chance(int, int, bool);

int SO, W, L;
double WChance, LChance, WWChance, WLChance, LWChance, LLChance;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string name;
		getline(cin, name);
		getline(cin, name);
		
		cin >> SO >> W >> L;

		WChance = 20.0 / (20.0 + SO);
		LChance = 1 - WChance;
		WWChance = (20.0 + W) / (20.0 + SO + W);
		LWChance = 1 - WWChance;
		WLChance = (20.0 - L) / (20.0 + SO - L);
		LLChance = 1 - WLChance;
		double ans = chance(4, 0, true) + chance(4, 1, true) + chance(4, 2, true) + chance(4, 3, true);
		cout << setprecision(5) << fixed << ans << endl;
	}
	return 0;
}

double chance(int w, int l, bool wonLast){
	if(w == 0 && l == 0){
		return 1;
	} else if(w == 0 && l == 1){
		return wonLast ? 0 : LChance * chance(w, l - 1, false);
	} else if(w == 1 && l == 0){
		return wonLast ? WChance * chance(w - 1, l, true) : 0;
	} else if(w == 0){
		return wonLast ? 0 : LLChance * chance(w, l - 1, false);
	} else if(l == 0){
		return wonLast ? WWChance * chance(w - 1, l, true) : 0;
	} else if(wonLast){
		return WWChance * chance(w - 1, l, true) + WLChance * chance(w - 1, l, false);
	} else {
		return LWChance * chance(w, l - 1, true) + LLChance * chance(w, l - 1, false);
	}
}