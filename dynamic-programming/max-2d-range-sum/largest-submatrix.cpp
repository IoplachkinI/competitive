#include <bits/stdc++.h>

using namespace std;

void fillrow(int row, string str, vector<vector<int>> &v){
    for (int i = 0; i < str.size(); i++){
        if (str[i] == '1')
            v[row][i] = 1;
        else 
            v[row][i] = -1000;
    }
}

int main(){
    int t;
    cin >> t;
    cin.ignore(100, '\n');
    cin.ignore(100, '\n');
    while (t--){
        string str;
        getline(cin, str);
        int n = str.size();
        vector<vector<int>> v(n, vector<int>(n));
        fillrow(0, str, v);
        for (int i = 1; i < n; i++){
            getline(cin, str);
            fillrow(i, str, v);
        }


        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                if (i) v[i][j] += v[i-1][j];
                if (j) v[i][j] += v[i][j-1];
                if (i && j) v[i][j] -= v[i-1][j-1];
            }

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << v[i][j] << " ";
            cout << "\n";
        }*/
        
        long long maxarea = 0, maxsum = 0;
        for (int i1 = 0; i1 < n; i1++) for (int j1 = 0; j1 < n; j1++)
            for (int i2 = i1; i2 < n; i2++) for (int j2 = j1; j2 < n; j2++){
                long long cursum = v[i2][j2];
                if (i1) cursum -= v[i1-1][j2];
                if (j1) cursum -= v[i2][j1-1];
                if (i1 && j1) cursum += v[i1-1][j1-1];
                if (cursum > maxsum){
                    maxsum = cursum;
                    maxarea = max(maxarea, (llabs(i2-i1) + 1) * (llabs(j2-j1) + 1));
                }
            }

        cout << maxarea << "\n";
        if (t) cout << "\n";
        cin.ignore(100, '\n');
    }
}