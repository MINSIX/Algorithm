#include<bits/stdc++.h>
using namespace std;
map<long long, long long> sv;
const int MOD =  1000000007;
long long fibo(long long N){
  
 if (N == 0) return sv[N]=0;
  if (N == 1) return sv[N]=1;
  if(N==2)return sv[N]=1;
  
  if(sv[N])return sv[N];
  
  
  
  
  if(N%2==0)
    return sv[N] = ((fibo(N/2)*(fibo(N/2+1)+fibo(N/2-1)))%MOD)%MOD;
  else
    return sv[N]=(((fibo((N+1)/2) * fibo((N+1)/2))%MOD)+((fibo((N-1)/2)*fibo((N-1)/2))%MOD)%MOD)%MOD;
}


int main(){
  
  
  long long N;
  cin >> N;
  
  cout << fibo(N);
  
}