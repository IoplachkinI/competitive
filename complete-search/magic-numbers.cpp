#include<bits/stdc++.h>

using namespace std;

long long getLargestNum(int n, int cur, string str){
    if (n == cur) return stoll(str);
    return getLargestNum(n, cur + 1, str + char('0' + (9 - cur)));
}

int main(){
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        int d = 0;
        long long n1 = n;
        while (n1){
            n1 /= 10;
            d++;
        }
        //s1 = i * n, s2 = i, s1 / s2 = n
        for (long long i = 1; i < getLargestNum(11 - d, 0, ""); i++) {
            bool good = true;
            if (i * n > 9876543210) continue;
            long long i1 = i;
            set <long long> s;

            while (i1 && good) {
                if (s.count(i1 % 10)) good = false;
                s.insert(i1 % 10);
                i1 /= 10;
            }

            s.clear();
            i1 = n * i;
            while (i1 && good) {
                if (s.count(i1 % 10)) good = false;
                s.insert(i1 % 10);
                i1 /= 10;
            }

            if (good) printf ("%lld / %lld = %lld\n", n * i, i, n);
        }
        if (t) printf("\n");
    }
}