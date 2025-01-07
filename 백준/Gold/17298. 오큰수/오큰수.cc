#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), result(N, -1); 
    stack<int> s;

    for (int i = 0; i < N; i++) {
        cin >> A[i];

        while (!s.empty() && A[s.top()] < A[i]) {
            result[s.top()] = A[i];
            s.pop();
        }

        s.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}
