#include <bits/stdc++.h>
using namespace std;

int main(){

   
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    long long cnt=0;
    
    do{
      long long cur=0;
      for(int i=0;i<N-1;i++)
      cur+=abs(arr[i]-arr[i+1]);
      
      cnt=max(cnt,cur);
      
      
    }while(next_permutation(arr.begin(),arr.end()));
    cout <<cnt;
  
    
    
    
    
    
    
    
    
}
