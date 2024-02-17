#include<bits/stdc++.h>

using namespace std;
int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    vector<int> arrA(n , 0);
    vector<int> arrB(n , 0);
    for (int i = 0; i < n; i++) 
        cin >> arrA[i];
       for (int i = 0; i < n; i++) 
        cin >> arrB[i];
    
       sort(arrA.begin(), arrA.end());
       sort(arrB.begin(), arrB.end(),greater<int>());
       int sum = 0;
       for (int i = 0; i < n; i++)
   {
           sum += arrA[i] * arrB[i];
       }
       cout << sum << endl;



 
}