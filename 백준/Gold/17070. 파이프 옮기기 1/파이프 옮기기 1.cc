#include <bits/stdc++.h>
using namespace std;

int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;

    vector<vector<int>> arr(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    queue<pair<pair<int, int>, int>> q;
    q.push({ {1, 2}, 0 });
    while (!q.empty()) {
        int nowx = q.front().first.first;
        int nowy = q.front().first.second;
        int di = q.front().second;
        q.pop();

        for (int i = 0; i < 3; i++) {
            if (di == 0 && i == 1) continue;
            if (di == 1 && i == 0) continue;

            int xx = nowx + dx[i];
            int yy = nowy + dy[i];
            if (xx > N || yy > N) continue;
            if (arr[xx][yy] == 1) continue;
            if (i == 2 && (arr[xx][nowy] == 1 || arr[nowx][yy] == 1)) continue;

            if (xx == N && yy == N) {
                cnt++;
                continue;
            }

            q.push({ {xx, yy}, i });
        }
    }
    cout << cnt << endl;

    return 0;
}
