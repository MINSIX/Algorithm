#include<bits/stdc++.h>

using namespace std;

int n;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	vector<vector<char>> grid(n + 1, vector<char>(n + 1));
	int rx,ry,gx,gy,bx,by;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> grid[i][j];
		}
	}
	int rgbcnt = 0;
	queue<pair<int, int>> q;
	vector<vector<bool>>visited ( n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == false) {
				
				rgbcnt++;
				visited[i][j] == true;
				q.push({ i,j });
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int nowx = x + dx[t];
						int nowy = y + dy[t];
					
						if (nowx<1 || nowy<1 || nowx>n || nowy>n || visited[nowx][nowy] == true || grid[nowx][nowy] != grid[x][y])
							continue;
	
						q.push({ nowx,nowy });
						visited[nowx][nowy] = true;
					
					}
				}
			}
		}
	}
	int rbcnt = 0;
	vector<vector<bool>>visited1(n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited1[i][j] == false) {

				rbcnt++;
				visited1[i][j] == true;
				q.push({ i,j });
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int nowx = x + dx[t];
						int nowy = y + dy[t];

						if (nowx<1 || nowy<1 || nowx>n || nowy>n || visited1[nowx][nowy] == true )
							continue;

						if(grid[nowx][nowy]!=grid[x][y]){
							if (grid[nowx][nowy] == 'B')
							{
								continue;
							}
							else if (grid[nowx][nowy] == 'G') {
								if (grid[x][y] == 'B')
									continue;

							}
							else if (grid[nowx][nowy] == 'R') {
								if (grid[x][y] == 'B')
									continue;

							}
						
						
						}
						q.push({ nowx,nowy });
						visited1[nowx][nowy] = true;

					}
				}
			}
		}
	}





	cout << rgbcnt << " " << rbcnt << endl;
}
