#include <bits/stdc++.h>

using namespace std;

int main(){
    int c;
    cin >> c;
    while (c--){
        int n;
        cin >> n;
        int min = INT32_MAX;
        for (int a = 1; a <= n; a++){
            for (int b = a; b <= sqrt(n / a); b++){
                for (int c = b; c <= n / a / b; c++){
                    int area = (a * b + a * c + b * c) * 2;
                    if (a * b * c == n && area < min) min = area;
                }
            }
        }
        cout << min << '\n';
    }
}