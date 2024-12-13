#include<bits/stdc++.h>
using namespace std;

struct point {
    int x, y, value;
};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> arr(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<point> q;
    queue<pair<int, int>> fire;
    queue<pair<int, int>> firesave;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'J') {
                q.push({i, j, 0});
                visited[i][j] = true; 
            }
            if (arr[i][j] == 'F') {
                fire.push({i, j});
            }
        }
    }

    int fireval = -1;
    while (!q.empty()) {
        int nowx = q.front().x;
        int nowy = q.front().y;
        int nowval = q.front().value;
        q.pop();

        if (fireval < nowval) {
            while (!fire.empty()) {
                int firex = fire.front().first;
                int firey = fire.front().second;
                fire.pop();

                for (int i = 0; i < 4; i++) {
                    int xx = firex + dx[i];
                    int yy = firey + dy[i];

                    if (xx < 0 || yy < 0 || xx >= N || yy >= M)
                        continue;
                    if (arr[xx][yy] == 'F' || arr[xx][yy] == '#')
                        continue;

                    arr[xx][yy] = 'F';
                    firesave.push({xx, yy});
                }
            }
            fireval++;
            fire = firesave;
            firesave = queue<pair<int, int>>();
        }

        for (int i = 0; i < 4; i++) {
            int xx = nowx + dx[i];
            int yy = nowy + dy[i];

            if (xx < 0 || yy < 0 || xx >= N || yy >= M) {
                cout << nowval + 1;
                return 0;
            }

            if (arr[xx][yy] == 'F' || arr[xx][yy] == '#' || visited[xx][yy])
                continue;

            visited[xx][yy] = true; 
            q.push({xx, yy, nowval + 1});
        }
    }

    cout << "IMPOSSIBLE"; 
}
