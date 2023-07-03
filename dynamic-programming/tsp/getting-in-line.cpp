#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 9;
vector<vector<float>> dist(MAXN, vector<float> (MAXN));
vector<int> curpath(MAXN), bestpath(MAXN);
int curind = 0;
float bestlen;

void calculate(){
    float tmplen = 0.f;
    for (int i = 1; i < n; i++){
        tmplen += dist[curpath[i]][curpath[i-1]];
    }
    if (tmplen < bestlen){
        bestlen = tmplen;
        bestpath = curpath;
    } 
}

void gen(int mask){
    if (mask == (1 << n) - 1){
        calculate();
        return;
    }
    for (int i = 0; i < n; i++){
        if (mask & (1 << i)) continue;
        curpath[curind] = i;
        curind++;
        gen(mask | (1 << i));
        curind--;
    }
}

int main(){
    int _case = 0;
    while (true){
        _case++;
        cin >> n;
        if (!n) break;
        bestlen = numeric_limits<float>::max();

        vector<int> x (n), y(n);
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            dist[i][j] = dist[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) + 16.f;

        gen(0);
        printf("**********************************************************\n");
        printf("Network #%d\n", _case);
        for (int i = 1; i < n; i++){
            int pos1 = bestpath[i-1];
            int pos2 = bestpath[i];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", 
            x[pos1], y[pos1], x[pos2], y[pos2], dist[pos1][pos2]);
        }
        printf("Number of feet of cable required is %.2f.\n", bestlen);
    
    }
}