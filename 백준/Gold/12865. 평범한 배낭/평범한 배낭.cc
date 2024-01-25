
#include<bits/stdc++.h>
using namespace std;



int cal (int a, int b) {
    if (a > b)
        return a;

    else
        return b;
   


}

int N, K;
stack<pair<int, int>> pre;
int arr[101][100001] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
        cin >> N>>K;
        int t,v;
        for (int i = 0; i < N; i++)
        {
            cin >> t >> v;
            arr[i][0] = 0;
            arr[0][i] = 0;
            pre.push(make_pair(t, v));
        }
        int noww;
        int nowv;
        for (int i = 1; i <= N; i++) {
            noww = pre.top().first;
            nowv = pre.top().second;

            pre.pop();
            for (int w = 1; w <= K; w++) {
                if (noww > w) {
                    arr[i][w] = arr[i - 1][w];
                }else{
                    arr[i][w] = cal(arr[i - 1][w], arr[i - 1][w-noww]+ nowv );
                }

            }

        }
        cout << arr[N][K] << endl;

    return 0;
}



