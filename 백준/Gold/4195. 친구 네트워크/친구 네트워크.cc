#include <bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionNodes(int u, int v, vector<int>& parent, vector<int>& size) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (pu != pv) {
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int F;
        cin >> F;

        map<string, int> mt;
        vector<int> parent;
        vector<int> size;
        int now = 0;

        for (int i = 0; i < F; i++) {
            string s, y;
            cin >> s >> y;

            if (mt.find(s) == mt.end()) {
                mt[s] = now++;
                parent.push_back(mt[s]);
                size.push_back(1);
            }

            if (mt.find(y) == mt.end()) {
                mt[y] = now++;
                parent.push_back(mt[y]);
                size.push_back(1);
            }

            unionNodes(mt[s], mt[y], parent, size);

            int groupSize = size[findParent(mt[s], parent)];
            cout << groupSize << "\n";
        }
    }

    return 0;
}
