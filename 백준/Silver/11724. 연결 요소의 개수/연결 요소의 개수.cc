#include<bits/stdc++.h>

using namespace std;
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
    int a, b;

    cin >> V >> E;
    group.resize(V + 1);
    for (int i = 1; i <= V; i++)
        group[i] = i;
    vector<pair<int,int>> MST;
    for (int i = 0; i < E; i++) {
        cin >> a >> b ;
        MST.push_back({a,b });

    }
    int cnt = 0, ans =1;

    for (auto& ed : MST) {
        if (getGroup(ed.first) == getGroup(ed.second))
            continue;
        joinGroup(ed.first, ed.second);
        if (cnt == V - 1)
            break;
    }


    for (int i = 1; i < V; i++) {
        for (int j = i + 1; j <= V; j++) {
            if (getGroup(i) != getGroup(j))
            {
                ans++;
                joinGroup(i, j);
            }
        }
    }

    cout << ans << endl;


}