#include<bits/stdc++.h>
using namespace std;

int main() {
    int l1x1, l1y1, l1x2, l1y2, l2x1, l2y1, l2x2, l2y2;

    cin >> l1x1 >> l1y1 >> l1x2 >> l1y2;
    cin >> l2x1 >> l2y1 >> l2x2 >> l2y2;

    if (max(l1y1, l1y2) < min(l2y1, l2y2) || max(l2y1, l2y2) < min(l1y1, l1y2)) {
        cout << 0;
        return 0;
    }
    if (max(l1x1, l1x2) < min(l2x1, l2x2) || max(l2x1, l2x2) < min(l1x1, l1x2)) {
        cout << 0;
        return 0;
    }

    long long o1 = (long long)(l1y2 - l1y1) * (long long)(l2x1 - l1x2) - (long long)(l1x2 - l1x1) * (long long)(l2y1 - l1y2);
    long long o2 = (long long)(l1y2 - l1y1) * (long long)(l2x2 - l1x2) - (long long)(l1x2 - l1x1) * (long long)(l2y2 - l1y2);
    long long o3 = (long long)(l2y2 - l2y1) * (long long)(l1x1 - l2x2) - (long long)(l2x2 - l2x1) * (long long)(l1y1 - l2y2);
    long long  o4 = (long long)(l2y2 - l2y1) * (long long)(l1x2 - l2x2) - (long long)(l2x2 - l2x1) * (long long)(l1y2 - l2y2);

  
    if ((o1 > 0 && o2 < 0 || o1 < 0 && o2 > 0) && (o3 > 0 && o4 < 0 || o3 < 0 && o4 > 0)) {
        cout << 1;
        return 0;
    }


    cout << 0;

    return 0;
}
