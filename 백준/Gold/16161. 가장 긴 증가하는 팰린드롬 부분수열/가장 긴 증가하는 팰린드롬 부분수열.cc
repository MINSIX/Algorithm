#include<bits/stdc++.h>

using namespace std;
int N,M;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<int>arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int mm = 0;


    for (int i = 1; i < N - 1; i++) {
        int now = 1;
        int cnt = 1;
        int sv =arr[i];
        while (i - now >= 0 && i + now < N) {
            if (arr[i - now] == arr[i + now]&&sv>arr[i-now]) {
                sv = arr[i - now];
                cnt+=2;
                now++;
                mm = max(mm, cnt);

            }
            else {
           
                mm = max(mm, cnt);
                break;
            }
        }
    }
    for (int i = 1; i < N - 1; i++) {
        int now = 0;
        int cnt = 0;
        int sv = 1000000007;
        while (i - now >= 0 && i + now+1 < N) {
            if (arr[i - now] == arr[i+1 + now]&&sv>arr[i-now]) {
                sv = arr[i - now];
                cnt+=2;
                now++;
               
                mm = max(mm, cnt);

 
            }
            else {
        
                mm = max(mm, cnt);
                break;
            }
        }
    }
    cout << mm;


}
