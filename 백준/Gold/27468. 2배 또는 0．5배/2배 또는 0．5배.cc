#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	cout << "YES" << endl;

	if (N % 4 == 1) {
		for (int i = 1; i <= N; i += 4) {
			cout << i << " " << i + 2 << " " << i + 1 << " " << i + 3 << " ";
		}
	}
	else {
		for (int i = 1; i <= N; i += 4) {
			cout << i+1 << " " << i << " " << i + 2 << " " << i + 3 << " ";
		}
	}



	return 0;
}
