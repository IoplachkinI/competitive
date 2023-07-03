#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (!cin.eof()){
        vector<int> v (n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        int m;
        cin >> m;

        int price = -1;
        for (int i = 0; i < n; i++){
            if (v[i] > m / 2) break;
            if (binary_search(v.begin(), v.end(), m - v[i])) price = v[i];
        }

        printf ("Peter should buy books whose prices are %d and %d.\n\n", price, m - price);

        cin >> n;
    }
}