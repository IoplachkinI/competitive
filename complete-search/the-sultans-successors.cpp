#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v (8, vector<int>(8));
vector<int> rc (8);
int maxsum;

void rec(int cur, int sum){
    if (cur == 8 && sum > maxsum){
        maxsum = sum; 
        return;
    }
    for (int i = 0; i < 8; i++){
        bool good = true;
        for (int j = 0; j < cur && good; j++){
            if (i == rc[j] || abs(i - rc[j]) == abs(cur - j)) good = false;
        }
        if (good) {
            rc[cur] = i;
            rec(cur + 1, sum + v[cur][i]);
            rc[cur] = -1;
        }
    }
}

int main(){
    rc.assign(8, -1);
    int k;
    cin >> k;
    while (k--){
        maxsum = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> v[i][j];
        rec(0, 0);
        printf("%5d\n", maxsum);

    }
}