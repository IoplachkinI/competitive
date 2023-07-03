#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int n;
        long long sum = 0;
        cin >> n;
        if (cin.eof()) break;

        vector<int> a (n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<pair<int, int>> c (n);
        for (int i = 0; i < n; i++)
            c[i] = {a[i], b[i]};

        int curind = 0;
        for (int i = 0; i < n; i++){
            if (c[i].first < c[i].second) {
                iter_swap(c.begin() + i, c.begin() + curind);
                curind++;
            }
        }

        sort(c.begin(), c.begin() + curind);

        sort(c.begin() + curind, c.end(), [](pair<int, int> i, pair<int, int> j){
            return i.second > j.second;
        });

        int over = 0;
        for (int i = 0; i < n - 1; i++){
            if (c[i].second > c[i + 1].first)
                c[i + 1].second += c[i].second - c[i + 1].first;
        }
        over += c[n - 1].second;

        cout << sum + over << '\n';

    }
}