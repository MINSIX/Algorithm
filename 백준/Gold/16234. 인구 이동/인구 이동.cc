#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int main(){
    int N,L,R;
    cin >> N >> L >> R;
    vector<vector<int>> arr(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    queue<pair<int,int>> q;
    int cnt=0;
    while(true){
        vector<vector<bool>> visited(N,vector<bool>(N,false));
        int movement = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visited[i][j]){
                    while(!q.empty()) q.pop();
                    q.push({i,j});
                    visited[i][j] = true;
                    vector<pair<int,int>> v;
                    v.push_back({i,j});
                    int sumPop = arr[i][j];
                    while(!q.empty()){
                        int nowx = q.front().first;
                        int nowy = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int xx = nowx + dx[k];
                            int yy = nowy + dy[k];
                            if(xx<0||yy<0||xx>=N||yy>=N) continue;
                            if(visited[xx][yy]) continue;
                            int diff = abs(arr[xx][yy] - arr[nowx][nowy]);
                            if(diff >= L && diff <= R){
                                visited[xx][yy] = true;
                                q.push({xx,yy});
                                v.push_back({xx,yy});
                                sumPop += arr[xx][yy];
                            }
                        }
                    }
                    if(v.size() > 1){
                        movement++;
                        int newPop = sumPop / v.size();
                        for(auto p : v){
                            arr[p.first][p.second] = newPop;
                        }
                    }
                }
            }
        }
        if(movement == 0) break;
        cnt++;
    }
    cout << cnt;
}
