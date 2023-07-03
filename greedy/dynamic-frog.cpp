#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int cas = 0;
    cin >> t;
    while (t--){
        cas++;
        int n, d;
        cin >> n >> d;
        vector<int> v;
        v.push_back(0);
        int prev = v[0];
        for (int i = 0; i < n; i++){
            char type, junk;
            int dist;
            cin >> type >> junk >> dist;
            v.push_back(dist - prev);
            if (type == 'B') v.push_back(0);
            prev = dist;
        }
        v.push_back(d - prev);

        int maxdist = 0;
        for (int i = 2; i < v.size(); i += 2){
            int curdist = v[i] + v[i - 1];
            if (curdist > maxdist) maxdist = curdist;
        }

        for (int i = 3; i < v.size(); i += 2){
            int curdist = v[i] + v[i - 1];
            if (curdist > maxdist) maxdist = curdist;
        }

        printf("Case %d: %d\n", cas, maxdist);
    }
}