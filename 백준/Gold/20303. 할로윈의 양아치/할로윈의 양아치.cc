#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N,M,K;
    cin >> N >> M >> K;
    
    vector<int> arr(N+1); // 사탕 개수
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    vector<vector<int>> connect(N+1);
    int a,b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    
    vector<bool> visited(N+1, false);
    vector<pair<int, int>> groups;
    
    for(int i=1; i<=N; i++){
        if(visited[i]) continue;
        
        queue<int> q;
        q.push(i);
        visited[i] = true;
        int localCnt = 0;
        int localConnect = 0;
        
        while(!q.empty()){
            int now = q.front();
            q.pop();
            localCnt += arr[now];
            localConnect++;
            
            for(auto k : connect[now]){
                if(visited[k]) continue;
                visited[k] = true;
                q.push(k);
            }
        }
        
        groups.push_back({localCnt, localConnect});
    }
    
    int n = groups.size();
    vector<vector<int>> dp(n+1, vector<int>(K+1, 0));
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=K; j++){
            if(j > groups[i-1].second){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-groups[i-1].second] + groups[i-1].first);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[n][K] << '\n';
    
    return 0;
}