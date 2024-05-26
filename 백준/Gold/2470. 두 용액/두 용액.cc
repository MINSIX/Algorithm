#include <bits/stdc++.h>
using namespace std;
int N;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int stst, eded;
    int nowval = INT32_MAX;
      int st = 0;
        int ed = N - 1;
        while (st < ed) {
            int sum = arr[st] + arr[ed];
            if (nowval > abs(sum)) {
                nowval=abs(sum);
                    stst=arr[st];
                    eded=arr[ed];
            }
            if(sum>0)
                ed--;
            else
                st++;

        }
        cout << stst << " " << eded;


}