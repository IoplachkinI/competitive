#include <bits/stdc++.h>

using namespace std;

int main(){
    int cnt = 0;
    while (true){
        cnt++;
        int c, s;
        cin >> c >> s;
        if (cin.eof()) break;

        vector<int> v;
        v.assign(c*2, 0);
        long long sum = 0;
        for (int i = 2*c-s; i < 2*c; i++){
            cin >> v[i];
            sum += v[i];
        }

        double av = (double) sum / c;
        double imb = 0.0;
        sort(v.begin(), v.end());

        printf("Set #%d\n", cnt);
        for (int i = 0; i < c; i++){
            imb += fabsl(av - v[i] - v[2*c-i-1]);
            printf(" %d:", i);
            if (!v[i] && v[2*c-i-1]) printf(" %d", v[2*c-i-1]);
            else if (v[i] && v[2*c-i-1]) printf(" %d %d", v[i], v[2*c-i-1]);
            printf("\n");
        }

        printf("IMBALANCE = %.5lf\n\n", imb);

    }
}