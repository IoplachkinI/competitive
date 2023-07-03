#include <bits/stdc++.h>

using namespace std;

int main(){
    int cas = 0;
    while (true){
        cas++;
        int n;
        long long sum = 0;
        cin >> n;
        if (!n) break;
        vector<vector<int>> v(n, vector<int> (2));
        for (int i = 0; i < n; i++){
            cin >> v[i][0];
            cin >> v[i][1];
            sum += v[i][0];
        }   

        long long sumleft = sum;
        /*int curind = 0;
        for (int i = 0; i < n; i++){
            if (v[i][0] < v[i][1]){
                iter_swap(v.begin() + curind, v.begin() + i);
                curind++;
            }
        }

        sort(v.begin(), v.begin() + curind);
        sort(v.begin() + curind, v.end(), [](vector<int> i, vector<int> j){
            return (i[1] > j[1]);
        });*/

        sort(v.begin(), v.end(), [](vector<int> i, vector<int> j){
            return i[1] > j[1];
        });

        int over = 0;
        for (int i = 0; i < n; i++){
            sumleft -= v[i][0];
            if (v[i][1] - sumleft > over) over = v[i][1] - sumleft;
        }

        printf("Case %d: %lld\n", cas, sum + over);
    }
}