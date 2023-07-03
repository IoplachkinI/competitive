#include <bits/stdc++.h>

using namespace std;

//left, top - inclusive, right, bottom - non-inclusive
int determine(int left, int right, int top, int bottom, vector<vector<int>>& v){
    bool white = true, black = true;
    for (int i = top; i < bottom; i++){
        for (int j = left; j < right; j++){
            if (v[i][j]) black = false;
            else white = false;
        }
    }

    if (white) return 1;
    if (black) return 0;
    return -1;

}

void fillrec(int color, int left, int right, int top, int bottom, vector<vector<int>>&v){
    for (int i = top; i < bottom; i++){
        for (int j = left; j < right; j++){
            v[i][j] = color;
        }
    }
}

string out, in;
int charcnt;

void recb(int left, int right, int top, int bottom, vector<vector<int>>& v){
    if (charcnt % 50 == 0 && charcnt != 0) out += '\n';
    charcnt++;
    int val = determine(left, right, top, bottom, v);
    if (val == 1) out += "1";
    else if (val == 0) out += "0";
    else {
        out += "D";
        int vdivider = round((right + left) / 2.0);
        int hdivider = round((top + bottom) / 2.0);
        recb(left, vdivider, top, hdivider, v);
        if (right - left > 1)recb(vdivider, right, top, hdivider, v);
        if (bottom - top > 1)recb(left, vdivider, hdivider, bottom, v);
        if (right - left > 1 && bottom - top > 1)recb(vdivider, right, hdivider, bottom, v);
    }
}

int pos;

void recd(int left, int right, int top, int bottom, vector<vector<int>>& v){
    if (in[pos] == '1') fillrec(1, left, right, top, bottom, v);
    else if (in[pos] == '0') fillrec(0, left, right, top, bottom, v);
    else {
        int vdivider = round((right + left) / 2.0);
        int hdivider = round((top + bottom) / 2.0);
        pos++;
        recd(left, vdivider, top, hdivider, v);
        if (right - left > 1) {
            pos++;
            recd(vdivider, right, top, hdivider, v);
        }
        if (bottom - top > 1){
            pos++;
            recd(left, vdivider, hdivider, bottom, v);
        }
        if (right - left > 1 && bottom - top > 1){
            pos++;
            recd(vdivider, right, hdivider, bottom, v);
        }
    }
}


int main(){
    while (true){
        char mode;
        cin >> mode;
        if (mode == '#') break;

        int r, c;
        cin >> r >> c;

        out = "";
        printf("%c%4d%4d\n",(mode == 'B') ? 'D' : 'B', r, c);
        vector<vector<int>> v (r, vector<int> (c));

        if (mode == 'B'){
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++){
                    char ch;
                    cin >> ch;
                    v[i][j] = (ch - '0');
                }
                    
            charcnt = 0;
            recb(0, c, 0, r, v);
            cout << out << "\n";
        }
        else if (mode == 'D'){
            cin >> in;
            pos = 0;
            recd(0, c, 0, r, v);
            int cnt = 0;
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++){
                    if (cnt % 50 == 0 && cnt != 0) cout << '\n';
                    cout << v[i][j];
                    cnt++;
                }
            cout << '\n';
        }

    }
}