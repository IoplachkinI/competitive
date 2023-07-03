#include <bits/stdc++.h>

using namespace std;

int main(){
    int r;
    cin >> r;
    for (int i = 1; i <= r; i++){
        int b;
        cin >> b;
        int maxstart = 0, maxend = 0, maxlen = 0;
        int start = 0, end = 0, len = 0;
        long long sum = 0, maxsum = LONG_LONG_MIN;

        for (int j = 0; j < b - 1; j++){
            end++;
            len++;
            int num;
            cin >> num;
            sum += num;
            if (sum < 0){
                sum = 0;
                len = 0;
                start = j + 1;
                end = j + 1;
            }
            else if (sum > maxsum || (sum == maxsum && len > maxlen)){
                maxstart = start;
                maxend = end;
                maxlen = len;
                maxsum = sum;
            }
        }

        if (maxsum < 0) printf("Route %d has no nice parts\n", i);
        else printf("The nicest part of route %d is between stops %d and %d\n", i, maxstart+1, maxend+1);
        
    }
}