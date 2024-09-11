#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int st = 0;
        int ed = N - 1;
        while (st < ed) {
            if (st == i) {
                st++;
                continue;
            }
            if (ed == i) {
                ed--;
                continue;
            }
            if (arr[st] + arr[ed] == arr[i]) {
                cnt++;
                break;
            }
            else if (arr[st] + arr[ed] < arr[i]) {
                st++;
            } else {
                ed--;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
