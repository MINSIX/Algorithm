#include<bits/stdc++.h>
using namespace std;

int main(){
   int limit = 1000;
    vector<bool> pp(limit + 1, true);

    pp[0] = pp[1] = false;

    for (int i = 2; i * i <= limit; ++i) {
        if (pp[i]) {
            for (int j = i * i; j <= limit; j += i) {
                pp[j] = false;
            }
        }
    }
 int N;
 cin >> N;
 int cnt=0;
  int a;
 for(int i=0;i<N;i++){
 cin >>a;
 if(pp[a])
 cnt++;
   
 }
  cout << cnt;
}
