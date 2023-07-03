#include <bits/stdc++.h>

using namespace std;

int main(){
    double _s, _e;
    cin >> _s >> _e;
    vector<vector<long double>> v;
    long long s = round(_s * 100.0), e = round(_e * 100.0);
    for (long long a = 1; a <= e / 2 + 1; a++){
        for (long long b = (10000 / a + 1 > a) ? 10000 / a + 1 : a; b <= e / 2 + 1; b++){
            if (10000 * (a + b) % (a * b - 10000) != 0) continue;
            long long c = 10000 * (a + b) / (a * b - 10000);
            if (c < b || c >= 26000) continue;
            if (a + b + c >= s && a + b + c <= e) {
                long double a1 = a / 100.0;
                long double b1 = b / 100.0;
                long double c1 = c / 100.0;
                v.push_back({a1 + b1 + c1, a1, b1, c1});
                //printf("{%.2Lf, {%.2Lf, %.2Lf, %.2Lf}}\n", a1 + b1 + c1, a1, b1, c1);
                //printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n", n1, a1, b1, c1, a1, b1, c1);
            }
        }
    }
    sort(v.begin(), v.end(), [](vector<long double> v1, vector<long double> v2){
        if (fabsl(v1[0] - v2[0]) > 0.001) return v1[0] < v2[0];
        else if (fabsl(v1[1] - v2[1]) > 0.001) return v1[1] < v2[1];
        else return v1[2] < v2[2];
    });
    for (int i = 0; i < v.size(); i++){
        long double a = v[i][1];
        long double b = v[i][2];
        long double c = v[i][3];
        long double sum = a + b + c;

        printf("%.2Lf = %.2Lf + %.2Lf + %.2Lf = %.2Lf * %.2Lf * %.2Lf\n", sum, a, b, c, a, b, c);
    }
    return 0;
}