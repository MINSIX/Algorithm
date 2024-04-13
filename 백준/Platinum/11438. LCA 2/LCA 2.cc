#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005; // 최대 노드의 수
const int LOG_MAXN = 20; // log2(MAXN) + 1

vector<int> adj[MAXN]; // 인접 리스트
int parent[MAXN][LOG_MAXN]; // 부모 노드를 저장하는 배열
int depth[MAXN]; // 각 노드의 깊이를 저장하는 배열

// DFS로 깊이와 부모 노드 계산
void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node][0] = par;
    for (int i = 0; i < adj[node].size(); ++i) {
        int next = adj[node][i];
        if (next != par)
            dfs(next, node, d + 1);
    }
}

// 부모 노드 배열 채우기
void fillParent(int n) {
    for (int j = 1; j < LOG_MAXN; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

// LCA를 찾는 함수
int findLCA(int u, int v) {
    // u와 v의 깊이를 맞춤
    if (depth[u] > depth[v]) swap(u, v);

    // 깊이를 맞춘 후, v를 LCA의 깊이까지 올림
    for (int i = LOG_MAXN - 1; i >= 0; --i) {
        if (depth[v] - (1 << i) >= depth[u]) {
            v = parent[v][i];
        }
    }

    // u와 v가 같으면 바로 반환
    if (u == v) return u;

    // 공통 조상을 찾음
    for (int i = LOG_MAXN - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; // 노드의 개수
    cin >> N;

    // 인접 리스트 초기화
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 깊이와 부모 노드 계산
    dfs(1, -1, 0);
    fillParent(N);

    int M; // 가장 가까운 공통 조상을 알고싶은 쌍의 개수
    cin >> M;

    // 두 정점 쌍에 대한 가장 가까운 공통 조상 계산 및 출력
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        cout << findLCA(u, v) << '\n';
    }

    return 0;
}
