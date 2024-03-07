#include<bits/stdc++.h>

using namespace std;



int Prime[2000001] = { 0, };
void findPrime(int n) {
    vector<bool> isPrime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
                
            }
        }
    }int i = 0;
    for (int p = 2; p <= n; p++) {
        
        if (isPrime[p]) {
            Prime[i] = p;
            i++;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A;
    cin >> A;
    findPrime(A);

    int i = 0;
    int sum = 0;
    int cnt = 0;
    
  for(int sv=0;Prime[sv]<=A;sv++){
      while(sum<A&&Prime[i]!=0) {
    
        
        sum += Prime[i];
        i++;
      
      }
      if (sum > A) {
          sum = 0;
          i = sv + 1;
      }
      else if (sum == A)
      {
          cnt++;
          sum = 0;
          i = sv + 1;
      }
    }
  cout << cnt;
    
}