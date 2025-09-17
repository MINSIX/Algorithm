#include <iostream>
using namespace std;

int main() {
    int n=0,check=0,m; 
    string str;
    cin >> str; 
    for (int i=0;i<12;i++){
        if (i%2==0){
            if (str[i]=='*'){
                check=1;
                continue;
            }
            n+=str[i]-'0';
        }
        else {
            if (str[i]=='*'){
                check=3;
                continue;
            }
            n+=(str[i]-'0')*3;
        }
    }
    m=str[12]-'0';

    n=(n+m)%10;

    int x;
    if(check==1) x=(10-n)%10;
    else x=(7*(10-n))%10;

    cout << x;
}
