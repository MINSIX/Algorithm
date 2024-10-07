#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N, M;
    cin >> N >> M;
  
    vector<vector<int>> arr(N, vector<int>(M));
    int x, y, c;
    cin >> x >> y >> c;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    int nowx = x;
    int nowy = y;

    while (1) {
        if (arr[nowx][nowy] == 0) {
            arr[nowx][nowy] = 2;
            cnt++;
        }

        bool cleaned = false;
        for (int i = 0; i < 4; i++) {
            int xx = nowx + dx[(c + 3) % 4];
            int yy = nowy + dy[(c + 3) % 4];

            if (xx >= 0 && yy >= 0 && xx < N && yy < M && arr[xx][yy] == 0) {
                nowx = xx;
                nowy = yy;
                c =  (c + 3) % 4;
                cleaned = true;
                break;
            }
            c =  (c + 3) % 4;
        }

        if (!cleaned) {
            int xx = nowx + dx[(c + 2) % 4];
            int yy = nowy + dy[(c + 2) % 4];

            if (xx < 0 || yy < 0 || xx >= N || yy >= M || arr[xx][yy] == 1) {
                break;
            }

            nowx = xx;
            nowy = yy;
        }
    }

    cout << cnt;
}
