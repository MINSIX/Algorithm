#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;

int N, M, W;
vector<ti> edges;
vector<long long> dist;
const long long INF = 1e9;

void solve() {
    for (int i = 1; i <= N; i++) {
        for (auto e : edges) {
            int a, b, weight;
            tie(a, b, weight) = e;
            if (dist[b] > dist[a] + weight) {
                dist[b] = dist[a] + weight;
                if (i == N) {
                    cout << "YES" << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;

        int a, b, weight;
        edges.clear();
        dist.resize(N + 1);
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> weight;
            edges.push_back(make_tuple(a, b, weight));
            edges.push_back(make_tuple(b, a, weight));
        }
        for (int i = 0; i < W; i++) {
            cin >> a >> b >> weight;
            edges.push_back(make_tuple(a, b, -weight));
        }
        solve();
    }
    return 0;
}