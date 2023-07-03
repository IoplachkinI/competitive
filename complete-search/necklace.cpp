#include <bits/stdc++.h>

using namespace std;

int main(){
    //ofstream o;
    //o.open("out.txt");
    long double v0, v;
    cin >> v0 >> v;

    while (v0 > 0.0001){
        long double n = v0 / double(v) / 2.0;
        long long res = 0;
        if ((fabsl(n - floorl(n) - 0.5) > 0.00001 || fabsl(n - 0.5) < 0.0001) && v0 > v) res = (round(n) + 0.00001);
        cout << res << '\n';    
        cin >> v0 >> v;
    }
    //o.close();
}