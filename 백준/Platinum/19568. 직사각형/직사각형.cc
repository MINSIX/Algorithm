#include <bits/stdc++.h>
using namespace std;
int N;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 30; i++) {
        if (i == 15) {
            for (int j = 0; j < 30; j++) {
                if(j<15)
                cout << 1 << " ";
                else if(j>15)
                    cout << 15 * 15 << " ";
                else
                    cout <<0 << " ";
            }
        }else
        {
            if(i<15)
            for (int j = 0; j < 30; j++) {

                if (j == 15)
                    cout << 15 << " ";
                else
                    cout << 0 << " ";
            }
            else {
                for (int j = 0; j < 30; j++) {

                    if (j == 15)
                        cout << 15*15*15 << " ";
                    else
                        cout << 0 << " ";
                }
            }
        }
        
        cout << "\n";
    }

}