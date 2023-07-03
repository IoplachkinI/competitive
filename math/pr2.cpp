#include <bits/stdc++.h>


using namespace std;


int main(){
    set <vector<int>> s;
    for (int a = 1; a < 50; a+=2)
        for (int b = 1; b < 50; b+=2)
            for (int c = 1; c < 50; c+=2)
                for (int d = 1; d < 50; d+=2){
                    if (a + b + c + d == 50){
                        printf("%d %d %d %d\n", a, b, c, d);
                        s.insert({a, b, c, d});
                    }
                }
    cout << s.size();
}
