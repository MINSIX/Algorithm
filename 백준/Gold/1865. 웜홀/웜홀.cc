#include<bits/stdc++.h>
using namespace std;
int TC;
const int INF = 99999;
int N, M, W;
vector < tuple<int, int, int>>arr;
vector<long long>dist;
void solve() {
    for (int i = 1; i <= N; i++) {
        for (auto e : arr) {
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
    cin >> TC;
    while (TC-- > 0) {

        cin >> N >> M >> W;
        int s, e, t;
        arr.clear();
        dist.resize(N + 1);


        for (int i = 0; i < M; i++) {
            cin >> s >> e >> t;
            arr.push_back(make_tuple( s,e,t ));
            arr.push_back(make_tuple(e, s, t));



        }
        for (int i = 0; i < W; i++) {
            cin >> s >> e >> t;
            arr.push_back(make_tuple(s, e, -t));
        }

        solve();


    }

}
