#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int N;
const int INF = 1e9;
vector<bool> button(12, true);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	vector<vector<int>>arr(N + 1, vector<int>(N + 1,INF));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
				arr[i][j] = INF;

		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
			{
			
					arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
	

			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (arr[i][j] ==INF)
				cout << 0<< " ";
			else
				cout << 1 << " ";
		}cout << endl;
	}
}
