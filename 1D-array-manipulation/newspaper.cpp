#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long k;
        cin >> k;
        map<char, long long> pay;

        for (long long i = 0; i < k; i++){
            char c; long long p;
            cin >> c >> p;
            pay[c] = p;
            cout << c << ": " << pay[c];
        }

        long long l, money = 0;
        cin >> l;
        cin.ignore(100, '\n');

        for (long long i = 0; i < l; i++){
            string line;
            getline(cin, line);
            for (const auto& c : line){
                if (pay.find(c) != end(pay)) money += pay[c];
            }
        }
        
        char buffer [100];
        sprintf(buffer, "%lld.%02lld$\n", money / (long long) 100, money % (long long) 100);

        cout << buffer;
    }
}