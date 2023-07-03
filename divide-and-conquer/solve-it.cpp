#include <bits/stdc++.h>

#define e 2.718281828459045
using namespace std;
typedef long double ld;

int main(){
    ld p, q, r, s, t, u;
    cin >> p >> q >> r >> s >> t >> u;
    while (!cin.eof()){
        ld left = 0.0, right = 1.0;
        ld x = 0.0, res = 1.0;
        ld a = p * powl(e, -x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
        x = 1.0;
        ld b = p * powl(e, -x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;

        if (a * b > 0.0) printf("No solution\n");
        else{
            while (fabsl(res) > 0.0000001){
                x = (left + right) / 2.0;
                res = p * powl(e, -x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
                if (res > 0) left = x;
                else right = x;   
            }

            printf("%.4Lf\n", x);
        }

        cin >> p >> q >> r >> s >> t >> u;
    }
}