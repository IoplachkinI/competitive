#include <bits/stdc++.h>

using namespace std;

const int MAXN = 52;
int l, n;

vector<vector<int>> memo(MAXN, vector<int> (MAXN));
vector<int> lengths (MAXN);

//left and right are indices of pieces to the left and right of the piece we're currently cutting
int rec(int left, int right){
    if (right - left == 1) return 0;
    int& ans = memo[left][right];
    if (ans != -1) return ans;
    int tmp = INT32_MAX;
    for (int i = left+1; i < right; i++){
        tmp = min(tmp, rec(left, i) + rec(i, right) + lengths[right] - lengths[left]);
    }
    return ans = tmp;
}

int main(){
    while (true){
        cin >> l;
        if (!l) break;

        for (auto& a : memo) for (auto& b : a) b = -1;
        cin >> n;
        lengths[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> lengths[i];
        }
        lengths[n+1] = l;

        int ans = rec(0, n+1);
        printf("The minimum cutting is %d.\n", ans);
    }
}