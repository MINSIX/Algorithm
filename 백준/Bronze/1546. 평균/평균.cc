#include<bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    vector<double>arr(a);
    double sum = 0;
    double max1 = 0;
    for (int i = 0; i < a; i++){
        cin >> arr[i];
        sum += arr[i];
        max1 = max(max1, arr[i]);
    }
    cout << (double)((sum/(max1*a))* 100) << endl;
}