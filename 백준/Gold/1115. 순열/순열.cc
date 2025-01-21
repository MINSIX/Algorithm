#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  vector<int> check(N);
  vector<int> arr(N);
  for(int i=0;i<N;i++)
  cin >>arr[i];
  vector<bool>visit(N,false);
  int cnt=0;
  for(int i=0;i<N;i++){
  if(!visit[i]){
  stack<int> st;
  st.push(i);
  
  while(!st.empty()){
    int now = st.top();
    st.pop();
    if(visit[now])
    continue;
    
    visit[now]=true;
    if(!visit[arr[now]])
    st.push(arr[now]);
    
  }
  cnt++;
  }  
  }
  if(cnt==1)
  cout << 0;
  else
  cout << cnt;
}