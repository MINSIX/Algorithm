#include <bits/stdc++.h>
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
    vector<int> lis_index(A, -1);
    for (int i = 0; i < A; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) {
            lis.push_back(arr[i]);
            lis_index[i] = lis.size() - 1;
        }
        else {
            *it = arr[i];
            lis_index[i] = it - lis.begin();
        }
    }

    int length = lis.size();
    vector<int> result;
    for (int i = A - 1; i >= 0 && length > 0; i--) {
        if (lis_index[i] == length - 1) {
            result.push_back(arr[i]);
            length--;
        }
    }

    reverse(result.begin(), result.end());

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
