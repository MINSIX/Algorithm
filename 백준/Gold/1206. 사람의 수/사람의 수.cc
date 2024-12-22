#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        double a;
        cin >> a;
        arr[i] = round(a * 1000);
    }
    bool valid = true;
    for (int i = 1; i <= 10000; i++) {
        valid = true;
        for (int avg : arr) {
            int lower_bound = avg;       
            int upper_bound = avg + 1;    

            int lower_sum = (lower_bound * i + 999) / 1000; 
            int upper_sum = (upper_bound * i - 1) / 1000;      

            if (lower_sum > upper_sum) { 
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << i ;
            return 0;
        }
    }

}
