#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1}; 
int dy[4] = {0, -1, 1, 0};

struct State {
    int x, y, k, cnt;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> arr(N + 1, vector<int>(M + 1));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char a;
            cin >> a;
            arr[i][j] = a - '0';
        }
    }

    vector<vector<vector<bool>>> visited(N + 1, vector<vector<bool>>(M + 1, vector<bool>(K + 1, false)));
    
    queue<State> q;
    q.push({1, 1, K, 1});
    visited[1][1][K] = true;

    while (!q.empty()) {
        int nowx = q.front().x;
        int nowy = q.front().y;
        int kk = q.front().k;
        int cnt = q.front().cnt;
        q.pop();

        if (nowx == N && nowy == M) {
            cout << cnt;
            return 0;
        }

        for (int i = 0; i < 4; i++) { 
            int xx = nowx + dx[i];
            int yy = nowy + dy[i];
            if (xx < 1 || yy < 1 || xx > N || yy > M) continue;

            bool is_day = (cnt % 2 == 1);

            if (arr[xx][yy] == 0 && !visited[xx][yy][kk]) {
                visited[xx][yy][kk] = true;
                q.push({xx, yy, kk, cnt + 1});
            }
            if (arr[xx][yy] == 1 && kk > 0 && !visited[xx][yy][kk - 1]) {
                if (is_day) {
                    visited[xx][yy][kk - 1] = true;
                    q.push({xx, yy, kk - 1, cnt + 1});
                } else {
                    q.push({nowx, nowy, kk, cnt + 1});
                }
            }
        }
    }

    cout << -1;
}
