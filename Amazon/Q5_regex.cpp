#include <bits/stdc++.h>
#include <regex>
using namespace std;
 
int main () {
 
    string s;
    cin>>s;
    if (regex_match(s, regex("a[a-b]*a|b[a-b]*b|a|b")))
        cout << "matched\n";
    else
        cout<<"not matched\n";
    return 0;
}