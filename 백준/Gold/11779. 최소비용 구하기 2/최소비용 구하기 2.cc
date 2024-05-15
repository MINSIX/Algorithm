#include<bits/stdc++.h>
using namespace std;
int N;
int M;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    cin >> M;
    vector<vector<pair<int, int>>> arr(N + 1);
    vector<int>dist(N+1,INF);

    vector<int>check(N + 1, -1);
    for (int i = 0; i < M; i++) {
        int st, ed, val;
        cin >> st >> ed >> val;
        arr[st].push_back({ ed, val });
    }

    int st, ed;
    cin >> st >> ed;
    int lastsave = 1;
    dist[st] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,st});
    while (!pq.empty()) {
        int dis = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (dis > dist[u]) continue;

        for (auto& it : arr[u]) {
            int nowed = it.first;
            int nowval = it.second;
            if (dist[u] + nowval < dist[nowed]) {
              
                
                dist[nowed] = dist[u] + nowval;
                pq.push({ dist[nowed], nowed });
                check[nowed] = u;
            }
        }
    }

    vector<int> sv;
    for (int node = ed; node != -1; node = check[node])
        sv.push_back(node);
    reverse(sv.begin(), sv.end());


    cout << dist[ed] << endl;
    cout << sv.size() << endl;
    for (int node : sv)
        cout << node << " ";
    cout << endl;


  
}
