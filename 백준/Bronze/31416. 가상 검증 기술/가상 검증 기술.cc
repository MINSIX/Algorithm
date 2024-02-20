#include<bits/stdc++.h>

using namespace std;
int q;

int ta, tb, va, vb;


int cal() {
    int sum = 0;
    int timea = 0, timeb = 0;
    if (ta <= tb && va < vb)
        return tb * vb;

    if (ta == tb && va == vb)
        return ta * va;

    if (ta == tb && va > vb) {
        if ((va + vb) % 2 == 0)
            return ta * (va + vb) / 2;
        return ta * (va + 1 + vb) / 2;
    }
    timeb = tb * vb;
    timea = ta * (timeb / ta);
    va -= timeb / ta;

    while (va > 0) {
        va -= 1;
        if (timea > timeb) {
            timeb += ta;

        }
        else
            timea += ta;
    }

    sum = max(timea, timeb);


    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> ta >> tb >> va >> vb;
        cout << cal() << endl;

    }
}