#include <bits/stdc++.h>
using namespace std;
int N;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    long long stst, eded;
    long long nownow;
    long long nowval = LONG_MAX;

    for (int now = 0; now < N - 2; now++) {
        int st = now + 1;
        int ed = N-1;


        while (st < ed) {
            long long sum = arr[st] + arr[ed] + arr[now];
            if (nowval > abs(sum)) {
                nowval = abs(sum);
                stst = arr[st];
                eded = arr[ed];
                nownow = arr[now];
            }
            if (sum > 0)
                ed--;
            else
                st++;

        }
    }
        
        cout << nownow << " " << stst <<" " << eded;


}