#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        string a, b;
        bool good = true;
        cin >> a >> b;
        if (cin.eof()) break;
        
        if (a.size() > b.size()) good = false;
        int curind = 0;
        for (int i = 0; i < a.size() && good; i++){
            while (curind < b.size()){
                if (a[i] == b[curind]) {
                    curind++;
                    break;
                }
                else if (curind == b.size() - 1) good = false;
                curind++;
            }
        }

        if (!good) cout << "No\n";
        else cout << "Yes\n";
    }
}