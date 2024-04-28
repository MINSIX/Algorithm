#include<bits/stdc++.h>
using namespace std;

int N, E;
const int INF = 1e8;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> N >> E;
	vector<vector<int>>arr(N + 1, vector<int>(N + 1, INF));
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;

	}
	int x1, x2;
	cin >> x1 >> x2;
	for(int k=1;k<=N;k++){
		for (int i = 1; i <= N; i++) {
			if (i == k)
				continue;
			for (int j = 1; j <= N; j++) {
				if (i == j || k == j)
					continue;

				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);


			}
		}
	}
	int mm=9999999;
	if (x1 == 1)
		if(x2==N)
		 mm = arr[1][N];
		else
		mm = arr[1][x2] + arr[x2][N];
	else
	mm = min(arr[1][x1] + arr[x1][x2] + arr[x2][N], arr[1][x2] + arr[x2][x1] + arr[x1][N]);
	
	if (mm >= INF)
		cout << -1 << endl;
	else
		cout << mm << endl;



}
