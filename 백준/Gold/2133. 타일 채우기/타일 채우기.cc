#include<bits/stdc++.h>

using namespace std;

int main(){
  
  int N;
  cin >> N;
  vector<long long> arr(N+1);
  if(N%2==1)
  {
    cout << 0;
    return 0;
    
  }
  arr[2]=3;
  for(int i=4;i<=N;i+=2){
    arr[i]=arr[i-2]*3+2;
       for (int j = 4; j < N; j += 2) {
         if(i==j)
         continue;
                arr[i] += 2 * arr[i - j];
            }
    
  }
  
  cout << arr[N];
}