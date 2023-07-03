#include <bits/stdc++.h>


using namespace std;


bool next(string& str){
    string col;
    bool last = true;
    for (int i = str.size() - 1; i >= 0; i--){
        col += str[i];
        sort(col.begin(), col.end());
        auto it = upper_bound(col.begin(), col.end(), str[i]);
        if (it != col.end()) {
            last = false;
            str[i] = *it;
            col.erase(it);
            for (int j = i + 1; j < str.size(); j++){
                str[j] = col[j - i - 1];
            }
            break;
        }
    }
    return last;
}


int main(){
    string in;
    cin >> in;

    while (in.compare("#") != 0){
        bool last = next(in);
        if (last) cout << "No Successor\n";
        else cout << in << '\n';
        cin >> in;
    }
}