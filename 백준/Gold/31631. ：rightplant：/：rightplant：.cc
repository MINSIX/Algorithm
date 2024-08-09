#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int>arr(N+1);
  
  
  
  if(N==2)
  {
    cout << "1 2";
    return 0;
  }

  for(int i=1;i<=N/2;i++){
    if(i%2==1){
      arr[i]=N-i*2+2;
      arr[N-i+1]=N-i*2+1;
    }else{
      arr[i]=N-i*2+1;
      arr[N-i+1]=N-i*2+2;
    }
    
  }
  if(N%2==1)arr[N/2+1]=1;
    for(int i=N;i>0;i--){
    cout << arr[i]<<" "; 
  }
}

