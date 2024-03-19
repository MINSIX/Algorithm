#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int N, M;
const int INF = 1e09;
vector<int> group;
//bool myf(vector<int>& i, vector<int>& j){
//
//    
//
//
//
//    return i[2] < j[2];
//
//
//}
int getGroup(int n) {
    if (group[n] == n)
        return n;
    return group[n] = getGroup(group[n]);
}

void joinGroup(int a, int b) {
    a = getGroup(a);
    b = getGroup(b);
    if (a > b)
        swap(a, b);
    group[b] = a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int a, b, c;
    vector<vector<int>> load;
    group.resize(N + 1);
    for(int i=1;i<=N;i++)
        group[i] = i;
    for (int i = 0; i < M; i++) {
        
        cin >> a >> b >> c;
        load.push_back({c, a,b });
    }
    sort(load.begin(), load.end());
    int cnt = 0, ans = 0;
    for (auto& ed : load) {
        if (cnt == N - 2)
            break;
        if (getGroup(ed[1]) == getGroup(ed[2]))
            continue;
        joinGroup(ed[1], ed[2]);
        ans += ed[0];
        cnt++;
     
    }
    cout << ans << endl;
    return 0;
}



