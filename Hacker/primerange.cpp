#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

void prime_numbers(vector<bool> &prime, int max){

    for(ull p = 2; p <= max;p++){
        if(prime[p]){
            for(ull i = p*p;i <=max;i += p){
                prime[i] = false;
            }
        }
    }
}

int maxDifference(vector<bool> prime,int startVal, int endVal) {
    if(startVal == endVal)
        return 0;

    ull prime_1 = 0;
    ull prime_2 = 0;
    for(ull p = startVal; p <= endVal;p++){
        if(prime[p]){
            prime_1 = (!prime_1 && p >= startVal)?p:prime_1;
            break;
        }
    }
    if(!prime_1)
        return 0;
    for(ull p = endVal; p >= startVal;p--){
        if(prime[p]){
            prime_2 = (prime_1 && p > prime_2)?p:prime_2;
            break;
        }
    }

    if(prime_1 && prime_2)
        return (prime_2 - prime_1);
    return 0;
}

int main() {
    int q;
    cin >> q;
    vector<pair<int,int> > range;
    int max = 0;
    int startVal;
    int endVal;
    for(int a0 = 0; a0 < q; a0++){

        cin >> startVal >> endVal;
        range.push_back(make_pair(startVal,endVal));
        max = (max < endVal)?endVal:max;
    }
    vector<bool> prime(max+1,true);
    prime_numbers(prime, max);
    for(int i = 0; i < q;i++){
        int result = maxDifference(prime,abs(range[i].first),abs(range[i].second));
        cout << result << endl;
    }
    return 0;
}
