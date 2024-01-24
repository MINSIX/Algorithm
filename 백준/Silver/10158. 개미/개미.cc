#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;


int N, M;
int p, q;
int t;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    cin >> p >> q;
    cin >> t;

    
    int timex = t%(2*N);
    int timey = t % (2*M);

    int nowx = 0;
    int nowy = 0;
    if (timex + p > 2*N) {
        nowx = (timex + p)%(2*N);
    }
    else if (timex + p > N) {
        nowx = 2 * N - timex - p;
    }
    else{   nowx = timex + p;
    }
    if (timey + q > 2*M) {
        nowy = (timey + q) % (2*M);
    }
    else if (timey + q > M) {
        nowy = 2 * M - timey - q;
    }
    else {
        nowy = timey + q;
    }


    cout << nowx << " " << nowy << endl;


    return 0;
}



