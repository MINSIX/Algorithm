#include<bits/stdc++.h>
using namespace std;

vector<int> queen;

bool check(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(abs(queen[i] - queen[j]) == abs(i - j))
                return false;
        }
    }
    return true;
}

int solution(int n) {
    int cnt = 0;
    queen.resize(n);
    
    for(int i = 0; i < n; i++)
        queen[i] = i;
    

    do {
        if(check(n))
            cnt++;
    } while(next_permutation(queen.begin(), queen.end()));
    
    return cnt;
}