#include<bits/stdc++.h>
using namespace std;




int main(){
  int N;
  cin >> N;
  vector<vector<int>>arr(N);
  int a;
  int root;
  vector<int>par(N);
  for(int i=0;i<N;i++){
    cin >>a;
    par[i]=a;
    if(a==-1)
    root=i;
    else
    arr[a].push_back(i);
    
    
  }
  int del;
  cin >>del;
  stack<int>st;
  st.push(del);
  int cnt=0;
  if(arr[par[del]].size()==1)
  cnt++;
  while(!st.empty()){
    int now=st.top();
    st.pop();
   
    for(auto k : arr[now]){
      st.push(k);
      
    }
    arr[now].clear();
    
  }

  st.push(root);
  while(!st.empty()){
    int now=st.top();
    st.pop();

    if(arr[now].size()==0){
      cnt++;
    }else{
      
      for(auto k : arr[now]){
        st.push(k);
        
      }
    }
    
    
  }

  
  cout <<cnt-1;
  
  
  
}