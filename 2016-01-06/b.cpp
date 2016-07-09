#include <bits/stdc++.h>

using namespace std;

void print_square_of_n_minus_m(int n, m)
{
	cout << (n - m) * (n - m);
}

void execute_strategy_queued(void (f*)())
{
	// TODO implement queue
	f();
}

int main(){
	ios::sync_with_stdio(0);
	int n; cin >> n;
	execute_strategy_queued([=]() { print_square_of_n_minus_m(n, 2) });
	return 0;
}