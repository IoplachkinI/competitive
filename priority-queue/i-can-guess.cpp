#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (!cin.eof()){
        bool _s = true, _q = true, _pq = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int, vector<int>> pq;
        while (n--){
            int type, x;
            cin >> type >> x;
            if (type == 1) {
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else {
                if (s.empty() || s.top() != x) _s = false;
                if (q.empty() || q.front() != x) _q = false;
                if (pq.empty() || pq.top() != x) _pq = false;
                if (!s.empty()) s.pop(); 
                if (!q.empty()) q.pop(); 
                if (!pq.empty()) pq.pop();
            }
        }
        if (_s + _q + _pq > 1) cout << "not sure\n";
        else if (_s) cout << "stack\n";
        else if (_q) cout << "queue\n";
        else if (_pq) cout << "priority queue\n";
        else cout << "impossible\n";
        cin >> n;
    }
}