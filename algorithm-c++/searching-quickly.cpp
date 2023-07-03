#include <bits/stdc++.h>


using namespace std;


int main(){
    set<string> ignore;
    string in;
    cin >> in;

    while (in.compare("::")){
        for (int i = 0; i < in.size(); i++) in[i] = tolower(in[i]);
        ignore.insert(in);
        cin >> in;
    }

    in.clear();
    cin.ignore(100, '\n');
    getline(cin, in);
    vector<pair<string, string>> out;
    while (!cin.eof() && in.compare("0") != 0){
        for (int i = 0; i < in.size(); i++){
            in[i] = tolower(in[i]);
        }

        int start = 0, end = 0;
        while (end != string::npos){
            end = in.find(' ', start);
            string word;
            if (end == string::npos) word = in.substr(start);
            else word = in.substr(start, end - start);
            if (ignore.count(word) == 0) {
                string _in = in;
                for (int i = start; (end == string::npos && i < _in.size()) || i < end; i++) 
                    _in[i] = toupper(_in[i]);
                out.push_back({word, _in});
            }
            start = end;
            while (start != string::npos && in[start] == ' ') start++;
        }   

        getline (cin, in);
    }

    sort(out.begin(), out.end(), [](pair<string, string> el1, const pair<string, string> el2){
        return el1.first.compare(el2.first) < 0;
    });

    for (const auto& el : out){
        cout << el.second << '\n';
    }

}