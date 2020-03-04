#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

long long int simplestSum(int k,long long int a,long long int b) {
    long long int sum = 0;
    long long int i = a;
    for(i; i <= b; i++){
        if(i <= k){
            if(b >= k){
                sum += k - i + 1;
                i = k;
            }
            else{
                sum += b - i + 1;
                i = b;
            }
            continue;
        }
        float i_n = i;
        float k_n = k;
        i_n = (k_n - i_n*(1 - k_n))/k_n;
        long int n = ceil((log(i_n)/(log(k_n))));
        double p = k;
        double x = n;
        p = ((1 - pow(p,x))/(1 - k)) - n;
        p = (p*k)/(k-1);
        long long int temp = n + p;
        long long range = k*(1 - pow(k_n,n))/(1 - k);
        if(range - i){
            if(range >= b){
                temp *= (b - i + 1);
                i = b;
            }
            else{
                temp *= (range - i + 1);
                i = range;
            }
        }
        sum += temp;
    }
    return sum % MOD;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        long long int a;
        long long int b;
        cin >> k >> a >> b;
        long long int result = simplestSum(k, a, b);
        cout << result << endl;
    }
    return 0;
}

