#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
const int INF = 10e9;
int K, L;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> L;
	unordered_map<string, int> ck;
	string a;
	for (int i = 0; i < L; i++)
	{
		cin >> a;
		ck[a]=i;
	}
	vector<pair<int,string>>result;
	for (auto& i :ck) {
		result.push_back({ i.second,i.first });
	}
	sort(result.begin(), result.end());
	int j = 0;
	for (auto& i : result) {
		cout << i.second << "\n";
		j++;
		if (j == K)
			break;
	}



}
