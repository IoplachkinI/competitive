#include <bits/stdc++.h>

using namespace std;

//code very bad
int main(){
    while (true){
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        int cnt = f;
        int space = 0;

        if (a + b + c + d + e + f == 0) break;

        cnt += e;
        space = e * 11;
        if (space > a) a = 0;
        else a -= space;

        cnt += d;  
        space = 20 * d;
        if (space > 4 * b) {
            space -= 4 * b;
            b = 0;
        }
        else {
            b -= space / 4;
            space = 0;
        }
        if (space > a) a = 0;
        else a -= space;

        if (c % 4 == 0) cnt += c / 4;
        else cnt += c / 4 + 1;

        if (c % 4 == 3){
            space = 9;
            if (b > 0) {
                b--;
                space -= 4;
            }
            if (a > space){
                a -= space;
            }
            else a = 0;
        }       
        else if (c % 4 == 2){
            space = 18;
            if (b > 2){
                b -= 3;
                space -= 12;
            }
            else {
                space -= b * 4;
                b = 0;
            }
            if (a > space){
                a -= space;
            }
            else a = 0;
        }
        else if (c % 4 == 1){
            space = 27;
            if (b > 4){
                b -= 5;
                space -= 20;
            }
            else {
                space -= b * 4;
                b = 0;
            }
            if (a > space){
                a -= space;
            }
            else a = 0;
        } 

        if (b % 9 == 0) cnt += b / 9;
        else cnt += b / 9 + 1;

        if (!b || b % 9 == 0) space = 0;
        else space = 36 - b % 9 * 4;
        if (a > space) a -= space;
        else a = 0;

        if (a % 36 == 0) cnt += a / 36;
        else cnt += a / 36 + 1;

        cout << cnt << '\n';
    }
}