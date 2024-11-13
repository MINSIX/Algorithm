#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K, M;
  cin >> N >> K >> M;

  vector<vector<int>> arr(N + 1);          
  vector<vector<int>> hyper(M + 1);         

  for (int i = 0; i < M; i++) {
    vector<int> check(K);                  
    for (int j = 0; j < K; j++) {
      cin >> check[j];
      arr[check[j]].push_back(i);          
      hyper[i].push_back(check[j]);       
    }
  }

  queue<pair<int, int>> q;
  q.push({1, 1});
  vector<bool> visited(N + 1, false);       
  vector<bool> visitedHyper(M + 1, false); 
  visited[1] = true;

  while (!q.empty()) {
    int nowstation = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (nowstation == N) {                  
      cout << cnt;
      return 0;
    }

    for (int h : arr[nowstation]) {
      if (visitedHyper[h]) continue;
      visitedHyper[h] = true;

     
      for (int nextStation : hyper[h]) {
        if (visited[nextStation]) continue;
        visited[nextStation] = true;
        q.push({nextStation, cnt + 1});
      }
    }
  }

  cout << -1;  
}
