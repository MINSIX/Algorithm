#include <bits/stdc++.h>
using namespace std;

int main() {

    long long arr[800];
    int N;
    cin >> N;
    arr[0]=0;
    for (int i = 1; i<800; i++) {
        arr[i]= arr[i-1] + i*4 - 3;

    }

    long long dp[1000001];
    for(int i=1;i<=N;i++)
    dp[i]=6;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < 800; j++) {
            if (i >= arr[j])
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            else
                break; 
        }
    }

    cout << dp[N];
}
