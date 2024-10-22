#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    int N, K, R;
    cin >> N >> K >> R;

    int r, rr, c, cc;
    vector<vector<vector<pair<int, int>>>> arr(N + 1, vector<vector<pair<int, int>>>(N + 1));
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    vector<vector<bool>> cow(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < R; i++) {
        cin >> r >> c >> rr >> cc;
        arr[r][c].push_back({rr, cc});
        arr[rr][cc].push_back({r, c});
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> sv;
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        cow[r][c] = true;
        sv.push({r, c});
    }

    int cnt = 0; 

    while (!sv.empty()) {

        visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
        q.push(sv.front());
        sv.pop();
        visited[q.front().first][q.front().second] = true;

        while (!q.empty()) {
            int nowx = q.front().first;
            int nowy = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int xx = nowx + dx[i];
                int yy = nowy + dy[i];

                if (xx < 1 || yy < 1 || xx > N || yy > N)
                    continue;

                if (visited[xx][yy])
                    continue;

                bool check = false;
                for (auto k : arr[nowx][nowy]) {
                    if (k.first == xx && k.second == yy) {
                        check = true;
                        break;
                    }
                }
                if (check)
                    continue;

                if (cow[xx][yy])
                    cnt++;

                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }
    }

    cout << (K * (K - 1) - cnt) / 2 << endl;

    return 0;
}
