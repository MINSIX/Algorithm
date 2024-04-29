#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> arr(N + 1);


    for (int i = 0; i < M; i++) {
        int st, ed, val;
        cin >> st >> ed >> val;
        arr[st].push_back({ ed, val });
    }

    int st, ed;
    cin >> st >> ed;
    if (st == ed) {
        cout << 0 << endl;
        return 0;
    }


    vector<int> dist(N + 1, INF);
    dist[st] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, st });

    while (!pq.empty()) {
        int dis = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (dis > dist[u]) continue;

        for (auto& it :arr[u]) {
            int nowed = it.first;
            int nowval= it.second;
            if (dist[u] + nowval < dist[nowed]) {
                dist[nowed] = dist[u] + nowval;
                pq.push({ dist[nowed], nowed });
            }
        }
    }

    cout << dist[ed] << '\n';

    return 0;
}
