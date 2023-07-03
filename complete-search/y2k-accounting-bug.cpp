#include <bits/stdc++.h>

using namespace std;

long long s, d, maxsum;
vector<long long> v (12);

void rec(long long cur, long long sum, long long total, vector<long long>& v){
    if (cur > 4) {
        if (sum >= 0) return;
        sum -= v[cur - 5];
    }

    if (cur == 12) {
        if (total > maxsum) 
            maxsum = total;
        return;
    }

    v[cur] = s;
    rec(cur + 1, sum + s, total + s, v);
    v[cur] = -d;
    rec(cur + 1, sum - d, total - d, v);
    v[cur] = 0;
}

int main(){
    cin >> s >> d;
    while (!cin.eof()){
        maxsum = LONG_LONG_MIN;
        vector <long long> v;
        v.assign(12, 0);
        rec(0, 0, 0, v);
        if (maxsum > 0) cout << maxsum << "\n";
        else cout << "Deficit\n";
        cin >> s >> d;
    }
}