#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int N;

int result=0, edp=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int a, b, c;
    vector<pair<int, int>> node[10002];
   bool visited[10002] = { false, };
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >> c;

        node[a].push_back({ b,c });
        node[b].push_back({ a,c });


    }
    stack<pair<int, int>> dfs;

    dfs.push({ 1,0 });
    visited[1] = true;
    while (!dfs.empty())
    {
        int now = dfs.top().first;
        int len = dfs.top().second;
        dfs.pop();
        visited[now] = true;

        if (result < len) {
            result = len;
            edp = now;
        }
        
        for (int i = 0; i < node[now].size(); i++) {
          if(!visited[node[now][i].first])
            dfs.push({ node[now][i].first,len + node[now][i].second });



        }

    }
    result = 0;
    memset(visited, false, sizeof(visited));
    dfs.push({ edp,0 });
    visited[edp] = true;
    while (!dfs.empty())
    {
        int now = dfs.top().first;
        int len = dfs.top().second;
        dfs.pop();


    
        visited[now] = true;
        if (result < len) {
            result = len;
            edp = now;
        }

        for (int i = 0; i < node[now].size(); i++) {
            if (!visited[node[now][i].first])
            dfs.push({ node[now][i].first,len + node[now][i].second });



        }

    }
    cout << result << endl;
    return 0;}
