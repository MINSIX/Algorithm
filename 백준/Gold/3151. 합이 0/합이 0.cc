#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int>arr(N);
  for(auto &i : arr)
  cin >>i;
  
  sort(arr.begin(),arr.end());
  

  long long cnt=0;
  for(int i=0;i<N-2;i++){
      int a=i+1;
      int b=N-1;
      long long cal=0;
    while(a<b){
      if(arr[i]+arr[a]+arr[b]==0){
        if(arr[b]==arr[a])
        {
          cnt+=b-a;
        }else{
          if(cal==0){
          int index=b;
          while(index>a&&arr[i]+arr[a]+arr[index--]==0){
            cal++;
          }}
          cnt+=cal;
          
        }
        a++;
      }else if(arr[i]+arr[a]+arr[b]<0){
        a++;
        cal=0;
      }else{
        b--;
        cal=0;
      }
      
    } 
  }
  
  cout << cnt;
  
}