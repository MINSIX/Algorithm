#include<bits/stdc++.h>
using namespace std;

int arr[4]={2,3,5,7};
bool isPrime(int n){
  if(n< 2) return false;
  for(int i=2;i<n;i++)
  if(n%i==0)return false;
  return true;
}

void dfs(int first, int cnt){
  if(cnt==0){
    cout << first<<"\n";
    return ;
  }
  for(int i=1;i<10;i+=2){
    int cur=first*10+i;
    if(isPrime(cur)==true)
    dfs(cur,cnt-1);
  }
  
}

int main(){
  
  
  int N;
  cin >> N;
   
  
  for(int i=0;i<4;i++){
    dfs(arr[i],N-1);
  }
  
  
  
  
}