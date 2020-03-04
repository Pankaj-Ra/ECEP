#include <bits/stdc++.h>

using namespace std;

int getMagicNumber(string s, int k, int b, int m){
    int len = s.length()-k+1;
    int total = 0;
    for(int i = 0 ;i < len; i++){
        int sum = 0;
        for(int j = k+i-1; j >= (k == min(k,m))?i:k+i-m; j--){
            sum += (s[j]-48)*pow(b,k+i-1-j);
        }
        total += sum%m;
    }
    return total;
}

int main() {
    string s;
    cin >> s;
    int k;
    int b;
    int m;
    cin >> k >> b >> m;
    int result = getMagicNumber(s, k, b, m);
    cout << result << endl;
    return 0;
}

