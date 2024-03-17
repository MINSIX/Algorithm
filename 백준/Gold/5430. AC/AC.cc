#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;

int T;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for (int tt = 0; tt < T; tt++) {
        bool flag = false;
        int st=0;
        int ed;
        int p;
        string s;
        cin >> s;
        cin >> p;
        string arr;
        cin >> arr;
        int dcount = 0;
        string str = arr.substr(1, arr.size()-2);

        istringstream ss(str);
        string sub1;
        vector<string>v;
        vector<int>real;
        while (getline(ss, sub1, ',')) {
            v.push_back(sub1);
        }
        for (int i = 0; i < v.size(); i++) {
            real.push_back(atoi(v[i].c_str()));
        }
        ed = real.size() - 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') {
                flag = !flag;
            }
            else {
                if (flag) {
                    ed--;
                }
                else {
                    st++;
                }
                dcount++;
            }
        }

        if (dcount > p) {
            cout << "error" << endl;
        }
        else {

            cout << "[";
            while (st <= ed) {
                if (flag) {
                    cout << real[ed];
                    ed--;
                    if (st > ed)
                        break;
                    else
                        cout << ",";
                
                }
                else {
                    cout << real[st];


                    st++;

                    if (st > ed)
                        break;
                    else
                        cout << ",";
                }
                
               
            }
            cout << "]"<<endl;
        }

    }

}