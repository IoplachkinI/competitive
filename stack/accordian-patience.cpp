#include <bits/stdc++.h>


using namespace std;


#define o cout


void check(vector<stack<string>>::iterator begin, vector<stack<string>>::iterator end){
    if (end - begin > 3 && 
    ((*(end - 1)).top()[0] == (*(end - 4)).top()[0] || (*(end - 1)).top()[1] == (*(end - 4)).top()[1])) {
        cout << "moving " << (*(end - 1)).top() << " onto " << (*(end - 4)).top() << '\n';
        while (!(*(end - 1)).empty()){
            (*(end - 4)).push((*(end - 1)).top());
            (*(end - 1)).pop();
        }
        check(begin, end - 3);
        check(begin, end - 4);

    }
    else if (end - begin > 1 && !(*(end - 1)).empty() && !(*(end - 2)).empty() &&
    ((*(end - 1)).top()[0] == (*(end - 2)).top()[0] || (*(end - 1)).top()[1] == (*(end - 2)).top()[1])) {
        cout << "moving " << (*(end - 1)).top() << " onto " << (*(end - 2)).top() << '\n';
        while (!(*(end - 1)).empty()){
            (*(end - 2)).push((*(end - 1)).top());
            (*(end - 1)).pop();
        }
        check(begin, end - 2);
    }
}


int main(){
    string in = " ";
    vector <stack<string>> v;
    while (in.compare("#")){
        cin >> in;
        for (int i = 0; i < 51 && in.compare("#"); i++){
            stack<string> s; s.push(in);
            v.push_back(s);
            check(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++) if (v[i].empty()) v.erase(v.begin() + v.size() - 1);
            cin >> in;
        }
        if (v.size() == 1) o << "1 pile remaining:";
        else o << v.size() << " piles remaining:";

        for (const auto& el : v){
            o << ' ' << el.size();
        }
        o << '\n';

    }
}