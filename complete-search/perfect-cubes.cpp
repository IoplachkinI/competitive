#include <bits/stdc++.h>

using namespace std;

int main(){
    for (int a = 6; a <= 200; a++)
        for (int b = 2; b < 200; b++)
            for (int c = b + 1; c < 200; c++)
                if (a * a * a - b * b * b - c * c * c > c * c * c) {
                    for (int d = c + 1; d < 200; d++){
                        if (a * a * a == b * b * b + c * c * c + d * d * d){
                            printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                            break;
                        }
                    }
                }
}