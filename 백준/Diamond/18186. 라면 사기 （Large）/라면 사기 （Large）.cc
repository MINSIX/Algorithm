#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  
    int N;
    long long b,c;
    cin >> N>>b>>c;
    vector<int> arr(N+1, 0);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
  
    if(b<=c)
    {
      long long sum=0;
      for(int i=1;i<=N;i++){
        sum+=arr[i];
      }
      cout << sum*b;
      return 0;
    }
    
    long long cnt = 0;
    for (int i = 1; i <= N-2; i++) {
        long long mini;
        if (arr[i+1] <= arr[i+2]) {
            mini = min({arr[i], arr[i+1], arr[i+2]});
            cnt += (b+2*c) * mini;
            arr[i] -= mini;
            arr[i+1] -= mini;
            arr[i+2] -= mini;
          
            mini = min(arr[i], arr[i+1]);
            cnt += (b+c) * mini;
            arr[i] -= mini;
            arr[i+1] -= mini;
          
            cnt += b * arr[i];
        } else {
            mini = min(arr[i+1] - arr[i+2], arr[i]);
            cnt += (b+c) * mini;
            arr[i] -= mini;
            arr[i+1] -= mini;
          
            mini = min({arr[i], arr[i+1], arr[i+2]});
            cnt += (b+2*c) * mini;
            arr[i] -= mini;
            arr[i+1] -= mini;
            arr[i+2] -= mini;
          
            cnt += b * arr[i];
        }
    }
  

    long long mini = min(arr[N-1], arr[N]);
    cnt += (b+c) * mini;
    arr[N-1] -= mini;
    arr[N] -= mini;
    cnt += b* arr[N-1] + b * arr[N];
  
    cout << cnt << "\n";
    return 0;
}