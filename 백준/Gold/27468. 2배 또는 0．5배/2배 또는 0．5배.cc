#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	cout << "YES" << endl;



	int div1[4] = { 0,2,1,3 };
	int div2[4] = { 1,0,2,3 };


	if (N % 4 == 1) {
		for (int i = 0; i < N; i ++) {
			cout << (i/4)*4 + div1[i%4]+1<<" ";
	
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			cout <<(i/4)*4 + div2[i %4]+1 << " ";
	
		}
	}



	return 0;
}
