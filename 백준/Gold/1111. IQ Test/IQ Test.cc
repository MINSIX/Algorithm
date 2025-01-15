#include<bits/stdc++.h>
using namespace std;

int main(){
 int N;
 cin >> N;
 vector<int>arr(N);
 for(int i=0;i<N;i++)
 cin >>arr[i];
 
 
 if(N==1)
 {
   cout << "A";
   return 0;
 }
  if(N==2){
    if(arr[0]==arr[1])
    cout << arr[1];
    else
    cout<<"A";
    return 0;
  }
  int a=0;
  
  if(arr[1]-arr[0]!=0)
  a=(arr[2]-arr[1])/(arr[1]-arr[0]);
  int b = arr[1]-arr[0]*a;
  for(int i=1;i<N;i++){
    if(arr[i]!=arr[i-1]*a+b)
    {
      cout << "B";
      return 0;
    }
    
  }
  cout << arr[N-1]*a+b;
  
  
}