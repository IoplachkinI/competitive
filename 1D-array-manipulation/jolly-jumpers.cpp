#include <bits/stdc++.h>


using namespace std;


int main(){
    long long n;
    cin >> n;
    while (!cin.eof()){
        long long n1, n2;
        bool jolly = true;
        bitset<3010> flags;
        for (long long i = 0; i < flags.size(); i++){
            flags[i] = false;
        }

        cin >> n2;
        for (long long i = 1; i < n; i++){
            n1 = n2;
            cin >> n2;
            
            if (abs(n1 - n2) == 0 || abs(n1 - n2) > n - 1 || flags[abs(n1 - n2)]) {
                jolly = false;
            }
            flags[abs(n1 - n2)] = true;
        }

        if (jolly || n == 1) cout << "Jolly\n";
        else cout << "Not jolly\n";
        cin >> n;
    }
}