#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int N, M;
const int INF = 1e9;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;

	vector<vector<int>> box(N + 1, vector<int>(M + 1));
	queue<pair<int, int>>q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			cin >> box[i][j];

			if (box[i][j] == 1)
			{
				q.push({ i,j });

			}
			else if (box[i][j] == 0)
				box[i][j] = INF;
		}

	}

	;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int t = 0; t < 4; t++) {
			int nowx = x + dx[t];
			int nowy = y + dy[t];
			if (nowx<1 || nowy<1 || nowx>N || nowy>M)
				continue;


			if (box[nowx][nowy] != -1) {
				if (box[nowx][nowy] == INF)
				{

					q.push({ nowx,nowy });
					
					box[nowx][nowy] = min(box[x][y] + 1, box[nowx][nowy]);

				}
			}




		}


	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{


			if (box[i][j] == INF)
			{


				cout << -1 << endl;
				return 0;
			}
			if (box[i][j] != -1)
				cnt = max(cnt, box[i][j]);
		}
	}
	cout << cnt-1 << endl;




}
