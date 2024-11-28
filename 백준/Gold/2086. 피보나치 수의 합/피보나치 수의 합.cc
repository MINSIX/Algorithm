#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000000;

map<long long, long long> sv;

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
  long long a,b;
  cin >> a>>b;
  
  cout << (fibo(b+2)%MOD-fibo(a+1)%MOD + MOD) % MOD; 
  
  
  
  
}