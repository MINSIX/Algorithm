#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;


long long NK(long long N, long long K){
  long long result=1;
  while(K){
    if(K&1) result=(result*N)%MOD;
    N=(N*N)%MOD;
    K>>=1;
  }
  
  return result;
  
}



int main(){
  

  long long N, K;
  cin >> N >> K;
  
  vector<long long> fact(N+1),refact(N+1);
  
  fact[0]=1;
  for(int i=1; i<=N;i++)
    fact[i]=fact[i-1]*i%MOD;
  
  refact[N]=NK(fact[N],MOD-2);
  for(int i=N-1;i>=0;i--)
  refact[i]=refact[i+1]*(i+1)%MOD;
  
  long long answer=fact[N];
  answer=(answer*refact[K])%MOD;
  
  answer=(answer*refact[N-K])%MOD;
  cout << answer;
  
}