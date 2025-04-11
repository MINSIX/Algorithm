#include<bits/stdc++.h>
using namespace std;

int main(){
  
  
  int M;
  cin >> M;
  int arr[4]={0,};
  arr[1]=1;
  for(int i=0;i<M;i++){
    int a,b;
    cin >>a>>b;
    
    swap(arr[a],arr[b]);
  }
  
  for(int i=1;i<=3;i++)
  if(arr[i])
  cout << i;
  
  
}