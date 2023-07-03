#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(100, '\n');
    while (n--){
        string str;
        getline(cin, str);
        map<char, int> chars;
        int edges = 0, vert = 0;
        while (str.find("*") == string::npos){
            chars[str[1]]++;
            chars[str[3]]++;
            edges++;
            getline(cin, str);
        }
        getline(cin, str);
        vert = str.size() / 2 + 1;
        int acorns = 0, trees = 0;
        for (int i = 0; i < str.length(); i += 2){
            if (!chars.count(str[i])) acorns++;
        }
        trees = vert - edges - acorns;

        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
        
    }
}