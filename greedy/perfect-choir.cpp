#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int n;
        cin >> n;
        if (cin.eof()) break;
        vector<int> v (n);
        long long sum = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        }

        if (sum % n != 0) {
            cout << "-1\n";
            continue;
        }

        long long diffsum = 0;
        for (int i = 0; i < n; i++){
            diffsum += llabs(v[i] - sum / n);
        }

        cout << diffsum / 2 + 1<< "\n";

    }
}