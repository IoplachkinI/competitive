#include <bits/stdc++.h>

using namespace std;

int main(){
    int cas = 0;
    while (true){
        cas++;
        int m, n;
        cin >> m >> n;
        if (!m && !n) break;    

        int minb = INT32_MAX;
        for (int i = 0; i < m; i++){
            int a;
            cin >> a;
            if (a < minb) minb = a;
        }

        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
        }

        printf("Case %d: ", cas);
        if (m <= n) printf("0\n");
        else printf("%d %d\n", m - n, minb);

        /*vector<int> b(m), s(n), taken(n);
        for (int i = 0; i < m; i++){
            cin >> b[i];
        }
        for (int i = 0; i < n; i++){
            cin >> s[i];
            taken[i] = false;
        }

        for (int i = 0; i < min(m, n); i++){
            for (int j = 1; j < s.size(); j++){
                if (abs(b[i] - s[j - 1]) < abs(b[i] - s[j])) {
                    s.erase(s.begin() + j);
                    break;
                }
            }
        }*/

    }
}