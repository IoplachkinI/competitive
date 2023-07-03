#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int n, m;
        bool good = true;
        cin >> n >> m;
        if (!n && !m) break;
        if (n > m) good = false;

        priority_queue<int, vector<int>, greater<int>> heads, knights;
        for (int i = 0; i < n; i++){
            int head;
            cin >> head;
            heads.push(head);
        }
        for (int i = 0; i < m; i++){
            int knight;
            cin >> knight;
            knights.push(knight);
        }   

        long long pay = 0;
        while (!heads.empty() && good){
            while (!knights.empty() && knights.top() < heads.top())
                knights.pop();
            if (knights.empty()) good = false;
            else {
                pay += knights.top();
                knights.pop();
                heads.pop();
            }
        }

        if (!good) cout << "Loowater is doomed!\n";
        else cout << pay << '\n';
    }
}