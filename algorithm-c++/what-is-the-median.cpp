#include <bits/stdc++.h>


using namespace std;


int main(){
    vector<long long> v;
    long long n;
    cin >> n;
    while (!cin.eof()){
        long long out;
        v.push_back(n);
        if(v.size() % 2 == 1) {
            nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
            out = v[v.size() / 2];
        }
        else{
            nth_element(v.begin(), v.begin() + v.size() / 2 - 1, v.end());
            out = v[v.size() / 2 - 1];
            nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
            out += v[v.size() / 2];
            out /= 2;
        }
        cout << out << '\n';
        cin >> n;
    }   
    return 0;
}