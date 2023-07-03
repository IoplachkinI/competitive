#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    while (m != 1 || n != 1){
        int l [2] {0, 1};
        int r [2] {1, 0};
        int mid [2];
        string str = "";

        while (true){
            mid[0] = l[0] + r[0];
            mid[1] = l[1] + r[1];

            if (mid[0] * n > m * mid[1]){
                r[0] = mid[0];
                r[1] = mid[1];
                str += "L";
            }
            else if (mid[0] * n < m * mid[1]){
                l[0] = mid[0];
                l[1] = mid[1];
                str += "R";
            }
            else break;
        }

        cout << str << '\n';

        cin >> m >> n;
    }
}