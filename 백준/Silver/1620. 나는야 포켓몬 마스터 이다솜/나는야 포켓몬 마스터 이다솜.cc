#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int N, M;
const int INF = 1e9;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	string s;
	unordered_map<string, int> dic;
	unordered_map<int , string> dic1;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		dic[s] = i;
		dic1[i] = s;
	}

	for (int i = 0; i < M; i++) {
		cin >> s;

		if (!isdigit(s[0])) {
			cout << dic[s] << '\n';
		}
		else {
			cout << dic1[stoi(s)] << '\n';
		}
	}
		
}
