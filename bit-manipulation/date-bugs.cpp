#include <bits/stdc++.h>


using namespace std;


int main(){
    int n, k = 0;
    cin >> n;

    while (n != 0){
        k++;
        cout << "Case #" << k << ":\n"; 
        vector<bitset<10000>> v (n);
        for (int i = 0; i < n; i++){
            int y, a, b;
            cin >> y >> a >> b;
            for (int j = y; j >= a; j -= (b - a)) v[i][j] = true;
            for (int j = y; j < 10000; j += (b - a)) v[i][j] = true;
        }

        bitset<10000> total;
        total.set();
        for (int i = 0; i < n; i++){
            total &= v[i];
        }

        if (!total.any()) cout << "Unknown bugs detected.\n";
        else cout << "The actual year is " << total._Find_first() << ".\n";
        cout << '\n';
        cin >> n;
    }
}