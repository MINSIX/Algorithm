#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<vector<int>> arr(N + 1);

  for(int i = 1; i <= N; i++){
    int a, b;
    cin >> a;
    for(int j = 0; j < a; j++){
      cin >> b;
      arr[i].push_back(b);
      arr[b].push_back(i);
    }
  }

  vector<int> team(N + 1, -1);
  bool is_bipartite = true;

  for(int start = 1; start <= N; start++){
    if(team[start] == -1){ 
      queue<int> q;
      team[start] = 0;
      q.push(start);

      while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto k : arr[now]){
          if(team[k] == -1){
            team[k] = 1 - team[now];
            q.push(k);
          } else if(team[k] == team[now]){
            is_bipartite = false; 
          }
        }
      }
    }
  }

  if(!is_bipartite){
    cout << "0\n";
    return 0;
  }

  vector<int> blue;
  vector<int> red;
  for(int i = 1; i <= N; i++){
    if(team[i] == 0)
      blue.push_back(i);
    else
      red.push_back(i);
  }

  cout << blue.size() << "\n";
  for(int i = 0; i < blue.size(); i++){
    cout << blue[i] << " ";
  }
  cout << "\n";

  cout << red.size() << "\n";
  for(int i = 0; i < red.size(); i++){
    cout << red[i] << " ";
  }

}
