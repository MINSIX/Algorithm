#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N, K,M;
int arr[1001];
int xx[1001];
int cnt=1;
int cal(int t) {
   
    for (int i = 1; i <= N; i++) {
        xx[i] = 1;
        for (int j = i-1; j >0; j--) {
            
            if (arr[j] < arr[i])
            {
                xx[i] = max(xx[i], xx[j] + 1);
        
            }
        }
    }
    int ans = xx[1];


    for (int i = 1; i < N ; i++) {
        ans = max(xx[i + 1], ans);
    }
    return ans;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
   
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cout << cal(N)<<endl;


    return 0;
}



