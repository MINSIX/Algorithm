#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    
    cin >> T;
    while (T--) {
        map<string, int> arr;

        string s;
        cin >> s;
        string p;
        cin >> p;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'B')
            {
                arr["Bobcat"]++;
                arr["Bobcat"]++;

            }
            else if (p[i] == 'C')
                arr["Coyote"]++;
            else if (p[i] == 'M')
            {
                arr["Mountain Lion"]++;
                arr["Mountain Lion"]++;
                arr["Mountain Lion"]++;
                arr["Mountain Lion"]++;
            }
            else if (p[i] == 'W')
            {
                arr["Wolf"]++;
                arr["Wolf"]++;
                arr["Wolf"]++;
             
            }
        }
        int now = arr["Bobcat"];
        string nows = "Bobcat";
        if (now < arr["Coyote"]) {
            now = arr["Coyote"];
            nows = "Coyote";
        }
        else if (now == arr["Coyote"]) {
            nows = "no";
        }

        if (now < arr["Mountain Lion"]) {
            now = arr["Mountain Lion"];
            nows = "Mountain Lion";
        }
        else if (now == arr["Mountain Lion"]) {
            nows = "no";
        }
       
        if (now < arr["Wolf"]) {
            now = arr["Wolf"];
            nows = "Wolf";
        }
        else if (now == arr["Wolf"]) {
            nows = "no";
        }


        cout << s << ": ";
        if (nows != "no") {
            cout << "The " << nows << " is the dominant species" << endl;
        }
        else {
            cout << "There is no dominant species" << endl;
        }



    }




}