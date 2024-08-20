#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >>N;cin >> M;
  vector<vector<int>>par(N+1);
  vector<int>val(N+1,0);
  int t;

  for(int i=1;i<=N;i++)
  {
    cin >> t;
    if(t==-1)
    continue;
    par[t].push_back(i);
  }
  int a,b;
  for(int i=0;i<M;i++)
  {
    cin >> a>>b;
    val[a]+=b;
   
    
    
  }  
  stack<int> st;
    st.push(1);
    while(!st.empty()){
      int now=st.top();
   
      st.pop();
      for(auto k : par[now]){
    
        val[k]+=val[now];
        st.push(k);
        
        
      }
    }
  for(int i=1;i<=N;i++)
  cout << val[i]<<" ";
}