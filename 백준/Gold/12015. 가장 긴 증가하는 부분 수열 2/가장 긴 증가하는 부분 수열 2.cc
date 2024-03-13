#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A;
    cin >> A;
    vector<int> arr(A);
    for (int i = 0; i < A; i++)
        cin >> arr[i];

    vector<int> lis;
    for (int i = 0; i < A; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end())
            lis.push_back(arr[i]);
        else
            *it = arr[i];
    }
    
    cout << lis.size() << endl;

    return 0;
}
