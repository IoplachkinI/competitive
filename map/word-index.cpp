#include <bits/stdc++.h>

using namespace std;

int main(){
    int cnt = 1;
    map <string, int> m;

    for (char a = 'a'; a <= 'z'; a++) {
        string str;
        str += a;
        m[str] = cnt;
        cnt++;
    }

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = a + 1; b <= 'z'; b++){
            string str;
            str += a; str += b;
            m[str] = cnt;
            cnt++;
        }
    }

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = a + 1; b <= 'z'; b++){
            for (char c = b + 1; c <= 'z'; c++){
                string str;
                str += a; str += b; str += c;
                m[str] = cnt;
                cnt++;
            }
        }
    }

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = a + 1; b <= 'z'; b++){
            for (char c = b + 1; c <= 'z'; c++){
                for (char d = c + 1; d <= 'z'; d++){
                    string str;
                    str += a; str += b; str += c; str += d;
                    m[str] = cnt;
                    cnt++;
                }
            }
        }
    }

    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = a + 1; b <= 'z'; b++){
            for (char c = b + 1; c <= 'z'; c++){
                for (char d = c + 1; d <= 'z'; d++){
                    for (char e = d + 1; e <= 'z'; e++){
                        string str;
                        str += a; str += b; str += c; str += d; str += e;
                        m[str] = cnt;
                        cnt++;
                    }
                }
            }
        }
    }

    string str;
    cin >> str;

    while (!cin.eof()){
        if (!m.count(str)) cout << "0\n";
        else cout << m.at(str) << '\n';
        cin >> str; 
    }
}