#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int N, M,H;
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N>>H;
	int dx[6] = { -1,0,0,1,0,0 };
	int dy[6] = { 0,-1,1,0 ,0,0};
	int dz[6] = { 0,0,0,0,-1,1 };


	vector<vector<vector<int>>> box(H + 1, vector<vector<int>>(N + 1,vector<int>(M+1,0)));
	vector<vector<vector<int>>> boxcnt(H + 1, vector<vector<int>>(N + 1,vector<int>(M+1,INF)));
	vector<vector<vector<bool>>> visited(H + 1, vector<vector<bool>>(N + 1, vector<bool>(M + 1,false)));

	queue<pair<pair<int, int>,int>>q;
	for (int k = 1; k <= H; k++) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			
			cin >> box[k][i][j];

			if (box[k][i][j] == 1)
			{
				q.push({ {i,j},k });
				visited[k][i][j] = true;
				boxcnt[k][i][j] = 0;
			}
			else if (box[k][i][j] == -1)
				visited[k][i][j] = true;
		}

	}
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int t = 0; t < 6; t++) {
			int nowx = x + dx[t];
			int nowy = y + dy[t];
			int nowz = z + dz[t];
			if (nowx<1 || nowy<1 || nowx>N || nowy>M||nowz<1||nowz>H)
				continue;


			if (box[nowz][nowx][nowy] != -1) {
				if (visited[nowz][nowx][nowy] == false)
				{

					q.push({ { nowx,nowy},nowz });
					visited[nowz][nowx][nowy] = true;
					boxcnt[nowz][nowx][nowy] = min(boxcnt[z][x][y] + 1, boxcnt[nowz][nowx][nowy]);

				}
			}




		}


	}

	int cnt = 0;
	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{


				if (visited[k][i][j] == false)
				{


					cout << -1 << endl;
					return 0;
				}
				if (box[k][i][j] != -1)
					cnt = max(cnt, boxcnt[k][i][j]);


			}

		}
	}
	cout << cnt << endl;




}
