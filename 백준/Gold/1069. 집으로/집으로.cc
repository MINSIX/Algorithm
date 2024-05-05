#include<bits/stdc++.h>
using namespace std;
int X, Y, D, T;

const double INF = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //walk 1 =>1
    //jump T => D


    //직빵으로 뛰기
    //이등변 삼각형으로 뛰기 T/M이 바로뛰는거보다 가까운경우

    cin >> X >> Y >> D >> T;


    double check = sqrt(pow(X, 2) + pow(Y, 2));    double cnt =check;
    double temp = 0;
    if (check == D)
        cnt = min(cnt, (double)T);
    else if (check <= 2 * D)
    {
        temp = T * 2;
        cnt = min(cnt, temp);
    }
    else {
        cnt = min(cnt, check);
    }
    temp = 0;
    double check2 = check;
    while (check2 > 0) {
        check2 -= D;
        temp += T;

    }
    temp += abs(check2);
    cnt = min(cnt, temp);

    temp = 0;
    check2 = check;
    while (check2 > 0) {
        check2 -= D;
        temp += T;
        if (check2 <= 2 * D && check2 > 2 * T) {
            temp += T * 2;
            cnt = min(cnt, temp);
            temp -= T * 2;
        }
    }
    temp -= T;
    check2 += D;
    temp += check2;
    cnt = min(cnt, temp);


    printf("%.10lf", cnt);









}
