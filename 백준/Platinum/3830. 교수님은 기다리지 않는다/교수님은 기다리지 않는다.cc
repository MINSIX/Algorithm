#include<bits/stdc++.h>
using namespace std;

vector<int> parent, weight_diff;

int find(int x) {
    if (parent[x] == x) return x;
    int root = find(parent[x]);
    weight_diff[x] += weight_diff[parent[x]];
    return parent[x] = root;
}

void union_sets(int a, int b, int w) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parent[rootB] = rootA;
        weight_diff[rootB] = weight_diff[a] - weight_diff[b] + w;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        
        parent.resize(N+1);
        weight_diff.resize(N+1);

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            weight_diff[i] = 0;
        }

        char s;
        int a, b, w;

        for (int i = 0; i < M; i++) {
            cin >> s >> a >> b;
            if (s == '!') {
                cin >> w;
                union_sets(a, b, w);
                continue;
            }
            if (s == '?') {
                if (find(a) != find(b)) {
                    cout << "UNKNOWN\n";
                } else {
                    cout << weight_diff[b] - weight_diff[a] << "\n";
                }
            }
        }
    }
}
