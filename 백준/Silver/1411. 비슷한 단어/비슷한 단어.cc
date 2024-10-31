#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int length = arr[0].length();
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            vector<int> check(26, 9999); 
            vector<int> reverse_check(26, 9999);  
            bool asd = true;
            for (int k = 0; k < length; k++) {
                int a = arr[i][k] - 'a';
                int b = arr[j][k] - 'a';
                if (check[a] == 9999 && reverse_check[b] ==9999) {
                    check[a] = b;
                    reverse_check[b] = a;
                }
                else if (check[a] != b || reverse_check[b] != a) {
                    asd = false;
                    break;
                }
            }
            if (asd)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}
