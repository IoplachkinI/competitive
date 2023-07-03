#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    int cas = 0;
    while (t--){
        cas++;
        int n, m;
        cin >> n >> m;
        vector<int> a, b;
        a.assign(n, 1);
        b.assign(n, 0);

        vector<set<int>> v (n);
        for (int i = 0; i < m; i++){
            int n1, n2;
            cin >> n1 >> n2;
            n1--; n2--;
            v[n1].insert(n2);
            v[n2].insert(n1);
        }

        vector<set<int>> va = v, vb(n);

        bool good = true;
        int moves = 0;
        while (true){
            int pairsa = 0, pairsb = 0;
            for (int i = 0; i < n; i++){
                pairsa += va[i].size();
                pairsb += vb[i].size();
            }

            pairsa /= 2;
            pairsb /= 2;

            if (pairsa + pairsb <= m / 2) break;

            if (pairsb > m / 2){
                good = false;
                break;
            }

            moves++;
            int most = 0;
            for (int i = 0; i < n; i++)
                if (va[i].size() > va[most].size())
                    most = i;
            a[most] = 0;
            b[most] = 1;
            va[most].clear();
            for (int i = 0; i < n; i++)
                va[i].erase(most);
            for (const auto& el: v[most]){
                if (b[el]){
                    vb[most].insert(el);
                    vb[el].insert(most);
                }
            }
        }

        printf("Case #%d: ", cas);
        if (!good) printf("Impossible.\n\n");
        else {
            printf("%d\n", moves);
            bool first = true;
            for (int i = 0; i < n; i++){
                if (b[i]){
                    if (first)
                        first = false;
                    else printf(" ");
                    printf("%d", i + 1);
                }
            }
            printf("\n");
        }


    }
}