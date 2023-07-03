#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v2 {0, 1, 81}, v4 {0, 1, 2025, 3025, 9801},
    v6 {0, 1, 88209, 494209, 998001}, 
    v8 {0, 1, 4941729, 7441984, 24502500, 25502500, 52881984, 60481729, 99980001};
    /*for (int a = 0; a < 10; a++){
        for (int b = 0; b < 10; b++){
            int n1 = a, n2 = b;
            int n = n1 * 10 + n2;
            if (pow(n1 + n2, 2) == n) v2.push_back(n);
        }
    }

    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 10; c++)
                for (int d = 0; d < 10; d++){
                    int n1 = a * 10 + b;
                    int n2 = c * 10 + d;
                    int n = n1 * 100 + n2;
                    if (pow(n1 + n2, 2) == n) v4.push_back(n);
                }

    
    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 10; c++)
                for (int d = 0; d < 10; d++)
                    for (int e = 0; e < 10; e++)
                        for (int f = 0; f < 10; f++){
                            int n1 = a * 100 + b * 10 + c;
                            int n2 = d * 100 + e * 10 + f;
                            int n = n1 * 1000 + n2;
                            if (pow(n1 + n2, 2) == n) v6.push_back(n);
                        }


    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 10; c++)
                for (int d = 0; d < 10; d++)
                    for (int e = 0; e < 10; e++)
                        for (int f = 0; f < 10; f++)
                            for (int g = 0; g < 10; g++)
                                for (int h = 0; h < 10; h++){
                                    int n1 = a * 1000 + b * 100 + c * 10 + d;
                                    int n2 = e * 1000 + f * 100 + g * 10 + h;
                                    int n = n1 * 1000 + n2;
                                    if (pow(n1 + n2, 2) == n) v8.push_back(n);
                                }*/

    /*for (int i = 0; i < 100; i++){
        if (pow(i % 10 + i / 10, 2) == i) {
            v2.push_back(i);
        }
    }

    for (int i = 0; i < 10000; i++){
        int n1 = i % 10 + (i / 10) % 10 * 10;
        int n2 = (i / 100) % 10 + i / 1000 * 10;
        if (pow(n1 + n2, 2) == i){ 
            v4.push_back(i);
        }
    }

    for (int i = 0; i < 1000000; i++){
        int n1 = i % 10 + (i / 10) % 10 * 10 + (i / 100) % 10 * 100;
        int n2 = (i / 1000) % 10 + (i / 10000) % 10 * 10 + (i / 100000) * 100;
        if (pow(n1 + n2, 2) == i) {
            v6.push_back(i);
        }
    }

    for (int i = 0; i < 100000000; i++){
        int n1 = i % 10 + (i / 10) % 10 * 10 + (i / 100) % 10 * 100 + (i / 1000) % 10 * 1000;
        int n2 = (i / 10000) % 10 + (i / 100000) % 10 * 10 + (i / 1000000) % 10 * 100 + (i / 10000000) * 1000;
        if (pow(n1 + n2, 2) == i) v8.push_back(i);
    }*/
    while (!cin.eof()){
        int in = -1; cin >> in;
        if (in == -1) break;
        switch (in){
            case 2:
                for (const auto& el : v2) printf("%02d\n", el);
                break;
            case 4:
                for (const auto& el : v4) printf("%04d\n", el);
                break;
            case 6:
                for (const auto& el : v6) printf("%06d\n", el);
                break;
            case 8:
                for (const auto& el : v8) printf("%08d\n", el);
                break;
        }        
    }
}