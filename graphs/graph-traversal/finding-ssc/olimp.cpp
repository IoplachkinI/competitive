#include <bits/stdc++.h>


using namespace std;


void p1(){
    for (int x = 1; x <= 5; x++){
        for (int y = 0; y < 17; y++){
            printf("x:%d, y:%d = [%d, %d]\n", x, y+1, 3*x*17+x*y+1, 3*x*17+x*y+x);
        }
    }
}


void p2(){
    vector<int> v;
    int a = 69, b = 39;
    for (int j = 0; j < 2; j++){
        for (int i = a; i >= b; i--) v.push_back(i);
        for (int i = 1; i < b; i++) v.push_back(i);
    }
    for (const auto& a : v) cout << a <<' ';

    for (int i = 0; i < v.size(); i++){
        int cnt = 0;
        bool good1 = true, good2 = true;
        for (int j = i+1; j < v.size();j++){
            if (v[i] < v[j] && cnt < 40) good1 = false;
            if (v[i] > v[j] && cnt < 30) good2 = false;
            cnt++;
        }
        if (!(good1 || good2)) {
            printf("Shit on %d\n", v[i]);
            break;
        }
    }
    printf("Ok");

}


int main(){
    p2();
}
