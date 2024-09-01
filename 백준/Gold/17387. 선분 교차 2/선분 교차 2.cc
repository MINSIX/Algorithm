#include<bits/stdc++.h>
using namespace std;

int main() {
    long long l1x1, l1y1, l1x2, l1y2, l2x1, l2y1, l2x2, l2y2;

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

    long long o1 = (l1y2 - l1y1) * (l2x1 - l1x2) - (l1x2 - l1x1) * (l2y1 - l1y2);
    long long o2 = (l1y2 - l1y1) * (l2x2 - l1x2) - (l1x2 - l1x1) * (l2y2 - l1y2);
    long long o3 = (l2y2 - l2y1) * (l1x1 - l2x2) - (l2x2 - l2x1) * (l1y1 - l2y2);
    long long  o4 = (l2y2 - l2y1) * (l1x2 - l2x2) - (l2x2 - l2x1) * (l1y2 - l2y2);

  
    if ((o1 > 0 && o2 < 0 || o1 < 0 && o2 > 0) && (o3 > 0 && o4 < 0 || o3 < 0 && o4 > 0)) {
        cout << 1;
        return 0;
    }

    if (o1 == 0 && l2x1 >= min(l1x1, l1x2) && l2x1 <= max(l1x1, l1x2) &&
        l2y1 >= min(l1y1, l1y2) && l2y1 <= max(l1y1, l1y2)) {
        cout << 1;
        return 0;
    }
    if (o2 == 0 && l2x2 >= min(l1x1, l1x2) && l2x2 <= max(l1x1, l1x2) &&
        l2y2 >= min(l1y1, l1y2) && l2y2 <= max(l1y1, l1y2)) {
        cout << 1;
        return 0;
    }
    if (o3 == 0 && l1x1 >= min(l2x1, l2x2) && l1x1 <= max(l2x1, l2x2) &&
        l1y1 >= min(l2y1, l2y2) && l1y1 <= max(l2y1, l2y2)) {
        cout << 1;
        return 0;
    }
    if (o4 == 0 && l1x2 >= min(l2x1, l2x2) && l1x2 <= max(l2x1, l2x2) &&
        l1y2 >= min(l2y1, l2y2) && l1y2 <= max(l2y1, l2y2)) {
        cout << 1;
        return 0;
    }

    cout << 0;

    return 0;
}
