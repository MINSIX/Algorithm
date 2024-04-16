#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int N;

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };


int main() {
		cin >>N;
    vector<vector<int>>danji(N + 1, vector<int>(N + 1,0));
    vector<vector<bool>>visited(N + 1, vector<bool>(N + 1,false));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char gg = cin.get();
            if (gg == '\n')
                gg = cin.get();

            danji[i][j] = gg - '0';
        }
    }


    int cnt = 0;
    queue<pair<int, int>>q;
    vector<int> sum(25 * 25, 999);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            if (danji[i][j] == 0 || visited[i][j] == true)
                continue;

            visited[i][j] = true;
            cnt++;
            sum[cnt] = 1;
            q.push({ i,j });
            while (!q.empty()) {

                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int t = 0; t < 4; t++) {
                    int nowx = x + dx[t];
                    int nowy = y + dy[t];

                    if (nowx <1 || nowy <1 || nowx > N || nowy > N)
                        continue;

                    if (danji[nowx][nowy] == 0|| visited[nowx][nowy] == true)
                        continue;


                    visited[nowx][nowy] = true;

                   q.push({ nowx,nowy });

                    sum[cnt]++;



                }

            }
        }
    }
    cout << cnt << endl;
    sort(sum.begin(), sum.end());
    for (int i = 0; i < cnt; i++)
        cout << sum[i] << endl;
}
