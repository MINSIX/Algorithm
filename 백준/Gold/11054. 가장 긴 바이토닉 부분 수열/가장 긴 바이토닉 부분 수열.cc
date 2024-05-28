
#include<bits/stdc++.h>
using namespace std;

int N, K, M;
int arr[1001];
int xx[1001];
int fdp[1001];
int bdp[1001];
int cnt = 1;
int cal(int t) {
    int sv = 0;
    //가장수열
    for (int i = 1; i <= N; i++) {
        fdp[i] = 1;
        for (int j = i - 1; j > 0; j--) {

            if (arr[j] < arr[i]&&fdp[i]<fdp[j]+1)
            {
                fdp[i] = fdp[j] + 1;

            }
        }
    }
    //가장작아지는수열
    for (int i = N; i >= 1; i--) {
        bdp[i] = 1;
        for (int j = N; j >= i; j--) {

            if (arr[j] < arr[i] && bdp[i] < bdp[j] + 1)
            {
                bdp[i] = bdp[j] + 1;

            }
        }
    }
    int ans = 0;


    for (int i = 1; i <= N; i++) {
      
        if (ans < fdp[i] + bdp[i] - 1)ans = fdp[i] + bdp[i] - 1;
    }
    return ans;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cout << cal(N) << endl;


    return 0;
}



