#include <bits/stdc++.h>

using namespace std;

int main(){
    while (1){
        int f, r;
        cin >> f;
        if (!f) break;
        cin >> r;
        vector<int> front(f), rear(r);
        vector<double> d (f * r);
        for (int i = 0; i < f; i++) cin >> front[i];
        for (int i = 0; i < r; i++) {
            cin >> rear[i];
            for (int j = 0; j < f; j++){
                d[i * f + j] = double(rear[i]) / front[j];
            }
        }

        sort(d.begin(), d.end());
        double maxd = DBL_MIN;
        for (int i = 1; i < f * r; i++)
            if (d[i] / d[i - 1] > maxd) maxd = d[i] / d[i - 1];

        printf("%.2lf\n", maxd);
    }
}