#include <bits/stdc++.h>
using namespace std;

vector<long long> arr;
string num = "0123456789";

void solve(int index, string tmp) {
    if (!tmp.empty()) {
        string ttmp = tmp;
        reverse(ttmp.begin(), ttmp.end());
        arr.push_back(stoll(ttmp));
    }
    for (int i = index + 1; i < 10; i++) {
        tmp += num[i];
        solve(i, tmp);
        tmp.pop_back();
    }
}

int main(){
    int N;
    cin >> N;
    for (int i = 0; i < 10; i++) {
        string tmp = "";
        solve(i, tmp += num[i]);
    }
    sort(arr.begin(), arr.end());
    if (N > arr.size())
        cout << -1;
    else
        cout << arr[N - 1];
}
