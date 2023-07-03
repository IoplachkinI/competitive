#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> maxv;
int maxsum, n, t;

void rec(int pos, int sum, vector<int> tmp){

    if (sum > maxsum && sum <= n) {
        maxsum = sum;
        maxv = tmp;
    }

    for(int i = pos + 1; i < t && sum <= n; i++){
        tmp[0]++;
        tmp[tmp[0]] = v[i];
        rec(i, sum + v[i], tmp);
        tmp[tmp[0]] = 0;
        tmp[0]--;
    }
        
}  

int main(){
    while (true){
        n = 0;
        cin >> n;
        if (!n) break;

        cin >> t;
        maxsum = 0;
        v.assign(t, 0);
        maxv.assign(t + 1, 0);
        for (int i = 0; i < t; i++){
            cin >> v[i];
        }
        
        vector<int> tmp;
        tmp.assign(t + 1, 0);

        for (int i = 0; i < t; i++){
            tmp[0] = 1;
            tmp[1] = v[i];
            rec(i, v[i], tmp);
        }

        for (int i = 1; i <= maxv[0]; i++){
            cout << maxv[i] << " ";
        }

        cout << "sum:" << maxsum << "\n";
    }
}