#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  getline(cin,s);
  while(s!="#")
  {
    int cnt=0;
    for(int i=0;i<s.length();i++)
    {
      char c = tolower(s[i]);
      if(s[i]=='i'||s[i]=='e'||s[i]=='a'||s[i]=='o'
      ||s[i]=='I'||s[i]=='E'||s[i]=='O'||s[i]=='U'||s[i]=='A'||s[i]=='u')
      cnt++;
    }
    cout << cnt<<"\n";

    getline(cin,s);
  }
}