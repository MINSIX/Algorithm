#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> answer;
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

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u != 0)
            answer.push_back(u);

        // 현재 정점과 연결된 간선 제거
        for (int v : graph[u]) {
            indegree[v]--;
            
            if (indegree[v] == 0) {
                q.push(v);
            
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    map<pair<int,int>, int> check;

    int cnt;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> cnt;
        cin >> a;
        for (int j = 0; j < cnt - 1; j++)
        {
            cin >> b;
         
            if (check[{a, b}] == 0)
            graph[a].push_back(b);
            check[{a, b}]++;
            a = b;
        }
    }

    
 
    // 위상 정렬 수행
    topologicalSort(graph);
    if (answer.size() != N)
        cout << 0;
    else
        for (int i : answer) {
            cout << i << endl;
        }


}