#include <bits/stdc++.h>
using namespace std;
int N;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    vector<int> Rsum(N+1,0);
    vector<int> Bsum(N+1,0);


    Rsum[1] = arr[1];
    Bsum[N] = arr[N];
    for (int i = 2; i <= N; i++)
    {
       

        Rsum[i] = max(Rsum[i - 1],arr[i]);
    
        }
    Bsum[N] = arr[N];
    for (int i = N-1; i > 0; i--)
    {
        

        Bsum[i] = max(Bsum[i + 1], arr[i]);
    }

    int rcnt = 0;
    int bcnt = 0;
    for (int i = 1; i <= N; i++) {
        if (Rsum[i] > Bsum[i])
            rcnt++;
        else if (Rsum[i] == Bsum[i])
            ;
        else
            bcnt++;

    }
    if (rcnt > bcnt)
        cout << "R" << endl;
    else if(rcnt<bcnt)
        cout << "B" << endl;
    else
        cout << "X" << endl;
}