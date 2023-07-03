#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        string str;
        getline(cin, str);
        if (!str.compare("END")) break;
        float n = stof(str);
        float l = 0.0, r = 1.0;
        int cnt = 0;
        bool good = true;
        while (cnt++ < 64 && good){
            float firstthird = (r - l) / 3.0 + l + 0.00001;
            float secondthird = (r - l) / 3.0 * 2.0 + l - 0.00001;
            if (n >= l && n <= firstthird) 
                r = firstthird;
            else if (n <= r && n >= secondthird)
                l = secondthird;
            else good = false;
        }

        if (!good) cout << "NON-MEMBER\n";
        else cout << "MEMBER\n";
    }
}