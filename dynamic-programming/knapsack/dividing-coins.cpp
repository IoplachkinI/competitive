#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<vector<int>> memo;

int rec (int id, int rem){
    /*for (const auto& a : memo){
            for (const auto& b : a)
                printf("%4d ", b);
            cout << "\n";
        }
    cout << "\n";*/
    if (id == n || rem == 0) return 0;
    int& ans = memo[id][rem]; // writing to memo and then getting from it is what makes this so much faster
    //without this bit the program takes >3 seconds to run on a provided test case 
    //with it it takes less than 0.1 seconds
    //bruh
    if (ans != -1) return ans;
    if (v[id] > rem) return ans = rec(id+1, rem);
    return ans = max(
        rec(id+1, rem),
        rec(id+1, rem - v[id]) + v[id]
    );
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int maxsum = 0;
        cin >> n;
        v.resize(n);
        
        for (int i = 0; i < n; i++){
            cin >> v[i];
            maxsum += v[i];
        }
        
        memo.resize(n);
        for (int i = 0; i < n; i++)
            memo[i].assign(maxsum+1, -1);

        int out = maxsum - 2 * rec(0, maxsum / 2);
        cout << out << "\n";
        
    }
}