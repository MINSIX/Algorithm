#include<bits/stdc++.h>
using namespace std;
int N, M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;


    vector<vector<int>> arr(N + 1, vector<int>(M + 1));
    string a[101];
    map<string, int> mp;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        ++mp[a[i]];
    }
    int K;
    cin >> K;
    int cnt=0;
    for (int i = 1; i <=N; i++) {
        int c = 0;
        for (int j = 0; j < M; j++) 
            if (a[i][j] == '0') c++;
        if (c > K || c %2 != K %2) 
            continue;
        
        cnt = max(cnt, mp[a[i]]);
    }
    cout << cnt << endl;
        return 0;
}
