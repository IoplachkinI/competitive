#include <bits/stdc++.h>


using namespace std;


#define SWAP(n) (((n & 0xff) << 24) | (((n >> 8) & 0xff) << 16) | (((n >> 16) & 0xff) << 8) | (((n >> 24) & 0xff)))

//Dad's cool solution :)
int main(){
    int n;
    cin >> n;

    while (!cin.eof()){
        int out = ((n & 0xff) << 24) | 
        (((n >> 8) & 0xff) << 16) | 
        (((n >> 16) & 0xff) << 8) | 
        (((n >> 24) & 0xff));
        printf("%d converts to %d\n", n, out);
        //cout << n << " converts to " << out;
        cin >> n;
    }
}