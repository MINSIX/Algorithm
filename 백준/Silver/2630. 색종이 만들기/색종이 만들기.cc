#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int ar[130][130];
int n;
int bn = 0, wn = 0;
bool blue, white;

void dc(int a, int b, int c) {

	blue = true;
	white = true;

	for (int i = a; i < a + c; i++) {
		for (int j = b; j < b + c; j++) {
			if (ar[i][j] == 1)white = false;
			if (ar[i][j] == 0)blue = false;
			if (white == false && blue == false)break;
		}
	}

	if (blue == true) {
		bn++;
		return ;
	}

	if (white == true) {
		wn++;
		return ;
	}

	dc(a, b, c / 2);
	dc(a, c / 2 + b, c / 2);
	dc(c / 2 + a, b, c / 2);
	dc(c / 2 + a, c / 2 + b, c / 2);
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;

	for (int i =1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> ar[i][j];
	}

	dc(1, 1, n);

	cout << wn << "\n";
	cout << bn << "\n";

	return 0;
}