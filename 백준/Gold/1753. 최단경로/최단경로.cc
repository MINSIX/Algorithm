#include<bits/stdc++.h>
using namespace std;

int V, E;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> V >> E;
    int st;
    cin >> st;
    int u, v, w;
    vector<int> dist(V + 1,999999);
    vector<vector<pair<int, int>>>arr(V+1);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        arr[u].push_back({ w,v });

    }
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,st });
    dist[st] = 0;
    while (!pq.empty()) {
        int val = -pq.top().first;
        int now = pq.top().second;

        pq.pop();
        if (dist[now] <  val)continue;
for(auto i:arr[now]){
            int sum = i.first + val;
            int index = i.second;
            if (sum < dist[index]) {
                dist[index] = sum;
                pq.push({ -sum,index });
            }
        }


    }
    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] == 999999) cout << "INF\n";
        else cout << dist[i] << endl;
    }

    return 0;
}
