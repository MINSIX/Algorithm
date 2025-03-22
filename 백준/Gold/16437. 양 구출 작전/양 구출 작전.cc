#include<bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int N;
  cin >> N;
  char ani;
  long long a,b;
  
  char animals[N+1];
  long long values[N+1];
  vector<int> mom[N+1];
  long long save[N+1];
  for(int i=2;i<=N;i++)
  {
    cin >> ani >> a>>b;

    animals[i]=ani;
    values[i]=a;
    mom[b].push_back(i);
  }
  animals[1]='S';
  values[1]=0;
  vector<bool> visited(N+1,false);
  stack<pair<int,bool>>st;
  st.push({1,false});
  visited[1]=true;
  
  while(!st.empty()){
    int now = st.top().first;
    bool visiting=st.top().second;
    if(!visiting){
      st.top().second=true;
      
      for(auto it:mom[now]){
        if(!visited[it]){
          visited[it]=true;
          st.push({it,false});
        }
      }
      
    }else{
      long long nowsum=0;
      for(int it : mom[now]){
        nowsum+=save[it];
      }
      if(animals[now]=='W')
        nowsum=max(0LL,nowsum-values[now]);
      else
      nowsum+=values[now];
      
      save[now]=nowsum;
      
      st.pop();
      
    }
    
    
  }
  cout << save[1];
  
  
  
}