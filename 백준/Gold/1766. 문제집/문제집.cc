#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> indegree(32001, 0);
void topologicalSort(vector<vector<int>>& graph) {

    priority_queue<int> q; 

  

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(-i);
        }
    }


    while (!q.empty()) {
        int u = -q.top();
        q.pop();
         cout << u << " ";

  
         for (int i = 0; i < graph[u].size(); i++) {
             int next = graph[u][i];
             indegree[next]--;
             if (indegree[next] == 0)q.push(-next);
       }
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    topologicalSort(graph);

    return 0;
}
