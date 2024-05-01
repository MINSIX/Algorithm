#include<bits/stdc++.h>
using namespace std;
int N, M;

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // o = 빈공간
    // x = 벽
    // i = 도연이
    // p=사람
    cin >> N >> M;
    vector<vector<char>>arr(N + 1, vector<char>(M + 1));
    int stx, sty;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'I') {
                stx = i;
                sty = j;
            }
        }
    }
    queue<pair<int, int>>q;
    vector<vector<bool>>visited(N + 1, vector<bool>(M + 1, false));
    int sum = 0;
    q.push({ stx,sty });
    while (!q.empty()) {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = nowx + dx[i];
            int yy = nowy + dy[i];

            if (xx <= 0 || yy <= 0 || xx > N || yy >M)
                continue;
            if (arr[xx][yy] == 'X')
                continue;
            if (visited[xx][yy] == true)
                continue;

            if (arr[xx][yy] == 'P')
                sum++;
   
            q.push({ xx,yy });
            visited[xx][yy] = true;



        }


    }
    if(sum==0)
    cout << "TT" << endl;
    else
        cout << sum << endl;

}
