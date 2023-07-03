#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n){
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++){
            int k; cin >> k;
            pq.push(k);
        }
        long long cost = 0;
        while (pq.size() > 1){
            int newNum = 0;
            cost += pq.top();
            newNum += pq.top();
            pq.pop();
            cost += pq.top();
            newNum += pq.top();
            pq.pop();
            pq.push(newNum);
        }
        cout << cost << '\n';
        cin >> n;
    }
}