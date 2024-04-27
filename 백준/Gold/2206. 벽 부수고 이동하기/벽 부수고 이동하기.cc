#include<bits/stdc++.h>
using namespace std;
int N, M;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int main() {
    cin >> N >> M;
    vector<vector<int>>arr(N + 1, vector<int>(M + 1, 0));
    char a;
    arr[1][1] = 0;
    arr[N][M] = 0;
    vector<pair<int, int>> sv;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a;
            arr[i][j] = a - '0';
            if (arr[i][j] == 1)
                sv.push_back({ i,j });
        }
    }

    vector<vector<vector<int>>> visited;
    visited.resize(N + 1, vector<vector<int>>(M + 1, vector <int>(2,0)));
    queue<pair<pair<int, int>, int>> q;


    q.push({{ 1,1 }, 1});
    visited[1][1][1] = 1;
    while (!q.empty()) {

        int nowx = q.front().first.first;
        int nowy = q.front().first.second;
        int wall = q.front().second;
        if (nowx == N && nowy == M)
        {

            break;
        }
        q.pop();
        for (int t = 0; t < 4; t++) {
            int xx = nowx + dx[t];
            int yy = nowy + dy[t];
            if (xx <= 0 || xx > N || yy <= 0 || yy > M)
                continue;
            if (wall && arr[xx][yy] == 1)
            {
                q.push({ { xx,yy }, 0});
                visited[xx][yy][wall - 1] = visited[nowx][nowy][wall] + 1;
            }
            else if (arr[xx][yy] == 0 && visited[xx][yy][wall] == 0) {
                q.push({ {xx,yy},wall });
                visited[xx][yy][wall] = visited[nowx][nowy][wall] + 1;
            }
        }
    }

    visited[N][M][1] = max(visited[N][M][1], visited[N][M][0]);
    if (visited[N][M][1] == 0)
        cout << -1 << '\n';
    else
        cout << visited[N][M][1] << '\n';

    return 0;
}
