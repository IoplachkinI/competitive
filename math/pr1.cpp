#include <bits/stdc++.h>


using namespace std;


int main(){
    int cnt = 0;
    for (int a = 0; a < 100; a++)
        for (int b = 0; b < 100; b++)
            for (int c = 0; c < 100; c++){
                if (15 * a + 16 * b + 17 * c == 180){
                    printf("%d %d %d\n", a, b, c);
                    cnt++;
                } 
            }
    cout << cnt;
}
