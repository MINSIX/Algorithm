#include<bits/stdc++.h>
using namespace std;
int N, M, K;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int main() {
    cin >> N >> M >> K;
    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));
    char a;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a;
            arr[i][j] = a - '0';
        }
    }

    vector<vector<vector<int>>> visited(N + 1, vector<vector<int>>(M + 1, vector<int>(K + 1, 0)));
    queue<pair<pair<int, int>, int>> q;

    q.push({ { 1, 1 }, 0 });
    visited[1][1][0] = 1;

    while (!q.empty()) {
        int nowx = q.front().first.first;
        int nowy = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if (nowx == N && nowy == M) {
            cout << visited[nowx][nowy][wall] << '\n';
            return 0;
        }

        for (int t = 0; t < 4; t++) {
            int xx = nowx + dx[t];
            int yy = nowy + dy[t];

            if (xx <= 0 || xx > N || yy <= 0 || yy > M)
                continue;

            if (arr[xx][yy] == 1 && wall < K && visited[xx][yy][wall + 1] == 0) {
                q.push({ {xx, yy}, wall + 1 });
                visited[xx][yy][wall + 1] = visited[nowx][nowy][wall] + 1;
            }

            if (arr[xx][yy] == 0 && visited[xx][yy][wall] == 0) {
                q.push({ {xx, yy}, wall });
                visited[xx][yy][wall] = visited[nowx][nowy][wall] + 1;
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
