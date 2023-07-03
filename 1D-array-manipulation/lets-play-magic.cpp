#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    cin >> n;
    while (n != 0){
        vector <string> deck (n);
        int pos = -1;
        for (int i = 0; i < n; i++){
            string card, word;
            cin >> card >> word;

            for (int i = 0; i < word.length(); i++){
                pos++;            
                pos = pos % n;
                if (deck[pos].length() != 0) i--;
            }
            deck[pos] = card;

            // cout << pos << ' ' << card << '\n';   
        }

        cout << deck[0];
        for (int i = 1; i < deck.size(); i++){
            cout << ' ' << deck[i];
        }
        cout << '\n';

        cin >> n;
    }
}