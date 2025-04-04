#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

struct tri {
    int x, y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    int cheeseCount = 0;
  
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) cheeseCount++;
        }
    }
  
    int tt = 0;
    int last = 0;
  
    while(cheeseCount > 0){
        last = cheeseCount;
        tt++;
        
        vector<vector<bool>> visited(N, vector<bool>(M,false));
        queue<tri> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            q.pop();
            
            for(int i=0; i<4; i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx<0 || yy<0 || xx>=N || yy>=M) continue;
                if(visited[xx][yy]) continue;
                if(arr[xx][yy] == 0){
                    visited[xx][yy] = true;
                    q.push({xx, yy});
                }
            }
        }
        
        vector<pair<int,int>> melt;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == 1){
                    for(int k=0; k<4; k++){
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if(xx<0 || yy<0 || xx>=N || yy>=M) continue;
                        if(visited[xx][yy] && arr[xx][yy] == 0){
                            melt.push_back({i, j});
                            break;
                        }
                    }
                }
            }
        }
        
        for(auto &p : melt){
            arr[p.first][p.second] = 0;
        }
        
        cheeseCount -= melt.size();
    }
  
    cout << tt << "\n" << last << "\n";
}
