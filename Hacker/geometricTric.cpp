#include <bits/stdc++.h>

using namespace std;

long int geometricTrick(string s){
    long int i, j, k;
    long long int sq;
    long int triplets = 0;
    for(j = 1; j < s.length(); j++){
        if(s[j] == 'b'){
            sq = pow(j+1,2);
            if(sq<=s.length()){
                if(((s[0]=='a')&&(s[sq-1]=='c'))||
                        ((s[sq-1]=='a')&&(s[0]=='c'))){
                    triplets++;
                }
            }
            if(j>2){
                long int max = sq;
                for(long int k = 2; k < max; k++){
                    if(sq%k == 0){
                        max = sq/k;
                        if(max > s.length())continue;
                        if(((s[k-1]=='a')&&(s[sq/k -1]=='c'))||((s[sq/k -1]=='a')&&(s[k-1]=='c'))){
                            triplets++;
                        }
                    }
                }
            }
        }
    }
    return triplets;
}

int main() {
    long int n;
    cin >> n;
    string s;
    cin >> s;
    long int result = geometricTrick(s);
    cout << result << endl;
    return 0;
}

