#include<bits/stdc++.h>
using namespace std;
vector<int>isPrime(1000001,true);

int main(){
  
  int N;
  cin >> N;
  if(N<8){
  cout << -1;
  return 0;
    
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i * i <= N; i++) {
      if (isPrime[i]) {
          for (int j = i * i; j <= N; j += i) {
              isPrime[j] = false;
          }
      }
  }
  
  vector<int> answer;
  if(N%2){
    answer.push_back(2);
    answer.push_back(3);
    N-=5;
    for(int i=2;i<=N+5;i++){
      if(isPrime[i]&&isPrime[N-i])
      {
        answer.push_back(i);
        answer.push_back(N-i);
        break;
      }
    }
  }else{
    answer.push_back(2);
    answer.push_back(2);
    N-=4;
    
    for(int i=2;i<=N+4;i++){
      if(isPrime[i]&&isPrime[N-i])
      {
        answer.push_back(i);
        answer.push_back(N-i);
      break;
        
      }
    }
  }
  for(auto k : answer)
  cout<<k<<" ";
  
  
}