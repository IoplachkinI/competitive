#include <bits/stdc++.h>


using namespace std;

#define o cout

int main(){
    //ofstream o;
    //o.open("out.txt");
    int n;
    cin >> n;
    cin.ignore(100, '\n');
    while (n){
        map <set<int>, int> m;
        for (int i = 0; i < n; i++){
            string in;
            getline (cin, in);
            size_t start = 0, end = 0;
            set <int> s;
            while (in.find(' ', end + 1) != string::npos){
                end = in.find(' ', end + 1);
                s.insert(stoi(in.substr(start, end)));
                start = end + 1;
            }
            s.insert(stoi(in.substr(start)));
            m[s]++;
        }

        uint max = 0, cnt = 0;
        for (const auto& el : m){
            if (el.second > max){
                max = el.second;
                cnt = 0;
            }
            if (el.second == max) cnt++;
        }

        o << (max * cnt) << '\n';
        cin >> n;
        cin.ignore(100, '\n');
    }
    //o.close();
}