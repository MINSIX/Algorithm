#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;

int N, M;

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void wallsettingst(vector<vector<int>>& arr,int a,int b,int c) {

    arr[wall[a].first][wall[a].second] = 1;
    arr[wall[b].first][wall[b].second] = 1;
    arr[wall[c].first][wall[c].second] = 1;


}

int bfs(vector<vector<int>> arr,int a,int b,int c) {
    vector<vector<int>>svarr = arr;
    wallsettingst(svarr,a,b,c);
    queue<pair<int, int>>q;
    for (auto i : virus) {
        vector<vector<bool>>visited(N, vector<bool>(M, false));
        q.push({ i.first,i.second });
        while (!q.empty()) {
            int nowx = q.front().first;
            int nowy = q.front().second;
            visited[nowx][nowy] = true;
            q.pop();
            for (int t = 0; t < 4; t++) {
                int xx = nowx + dx[t];
                int yy = nowy + dy[t];
                
                if (xx < 0 || yy < 0 || xx >= N || yy >= M||visited[xx][yy]==true)
                    continue;

                if (svarr[xx][yy] == 1||svarr[xx][yy]==2)
                    continue;

                svarr[xx][yy] = 2;
                q.push({ xx,yy });
                visited[xx][yy] = true;
            }
        }
    
    
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            if (svarr[i][j] == 0)
                cnt++;
        }
    }
   

    return cnt;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    int wallcnt = 0;
    //2 = virus
    //1 = wall
    vector<vector<int>>arr(N, vector<int>(M, 0));
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                virus.push_back({ i,j });
            if (arr[i][j] == 0)
                wall.push_back({ i,j });
        }
    }
    for(int i=0;i<wall.size()-2;i++)
    {
        for (int j = i+1; j < wall.size() - 1; j++){
           
            for (int k = j+1; k < wall.size() ; k++){


           cnt=max(cnt, bfs(arr,i,j,k));
            }
        
        }
    }
    cout << cnt << "\n";


    return 0;
}