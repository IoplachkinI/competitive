#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    cin >> n;

    while (n){
        bool corrupt = false;
        vector <vector<int>> m (n, vector<int> (n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> m[i][j];
            }
        }

        int c = - 1, r = - 1;

        for (int i = 0; i < n && !corrupt; i++){
            int row = 0, col = 0;;
            for (int j = 0; j < n && !corrupt; j++){
                row += m[i][j];
                col += m[j][i];
            }

            if (row % 2 != 0) {
                if (r != -1) corrupt = true;
                else r = i + 1;
            }
            if (col % 2 != 0) {
                if (c != -1) corrupt = true;
                else c = i + 1;
            }
        }

        if (!corrupt && c == -1 && r == -1) printf("OK\n");
        else if (corrupt) printf("Corrupt\n");
        else printf("Change bit (%d,%d)\n", r, c);


        cin >> n;
    }
}