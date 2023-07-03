#include <bits/stdc++.h>

using namespace std;

#define o cout

int main(){
    int n, m;
    cin >> n >> m;
    while (m){
        unordered_map<int, int> um;

        for (int i = 0; i < n + m; i++){
            int k;
            cin >> k;
            um[k]++;
        }

        int cnt = 0;
        for (const auto& el : um){
            if (el.second > 1) cnt++;
        }

        o << cnt << '\n'; 
        cin >> n >> m;
    }
}