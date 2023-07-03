#include <bits/stdc++.h>

using namespace std;

#define o cout

int main(){
    int t;
    cin >> t;
    cin.ignore(100, '\n');
    cin.ignore(100, '\n');
    while (t--){
        string str;
        int total = 0;
        map<string, int> count;
        vector<pair<string, double>> percent;
        getline(cin, str);
        while (str.size() > 0){
            count[str]++;
            total++;
            getline(cin, str);
        }

        for (const auto& el : count){
            percent.push_back({el.first, el.second / double(total) * 100});
        }

        for (const auto& el : percent){
            o << el.first;
            char buff[100];
            sprintf(buff, " %.4lf\n", el.second);
            o << buff;
        }
    
        if (t) o << "\n";
    }   
}