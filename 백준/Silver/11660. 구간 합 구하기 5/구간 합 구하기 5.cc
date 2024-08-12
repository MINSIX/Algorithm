#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> arr(N+1, vector<int>(N+1, 0));
    vector<vector<int>> Sum(N+1, vector<int>(N+1, 0));
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }
    

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            Sum[i][j] = arr[i][j] + Sum[i-1][j] +Sum[i][j-1] -Sum[i-1][j-1];
        }
    }
    
    while(M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
      
        cout << Sum[x2][y2] - Sum[x1-1][y2] -Sum[x2][y1-1] + Sum[x1-1][y1-1]         << "\n";
    }
    
    return 0;
}