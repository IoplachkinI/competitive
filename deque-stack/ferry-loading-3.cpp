#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    cin >> k;

    while (k--){
        int n, t, m, cur = 0;
        queue<int> left, right;
        vector<int> times (m);
        cin >> n >> t >> m;
        bool onLeft = true;
        
        for (int i = 0; i < m; i++){
            int arr;
            string str;
            cin >> arr;
            cin >> str;
            if (!str.compare("left")) left.push(arr);
            else right.push(arr);

            if ((left.empty() || left.front() > cur)
                && (right.empty() || right.front() > cur)) {
                    if (left.empty()) 
                }
            else if ((onLeft && (left.empty() || left.front() > cur) 
                && (!right.empty() && right.front() <= cur))
                ||   
                )
                {
                    onLeft = !onLeft;
                    cur += t;
                }
            else if ()
        }
    }
}