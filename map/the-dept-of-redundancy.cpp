#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    map <int, int> cnt;
    vector<int> order;

    while (!cin.eof()){
        cnt[n]++;
        if (cnt[n] == 1) order.push_back(n);
        cin >> n;
    }

    for (const auto& el : order){
        cout << el << ' ' << cnt[el] << '\n';
    }

}