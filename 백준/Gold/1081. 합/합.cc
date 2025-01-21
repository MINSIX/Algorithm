#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>>arr(11,vector<long long>(10));
vector<long long>digits(11);

long long cal(string s){
    int len = s.length();
    int a=0;
    int b=0;
    long long c=0;
    for(int i=0;i<len;i++){
        b = s[i]-'0';
        for(int j=0;j<b;j++){
            c += arr[len - i - 1][j] + (a * (long long)pow(10, len - i - 1));
        }
        a += b;
    }
    return c + a;
}

int main(){
    int L,U;
    cin >> L >> U;
    int cnt = U - L;
    string s = to_string(U);

    for(int i=0; i<10; i++){
        arr[0][i] = i;
    }

    digits[1] = 45;
    for(int i=1; i <= s.length(); i++){
        digits[i] = digits[i-1] * 10 + 45 * (long long)pow(10, i - 1);
        for(int j=0; j<10; j++){
            arr[i-1][j] = digits[i-1] + j * (long long)pow(10, i - 1);
        }
    }

    if(L == 0){
        cout << cal(to_string(U));
        return 0;
      
    }
    
        cout << cal(to_string(U)) - cal(to_string(L - 1));
    
}
