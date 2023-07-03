#include <bits/stdc++.h>

using namespace std;

vector<int> board (8);
vector<vector<int>> pre;

void gen(int cur){
    vector<int> a = board;
    if (cur == 8) pre.push_back(board);
    for (int i = 0; i < 8; i++){
        bool good = true;
        for (int j = 0; j < cur && good; j++){
            if (j == cur) continue;
            if (board[j] == i || abs(j - cur) == abs(board[j] - i)) good = false;
        }
        if (!good) continue;
        board[cur] = i;
        a = board;
        gen(cur + 1);
    }
}

int main(){
    vector<int> col(8);
    gen(0);
    /*for (const auto& a : pre){
        for (const auto& b : a){
            cout << b << ' ';
        }
        cout << '\n';
    }*/
    int cnt = 0;
    while (!cin.eof()){
        cnt++;
        
        for (int i = 0; i < 8; i++){
            cin >> col[i];
            col[i]--;
        }

        int min = INT32_MAX;

        for (const auto& el : pre){
            int sum = 0;
            for (int i = 0; i < 8; i++)
                if (el[i] != col[i]) sum++;

            if (sum < min) min = sum;
        }

        printf("Case %d: %d\n", cnt, min);

    }
}