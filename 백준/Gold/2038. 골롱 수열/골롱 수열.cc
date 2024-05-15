#include <bits/stdc++.h>
using namespace std;
int N;

const int INF = 1e6+1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    vector<int>arr(INF);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 2;
    
    int index = 4;
    int cnt = 3;
    if (N <= 3) {
        cout << arr[N] << endl;
        
    }else
    for (int i =3; i<INF; i++)
    {
        
        cnt += arr[i];
        if (cnt >= N)
        {
            cout << i << endl;
            return 0;
        } for (int j = 0; j < arr[i]; j++) {

            if (index >= INF)
                break;

            if (index == N) {
                cout << i << endl;
                return 0;
            }
            arr[index++] = i;

            
        }
    
    
    
    }
    return 0;
}