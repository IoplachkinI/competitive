#include <bits/stdc++.h>

using namespace std;

int main(){
    while (true){
        int n;
        cin >> n;
        if (!n) break;

        long long maxsum = LONG_LONG_MIN, sum = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            sum += a;
            if (sum > maxsum) maxsum = sum;
            if (sum < 0) sum = 0;
        }
        if (maxsum > 0) printf("The maximum winning streak is %lld.\n", maxsum);
        else printf("Losing streak.\n");
    }
}