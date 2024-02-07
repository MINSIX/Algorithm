#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int N, K, M;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 

    int a, b, c;
    cin >> a >> b >> c ;
       


    while (a != 0 && b != 0 && c != 0) {


        if (pow(a, 2) + pow(b, 2) == pow(c, 2)|| pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(c, 2) + pow(b, 2) == pow(a, 2))
            cout << "right" << endl;
        else
            cout << "wrong" << endl;


        cin >> a >> b >> c;

    }



    return 0;
}



