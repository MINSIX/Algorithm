#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;
int V, E; //V는 정점개수, E는 간선개수
vector<int> group;

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
    int a, b, c;
        
    cin >> V >> E;
    group.resize(V + 1);
    for (int i = 1; i <= V; i++)
        group[i] = i;
    vector<vector<int>> MST;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        MST.push_back({c,a,b });

    }
    sort(MST.begin(), MST.end());
  
    int cnt = 0, ans = 0;

    for (auto& ed : MST) {
        if (getGroup(ed[1]) == getGroup(ed[2]))
            continue;
        joinGroup(ed[1], ed[2]);
        ans += ed[0];
        cnt++;
        if (cnt == V - 1)
            break;
    }

    cout << ans << endl;


}