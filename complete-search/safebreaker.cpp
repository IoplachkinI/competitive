#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--){
        int t;
        cin >> t;
        vector<vector<int>> v (t, vector<int> (6));
        for (int i = 0; i < t; i++){
            int k;
            char a, b;
            cin >> k >> ws >> a;
            cin.ignore(1);
            cin >> b;
            v[i][0] = k / 1000;
            v[i][1] = k / 100 % 10;
            v[i][2] = k / 10 % 10;
            v[i][3] = k % 10;
            v[i][4] = a- '0';
            v[i][5] = b - '0';
        }
        int ans = 0;
        int res [4] = {0, 0, 0, 0};
        for (int a = 0; a < 10 && ans < 2; a++)
            for (int b = 0; b < 10 && ans < 2; b++)
                for (int c = 0; c < 10 && ans < 2; c++)
                    for (int d = 0; d < 10 && ans < 2; d++){
                        int cnt = 0;
                        for (const auto& el : v){
                            int cur [4] = {a, b, c, d};
                            int corr = 0, misp = 0;
                                map<int, int> s1;
                            map<int, int> s2;
                            for (int i = 0; i < 4; i++){
                                if(el[i] == cur[i]) corr++;
                                else {
                                    s1[cur[i]]++;
                                    s2[el[i]]++;
                                }
                            }
                            for (const auto& s : s1)
                                misp += (s2[s.first] < s.second) ? s2[s.first] : s.second;

                            if (corr == el[4] && misp == el[5]) {
                                cnt++;
                            }
                        }
                        if (cnt == v.size()) {
                            res[0] = a; res[1] = b; res[2] = c; res[3] = d;
                            ans++;
                        }
                    }
        if (ans == 1) cout << res[0] << res[1] << res[2] << res[3] << '\n';
        else if (ans > 1) cout << "indeterminate\n";
        else cout << "impossible\n";
    }
}