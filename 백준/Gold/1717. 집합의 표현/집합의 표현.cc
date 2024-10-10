#include<bits/stdc++.h>
using namespace std;
int group[1000001];


int getGroup(int n) {
    if (group[n] == n)
        return n;
    return group[n] = getGroup(group[n]);
}

void joinGroup(int a, int b) {
    a = getGroup(a);
    b = getGroup(b);
    if (a > b)
        swap(a, b);
    group[b] = a;
}

int main(){
  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int N,M;
  cin >>N>>M;
  for(int i=0;i<=N;i++)
  group[i]=i;
  int a,b,c;
  for(int i=0;i<M;i++){
    cin >>a>>b>>c;
    
    if(a==1)
  {
    if(getGroup(b)==getGroup(c))
    cout <<"YES\n";
    else
    cout<<"NO\n";
    
  }else{
    joinGroup(b,c);
    
  }
    
  }
  
  
}