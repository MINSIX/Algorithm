#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m;


void topologicalSort(vector<vector<int>>& graph) {
    int V = graph.size(); // 정점의 수
    vector<int> indegree(V, 0); // 진입 차수를 저장하는 배열
    queue<int> q; // 진입 차수가 0인 정점을 저장하는 큐

    // 각 정점의 진입 차수 계산
    for (int u = 0; u < V; ++u) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }

    // 진입 차수가 0인 정점을 큐에 추가
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 위상 정렬 수행
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 0)
            ;
        else
        cout << u << " ";

        // 현재 정점과 연결된 간선 제거
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    vector<vector<int>>graph(n+1);

    int a, b;
    for (int i = 0;i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }


    topologicalSort(graph);


}



