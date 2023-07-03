#include <bits/stdc++.h>


using namespace std;


int main(){
    string str;
    int count = 0;

    getline(cin, str);
    while (true){
        //cout << "STRING SIZE: " << str.size();
        printf ("INPUT RECIEVED\n");
        cout << str << '\n';
        if (str.empty()) break;
        int n, i, j;
        scanf("%d ", &n);
        count++;
        printf ("Case %d:", count);

        while (n--){
            scanf("%d %d ", &i, &j);
            cout << i << ' ' << j << '\n';
            bool found = true;
            for (int k = min(i, j); k <= max(i, j); k++){
                if (str[k] != str[min(i, j)]) found = false;
            }

            if (found) printf("Yes\n");
            else printf("No\n");
        }
        getline(cin, str);
    }


}