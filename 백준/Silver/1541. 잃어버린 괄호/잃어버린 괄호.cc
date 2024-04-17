#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string s;
	cin >> s;
	vector<int> num;
	vector<char> sign;
	int decimal = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			sign.push_back(s[i]);
			num.push_back(decimal);
			decimal = 0;
		}
		else {
	
			decimal = decimal * 10 + s[i]-'0';
		}
	}

	num.push_back(decimal);
	int sum = num[0];
	bool flag = false;
	for (int i = 0; i < sign.size(); i++) {
		if (sign[i] == '-') {
			flag = true;
		}
		if (flag) {
			sum -= num[i + 1];
		}
		else {
			sum += num[i + 1];
		}
	}


	cout << sum<<endl;

}
