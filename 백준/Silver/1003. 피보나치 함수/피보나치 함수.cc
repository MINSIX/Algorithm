#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int T;
vector<int>dp0(41);
vector<int>dp1(41);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	int N;

	dp0[0] = 1;
	dp1[0] = 0;
	dp0[1] = 0;
	dp1[1] = 1;
	dp0[2] = 1;
	dp1[2] = 1;
	dp0[3] = 1;
	dp1[3] = 2;
	for (int i = 3; i <= 40; i++) {
		
		
		
		dp0[i] = dp0[i - 1] + dp0[i - 2];
		dp1[i]= dp1[i - 1] + dp1[i - 2];



	}



	while(T-->0){
		cin >> N;

		cout << dp0[N] << " " << dp1[N] << endl;





	
	}



}
