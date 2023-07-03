#include <bits/stdc++.h>

using namespace std;

string printbits(uint n){
    string str = "";
    for (int i = 31; i >= 0; i--){
        if ((n & (1 << i)) != 0)
            str += "1";
        else str += "0";
    }
    return str;
}

int main(){
    while (true){
        uint n, l, u;
        cin >> n >> l >> u;
        if (cin.eof()) break;
        uint m = ~n;

        /*cout << "l: " << printbits(l) << "\n";
        cout << "u: " << printbits(u) << "\n";
        cout << "n: " << printbits(n) << "\n";

        cout << "m: " << printbits(m) << "\n";*/

        bool first = true;
        for (int i = 31; i >= 0; i--){
            bool lon = l & (1 << i);
            bool uon = u & (1 << i);
            if (lon && uon){
                first = false;
                m |= (1 << i);
            }
            else if (!first) break;
        }

        //cout << "m: " << printbits(m) << "\n";

        int biton = 31, bitoff = 31;
        while (!(m >= l && m <= u)){
            if (m < l){
                for (int i = biton; i >= 0; i--){
                    if (u & (1 << i)){
                        biton = i - 1;
                        m |= (1 << i);
                        break;
                    }
                }
            }
            if (m > u) {
                for (int i = bitoff; i >= 0; i--){
                    if (!(u & (1 << i))){
                        bitoff = i - 1;
                        m &= ~(1 << i);
                        break;
                    }
                }
            }
            //cout << "m: " << printbits(m) << " " << m << "\n";
            //getchar();
        }

        cout << m << '\n';

    }
}