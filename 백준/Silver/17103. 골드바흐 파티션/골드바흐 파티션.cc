#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  const int LIMIT = 1000000;
    vector<bool> isPrime(LIMIT + 1, true); 
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(LIMIT); ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }


  while(T--){
    int N;
    cin >> N;
    int cnt=0;
     for(int i=0;i<=N/2;i++){
      if(isPrime[i]&&isPrime[N-i])
        cnt++;  
  }

  cout << cnt<<"\n";
  }
}