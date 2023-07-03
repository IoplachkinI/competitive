#include <bits/stdc++.h>

using namespace std;

int countMatching (string a, string b, int offset){
    if (offset > (int)b.size() - 1 || offset < -(int)a.size() + 1) {
        throw logic_error("WRONG OFFSET");
    }

    int cnt = 0;
    if (offset > 0)
        for (int i = offset; i < min((int)b.size(), (int)a.size() + offset); i++)
            cnt += a[i - offset] == b[i];

    else {
        offset = -offset;
        for (int i = offset; i < min ((int)b.size() + offset, (int)a.size()); i++)
            cnt += a[i] == b[i - offset];
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<string> v (n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        int max = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                string a = v[i]; string b = v[j];
                int curmax = 0;
                for (int offset = -(int)a.size() + 1; offset < (int) b.size(); offset++){
                    int cur = countMatching(a, b, offset);
                    if (cur > curmax) curmax = cur;
                }
                if (curmax > max) max = curmax;
            }
        }
        cout << max << '\n';
    }
}