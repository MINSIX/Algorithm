#include<bits/stdc++.h>

using namespace std;
vector<vector<int>>maze;
vector<vector<int>>cnt;

int N, M;
int xx[4] = { -1,0,0,1 };
int yy[4] = { 0,-1,1,0 };


int bfs() {

    queue<pair<int, int>>q;

    cnt[1][1] = 1;
    q.push({ 1,1 });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        for(int i=0;i<4;i++){
            
            int nowx = x + xx[i];
            int nowy = y + yy[i];
            if (nowx == N && nowy == M)
            {
                cnt[N][M] = cnt[x][y] + 1;
                    return cnt[N][M];
            }
            if (nowx <= 0 || nowx > N || nowy <= 0 || nowy > M)
                continue;

            if (maze[nowx][nowy] == 1 ) {
                q.push({ nowx,nowy });
                maze[nowx][nowy] = 0;
                cnt[nowx][nowy]=cnt[x][y]+1;
               }      

        }

    }
    return cnt[N][M];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    maze.resize(N+1, vector<int>(M+1));
    cnt.resize(N + 1, vector<int>(M + 1, 0));

    int a;
    char gg;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
          gg=cin.get();
            if(gg=='\n')
                gg = cin.get();
            
            maze[i][j] = gg-'0';
        }
    }


    cout << bfs() << endl;


}
