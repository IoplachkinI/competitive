#include <bits/stdc++.h>


using namespace std;


int main(){
    long long s, p;
    cin >> s >> p;

    while (s){
        long long x = s / (long long) 2, y = s / (long long) 2, d = 1, cur = 1;
        bool up = true, right = false;

        while (x < s && y < s && x > -1 && y > -1){
            if (up) y += d;
            else y -= d;
            cur += d;

            if (cur >= p) {
                if (up) y -= (cur - p);
                else y += (cur - p);
                break;
            }

            if (right) x += d;
            else x -= d;
            cur += d;

            if (cur >= p) {
                if (right) x -= (cur - p);
                else x += (cur - p);
                break;
            }  

            right = !right;
            up = !up;
            d++;
        }

        printf("Line = %lld, column = %lld.\n", y + (long long)1, x + (long long)1);
        cin >> s >> p;
    }
}